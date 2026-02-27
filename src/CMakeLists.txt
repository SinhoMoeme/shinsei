cmake_minimum_required(VERSION 3.5...3.31)
project(Shinsei_SinhoMoeme)

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
		${CMAKE_CURRENT_SOURCE_DIR}/third-party/include
	)
	set(SHINSEI_THIRDPARTY_LIBRARY_DIR
		${CMAKE_CURRENT_SOURCE_DIR}/third-party/libs
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
    file(GLOB children CONFIGURE_DEPENDS "${base_dir}/*")
    foreach(child ${children})
        if(IS_DIRECTORY ${child} AND EXISTS "${child}/CMakeLists.txt")
            get_filename_component(child_name ${child} NAME)
            message(STATUS "shinsei: Registering module: ${child_name}")
            add_subdirectory(${child})
        endif()
    endforeach()
endfunction()

shinseiApplyOptionMacro(SHINSEI_BUILD_EX_POSTGRESQL "")
shinseiApplyOptionMacro(SHINSEI_BUILD_EX_SQLITE "")
shinseiApplyOptionMacro(SHINSEI_BUILD_EX_PYTHON3 "")

if(SHINSEI_BUILD_MINIMAL)
	message(STATUS "shinsei: Building minimal modules...")
else()
	message(STATUS "shinsei: Building standard modules...")
endif()
add_subdirectory(struct)

if(SHINSEI_BUILD_EX)
	message(STATUS "shinsei: Building EX modules...")
	add_subdirectory(ex)
endif()

install(TARGETS
    _shinsei_build_lib
    _shinsei_minimal
    _shinsei_std
    EXPORT shinseiTargets
)

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