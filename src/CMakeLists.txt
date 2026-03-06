cmake_minimum_required(VERSION 3.5...3.31)
project(Shinsei_SinhoMoeme VERSION 0.1.0)

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

option(SHINSEI_USE_SOURCE_LAYOUT
    "Output build artifacts into source-tree layout"
    OFF
)

if(SHINSEI_USE_SOURCE_LAYOUT)
    set(_SHINSEI_DEFAULT_LIB
        "${CMAKE_CURRENT_SOURCE_DIR}/libs"
    )
    set(_SHINSEI_DEFAULT_BIN
        "${CMAKE_CURRENT_SOURCE_DIR}/../release/bin"
    )
else()
    set(_SHINSEI_DEFAULT_LIB
        "${CMAKE_BINARY_DIR}/shinsei/lib"
    )
    set(_SHINSEI_DEFAULT_BIN
        "${CMAKE_BINARY_DIR}/shinsei/bin"
    )
endif()

set(SHINSEI_LIBRARY_DIR
    "${_SHINSEI_DEFAULT_LIB}"
    CACHE PATH "Shinsei library output directory"
)

set(SHINSEI_RUNTIME_DIR
    "${_SHINSEI_DEFAULT_BIN}"
    CACHE PATH "Shinsei runtime output directory"
)

file(MAKE_DIRECTORY
    "${_SHINSEI_DEFAULT_LIB}/shinsei/minimal"
    "${_SHINSEI_DEFAULT_LIB}/shinsei/ex/python3"
    "${_SHINSEI_DEFAULT_BIN}/libs/shinsei/minimal"
    "${_SHINSEI_DEFAULT_BIN}/libs/shinsei/ex/python3"
	"${CMAKE_CURRENT_SOURCE_DIR}/third_party/include/python3"
	"${CMAKE_CURRENT_SOURCE_DIR}/third_party/libs/python3"
)

add_library(_shinsei_build_lib INTERFACE)
add_library(shinsei::build_lib ALIAS _shinsei_build_lib)

add_library(_shinsei_minimal INTERFACE)
add_library(shinsei::minimal ALIAS _shinsei_minimal)

add_library(_shinsei_std INTERFACE)
add_library(shinsei::std ALIAS _shinsei_std)

target_link_libraries(_shinsei_std INTERFACE _shinsei_minimal)

target_compile_definitions(_shinsei_build_lib
    INTERFACE _SHINSEI_BUILD_LIB
)

set(_SHINSEI_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(_SHINSEI_LIBRARY_DIR ${SHINSEI_LIBRARY_DIR})
set(_SHINSEI_BINARY_DIR  ${SHINSEI_RUNTIME_DIR})

target_include_directories(_shinsei_build_lib
    INTERFACE
        $<BUILD_INTERFACE:${_SHINSEI_INCLUDE_DIR}>
        $<INSTALL_INTERFACE:include>
)

option(SHINSEI_BUILD_FORCE_INTERNAL_DEPS "Force use internal third-party libs for shinsei" OFF)
option(SHINSEI_BUILD_MINIMAL "Build minimal shinsei (no OS and EX)" OFF)
option(SHINSEI_BUILD_EX "Build shinsei EX modules" ON)
option(SHINSEI_BUILD_EX_PYTHON3 "Enable Python 3 module for shinsei EX" ON)
option(SHINSEI_BUILD_EX_SQLITE "Enable SQLite module for shinsei EX" ON)
option(SHINSEI_BUILD_EX_POSTGRESQL "Enable PostgreSQL module for shinsei EX" ON)

if(SHINSEI_BUILD_MINIMAL)
	set(SHINSEI_BUILD_EX OFF CACHE BOOL "" FORCE)
	target_compile_definitions(_shinsei_build_lib
		INTERFACE _SHINSEI_BUILD_MINIMAL
	)
	message(STATUS "shinsei: Enabled minimal mode.")
endif()

if(SHINSEI_BUILD_EX)
    target_compile_definitions(_shinsei_build_lib
		INTERFACE _SHINSEI_BUILD_EX
	)
	set(SHINSEI_THIRDPARTY_INCLUDE_DIR
		${CMAKE_CURRENT_SOURCE_DIR}/third_party/include
	)
	set(SHINSEI_THIRDPARTY_LIBRARY_DIR
		${CMAKE_CURRENT_SOURCE_DIR}/third_party/libs
	)
	target_include_directories(_shinsei_build_lib
    INTERFACE
        $<BUILD_INTERFACE:${SHINSEI_THIRDPARTY_INCLUDE_DIR}>
	)
	message(STATUS "shinsei: Enabled EX mode.")
else()
	set(SHINSEI_BUILD_EX_PYTHON3 OFF CACHE BOOL "" FORCE)
    set(SHINSEI_BUILD_EX_SQLITE OFF CACHE BOOL "" FORCE)
	set(SHINSEI_BUILD_EX_POSTGRESQL OFF CACHE BOOL "" FORCE)
	message(STATUS "shinsei: Enabled standard mode.")
endif()

function(shinseiApplyOptionMacro option_name interface_macro_name)
    if(DEFINED ${option_name} AND ${${option_name}})
        set(private_macro "_${option_name}")
        target_compile_definitions(_shinsei_build_lib
            INTERFACE ${private_macro}
        )
        if(NOT "${interface_macro_name}" STREQUAL "")
            target_compile_definitions(_shinsei_build_lib
                INTERFACE ${interface_macro_name}
            )
        endif()
    endif()
endfunction()

function(shinseiApplyOutputDirs target subdir)
    set_target_properties(${target} PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY
            "${_SHINSEI_LIBRARY_DIR}/shinsei/$<IF:$<CONFIG:Release>,${subdir},$<LOWER_CASE:$<CONFIG>>/${subdir}>"

        LIBRARY_OUTPUT_DIRECTORY
            "${_SHINSEI_LIBRARY_DIR}/shinsei/$<IF:$<CONFIG:Release>,${subdir},$<LOWER_CASE:$<CONFIG>>/${subdir}>"

        RUNTIME_OUTPUT_DIRECTORY
            "${_SHINSEI_BINARY_DIR}/libs/shinsei/$<IF:$<CONFIG:Release>,${subdir},$<LOWER_CASE:$<CONFIG>>/${subdir}>"
    )
endfunction()

function(shinseiAddModules base_dir)
    # exclusion
    set(EXCLUDE_DIRS ${ARGN})

    file(GLOB children CONFIGURE_DEPENDS "${base_dir}/*")

    foreach(child ${children})
        if(NOT IS_DIRECTORY ${child})
            continue()
        endif()

        get_filename_component(child_name ${child} NAME)

        list(FIND EXCLUDE_DIRS ${child_name} exclude_index)

        if(NOT exclude_index EQUAL -1)
            message(STATUS "shinsei: Skipping excluded dir: ${child_name}")
            continue()
        endif()

        # add modules
        if(EXISTS "${child}/CMakeLists.txt")
            message(STATUS "shinsei: Registering module: ${child_name}")
            add_subdirectory(${child})
        endif()
    endforeach()
endfunction()

function(shinseiAddModule MODULE_NAME SOURCE_NAME)
	project(SinhoMoeme_${MODULE_NAME})
	
    # minimal object
    add_library(${MODULE_NAME}_minimal_obj OBJECT
        ${CMAKE_CURRENT_SOURCE_DIR}/${SOURCE_NAME}.c
    )

    set_target_properties(${MODULE_NAME}_minimal_obj PROPERTIES
        C_STANDARD 23
        C_EXTENSIONS ON
    )

    target_compile_options(${MODULE_NAME}_minimal_obj PRIVATE
        $<$<CONFIG:Release>:-O3>
        $<$<CONFIG:Release>:-flto>
    )

    target_include_directories(${MODULE_NAME}_minimal_obj
        PUBLIC
            $<BUILD_INTERFACE:${_SHINSEI_INCLUDE_DIR}>
            $<INSTALL_INTERFACE:include>
    )

    target_link_libraries(${MODULE_NAME}_minimal_obj
        PRIVATE shinsei::minimal
    )

    # std object
    if(NOT SHINSEI_BUILD_MINIMAL)
        set(PLATFORM_SRC)

        if(WIN32 AND EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${SOURCE_NAME}-windows.c)
            set(PLATFORM_SRC ${SOURCE_NAME}-windows.c)
        elseif(UNIX AND EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${SOURCE_NAME}-unix.c)
            set(PLATFORM_SRC ${SOURCE_NAME}-unix.c)
        endif()

        add_library(${MODULE_NAME}_obj OBJECT ${PLATFORM_SRC})

        set_target_properties(${MODULE_NAME}_obj PROPERTIES
            C_STANDARD 23
            C_EXTENSIONS ON
        )

        target_compile_options(${MODULE_NAME}_obj PRIVATE
            $<$<CONFIG:Release>:-O3>
            $<$<CONFIG:Release>:-flto>
        )

        target_include_directories(${MODULE_NAME}_obj
            PUBLIC
                $<BUILD_INTERFACE:${_SHINSEI_INCLUDE_DIR}>
                $<INSTALL_INTERFACE:include>
        )

        target_link_libraries(${MODULE_NAME}_obj
            PRIVATE
                shinsei::std
        )
    endif()

    # minimal static/shared
    add_library(${MODULE_NAME}_minimal_static STATIC
        $<TARGET_OBJECTS:${MODULE_NAME}_minimal_obj>
    )

    add_library(${MODULE_NAME}_minimal_shared SHARED
        $<TARGET_OBJECTS:${MODULE_NAME}_minimal_obj>
    )

    set_target_properties(${MODULE_NAME}_minimal_static
        ${MODULE_NAME}_minimal_shared
        PROPERTIES OUTPUT_NAME "shinsei_${SOURCE_NAME}-minimal"
    )

    target_compile_options(${MODULE_NAME}_minimal_static PRIVATE
        $<$<CONFIG:Release>:-static-libgcc>
        $<$<CONFIG:Release>:-static>
    )

    target_compile_options(${MODULE_NAME}_minimal_shared PRIVATE
        $<$<CONFIG:Release>:-static-libgcc>
    )
	
	shinseiApplyOutputDirs(${MODULE_NAME}_minimal_static "minimal")
	shinseiApplyOutputDirs(${MODULE_NAME}_minimal_shared "minimal")
	
    # std static/shared
    if(NOT SHINSEI_BUILD_MINIMAL)
        add_library(${MODULE_NAME}_static STATIC
            $<TARGET_OBJECTS:${MODULE_NAME}_minimal_obj>
            $<TARGET_OBJECTS:${MODULE_NAME}_obj>
        )

        add_library(${MODULE_NAME}_shared SHARED
            $<TARGET_OBJECTS:${MODULE_NAME}_minimal_obj>
            $<TARGET_OBJECTS:${MODULE_NAME}_obj>
        )

        set_target_properties(${MODULE_NAME}_static
            ${MODULE_NAME}_shared
            PROPERTIES OUTPUT_NAME "shinsei_${SOURCE_NAME}"
        )

        target_compile_options(${MODULE_NAME}_static PRIVATE
            $<$<CONFIG:Release>:-static-libgcc>
            $<$<CONFIG:Release>:-static>
        )

        target_compile_options(${MODULE_NAME}_shared PRIVATE
            $<$<CONFIG:Release>:-static-libgcc>
        )

        if(SHINSEI_MINIMAL_SHARED)
            set_target_properties(${MODULE_NAME}_shared PROPERTIES
                C_VISIBILITY_PRESET hidden
                VISIBILITY_INLINES_HIDDEN YES
            )

            target_compile_definitions(${MODULE_NAME}_shared
                PRIVATE _SHINSEI_BUILD_SHARED
            )
        endif()
		
		shinseiApplyOutputDirs(${MODULE_NAME}_static "")
		shinseiApplyOutputDirs(${MODULE_NAME}_shared "")
    endif()
	
	# register minimal obj
	set_property(GLOBAL APPEND PROPERTY SHINSEI_MINIMAL_OBJECTS
		$<TARGET_OBJECTS:${MODULE_NAME}_minimal_obj>
	)

	# register std obj
	if(NOT SHINSEI_BUILD_MINIMAL)
		set_property(GLOBAL APPEND PROPERTY SHINSEI_STD_OBJECTS
			$<TARGET_OBJECTS:${MODULE_NAME}_obj>
		)
	endif()
	
    # install
    install(TARGETS
        ${MODULE_NAME}_minimal_static
        ${MODULE_NAME}_minimal_shared
        EXPORT shinseiTargets
    )

    if(NOT SHINSEI_BUILD_MINIMAL)
        install(TARGETS
            ${MODULE_NAME}_static
            ${MODULE_NAME}_shared
            EXPORT shinseiTargets
        )
    endif()
endfunction()

function(addShinseiDependency CURRENT_MODULE DEP_MODULE)
    set_property(GLOBAL APPEND PROPERTY SHINSEI_DEPS ${CURRENT_MODULE})
    set_property(GLOBAL APPEND PROPERTY SHINSEI_DEPS ${DEP_MODULE})
endfunction()

shinseiApplyOptionMacro(SHINSEI_BUILD_EX_POSTGRESQL "")
shinseiApplyOptionMacro(SHINSEI_BUILD_EX_SQLITE "")
shinseiApplyOptionMacro(SHINSEI_BUILD_EX_PYTHON3 "")

# register modules
shinseiAddModules(. "ex" "cmake" "include" "libs" "third_party")
if(SHINSEI_BUILD_EX)
	add_subdirectory(ex)
endif()

# get objects
get_property(_SHINSEI_MINIMAL_OBJECTS GLOBAL PROPERTY SHINSEI_MINIMAL_OBJECTS)
get_property(_SHINSEI_STD_OBJECTS GLOBAL PROPERTY SHINSEI_STD_OBJECTS)

# dependencies
get_property(_deps GLOBAL PROPERTY SHINSEI_DEPS)

list(LENGTH _deps _deps_len)

if(_deps_len GREATER 0)
    math(EXPR _deps_pairs "${_deps_len} / 2")
    math(EXPR _deps_last  "${_deps_pairs} - 1")

    foreach(i RANGE 0 ${_deps_last})
        math(EXPR idx0 "2 * ${i}")
        math(EXPR idx1 "2 * ${i} + 1")

        list(GET _deps ${idx0} CURRENT_MODULE)
        list(GET _deps ${idx1} DEP_MODULE)

		# shared minimal
		if(TARGET ${CURRENT_MODULE}_minimal_shared AND TARGET ${DEP_MODULE}_minimal_obj)
			target_sources(${CURRENT_MODULE}_minimal_shared PRIVATE
				$<TARGET_OBJECTS:${DEP_MODULE}_minimal_obj>
			)
		endif()

		# shared std
		if(TARGET ${CURRENT_MODULE}_shared AND TARGET ${DEP_MODULE}_minimal_obj)
			target_sources(${CURRENT_MODULE}_shared PRIVATE
				$<TARGET_OBJECTS:${DEP_MODULE}_minimal_obj>
			)
		endif()

		if(TARGET ${CURRENT_MODULE}_shared AND TARGET ${DEP_MODULE}_obj)
			target_sources(${CURRENT_MODULE}_shared PRIVATE
				$<TARGET_OBJECTS:${DEP_MODULE}_obj>
			)
		endif()

		# static
		if(TARGET ${CURRENT_MODULE}_static AND TARGET ${DEP_MODULE}_static)
			target_link_libraries(${CURRENT_MODULE}_static PUBLIC
				${DEP_MODULE}_static
			)
		endif()

		if(TARGET ${CURRENT_MODULE}_minimal_static AND TARGET ${DEP_MODULE}_minimal_static)
			target_link_libraries(${CURRENT_MODULE}_minimal_static PUBLIC
				${DEP_MODULE}_minimal_static
			)
		endif()
	endforeach()
endif()

# shinsei-minimal
add_library(shinsei-minimal_static STATIC
    ${_SHINSEI_MINIMAL_OBJECTS}
)

add_library(shinsei-minimal_shared SHARED
    ${_SHINSEI_MINIMAL_OBJECTS}
)

set_target_properties(shinsei-minimal_static PROPERTIES OUTPUT_NAME shinsei-minimal)
set_target_properties(shinsei-minimal_shared PROPERTIES OUTPUT_NAME shinsei-minimal)

target_compile_options(shinsei-minimal_static PRIVATE
	$<$<CONFIG:Release>:-static-libgcc>
)

target_compile_options(shinsei-minimal_shared PRIVATE
	$<$<CONFIG:Release>:-static-libgcc>
	$<$<CONFIG:Release>:-static>
)

shinseiApplyOutputDirs(shinsei-minimal_static "")
shinseiApplyOutputDirs(shinsei-minimal_shared "")

# shinsei
if(NOT SHINSEI_BUILD_MINIMAL)
    add_library(shinsei_static STATIC
		${_SHINSEI_MINIMAL_OBJECTS}
		${_SHINSEI_STD_OBJECTS}
	)

	add_library(shinsei_shared SHARED
		${_SHINSEI_MINIMAL_OBJECTS}
		${_SHINSEI_STD_OBJECTS}
	)

    set_target_properties(shinsei_static PROPERTIES OUTPUT_NAME shinsei)
    set_target_properties(shinsei_shared PROPERTIES OUTPUT_NAME shinsei)

    target_compile_options(shinsei_static PRIVATE
		$<$<CONFIG:Release>:-static-libgcc>
    )
	
    target_compile_options(shinsei_shared PRIVATE
		$<$<CONFIG:Release>:-static-libgcc>
        $<$<CONFIG:Release>:-static>
    )

    shinseiApplyOutputDirs(shinsei_static "")
    shinseiApplyOutputDirs(shinsei_shared "")
endif()

# shinsei-ex
if(SHINSEI_BUILD_EX)
	add_library(shinsei-ex_static STATIC
        $<TARGET_OBJECTS:shinsei_struct_minimal_obj>
        $<TARGET_OBJECTS:shinsei_io_minimal_obj>
        $<TARGET_OBJECTS:shinsei_str_minimal_obj>
        $<TARGET_OBJECTS:shinsei_path_minimal_obj>
        $<TARGET_OBJECTS:shinsei_sys_minimal_obj>
        $<TARGET_OBJECTS:shinsei_struct_obj>
        $<TARGET_OBJECTS:shinsei_io_obj>
        $<TARGET_OBJECTS:shinsei_str_obj>
        $<TARGET_OBJECTS:shinsei_path_obj>
        $<TARGET_OBJECTS:shinsei_sys_obj>
    )

    add_library(shinsei-ex_shared SHARED
        $<TARGET_OBJECTS:shinsei_struct_minimal_obj>
        $<TARGET_OBJECTS:shinsei_io_minimal_obj>
        $<TARGET_OBJECTS:shinsei_str_minimal_obj>
        $<TARGET_OBJECTS:shinsei_path_minimal_obj>
        $<TARGET_OBJECTS:shinsei_sys_minimal_obj>
        $<TARGET_OBJECTS:shinsei_struct_obj>
        $<TARGET_OBJECTS:shinsei_io_obj>
        $<TARGET_OBJECTS:shinsei_str_obj>
        $<TARGET_OBJECTS:shinsei_path_obj>
        $<TARGET_OBJECTS:shinsei_sys_obj>
    )

    if(SHINSEI_BUILD_EX_PYTHON3)
		target_sources(shinsei-ex_static PRIVATE
			$<TARGET_OBJECTS:shinsei_ex_python3_obj>
		)
		
		target_link_libraries(shinsei-ex_static
			PUBLIC shinsei::ex::python
		)

		target_sources(shinsei-ex_shared PRIVATE
			$<TARGET_OBJECTS:shinsei_ex_python3_obj>
		)
		
		target_link_libraries(shinsei-ex_shared
			PUBLIC shinsei::ex::python
		)
	endif()
	
    if(SHINSEI_BUILD_EX_SQLITE)
        #target_link_libraries(shinsei-ex_static PUBLIC shinsei_ex_sqlite_static)
        #target_link_libraries(shinsei-ex_shared PUBLIC shinsei_ex_sqlite_shared)
    endif()
	
    if(SHINSEI_BUILD_EX_POSTGRESQL)
        #target_link_libraries(shinsei-ex_static PUBLIC shinsei_ex_postgresql_static)
        #target_link_libraries(shinsei-ex_shared PUBLIC shinsei_ex_postgresql_shared)
    endif()
	
	target_compile_options(shinsei-ex_static PRIVATE
		$<$<CONFIG:Release>:-static-libgcc>
	)

	target_compile_options(shinsei-ex_shared PRIVATE
		$<$<CONFIG:Release>:-static-libgcc>
		$<$<CONFIG:Release>:-static>
	)
	
    set_target_properties(shinsei-ex_static PROPERTIES OUTPUT_NAME shinsei-ex)
    set_target_properties(shinsei-ex_shared PROPERTIES OUTPUT_NAME shinsei-ex)
	
	shinseiApplyOutputDirs(shinsei-ex_static "")
    shinseiApplyOutputDirs(shinsei-ex_shared "")
endif()

# install
install(TARGETS
    _shinsei_build_lib
    _shinsei_minimal
    _shinsei_std
    EXPORT shinseiTargets
)

if(SHINSEI_BUILD_MINIMAL)
	install(TARGETS
		shinsei-minimal_static
		shinsei-minimal_shared
		EXPORT shinseiTargets
	)
endif()

if(NOT SHINSEI_BUILD_MINIMAL)
	install(TARGETS
		shinsei_static
		shinsei_shared
		EXPORT shinseiTargets
	)
endif()

if(SHINSEI_BUILD_EX)
    install(TARGETS
        shinsei-ex_static
        shinsei-ex_shared
        EXPORT shinseiTargets
    )
endif()

install(DIRECTORY include/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(EXPORT shinseiTargets
    NAMESPACE shinsei::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/shinsei
)

configure_package_config_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/cmake/shinseiConfig.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/shinseiConfig.cmake
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/shinsei
)

install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/shinseiConfig.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/shinsei
)