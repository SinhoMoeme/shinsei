cmake_minimum_required(VERSION 3.5...3.31)
project(Shinsei_SinhoMoeme)

add_library(_shinsei_build_lib INTERFACE)

target_compile_definitions(_shinsei_build_lib
    INTERFACE _SHINSEI_BUILD_LIB
)

set(_SHINSEI_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
set(_SHINSEI_LIBRARY_DIR ${CMAKE_SOURCE_DIR}/libs)
set(_SHINSEI_BINARY_DIR ${CMAKE_SOURCE_DIR}/../release/bin)

target_include_directories(_shinsei_build_lib
    INTERFACE ${_SHINSEI_INCLUDE_DIR}
)

set(_SHINSEI_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${_SHINSEI_LIBRARY_DIR}/shinsei)
set(_SHINSEI_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${_SHINSEI_LIBRARY_DIR}/shinsei)
set(_SHINSEI_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${_SHINSEI_BINARY_DIR}/libs/shinsei)
set(_SHINSEI_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${_SHINSEI_LIBRARY_DIR}/shinsei/debug)
set(_SHINSEI_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${_SHINSEI_LIBRARY_DIR}/shinsei/debug)
set(_SHINSEI_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${_SHINSEI_BINARY_DIR}/libs/shinsei/debug)

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
	set(SHINSEI_THIRDPARTY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/third-party/include)
	set(SHINSEI_THIRDPARTY_LIBRARY_DIR ${CMAKE_SOURCE_DIR}/third-party/libs)
	target_include_directories(_shinsei_build_lib
    INTERFACE
		${SHINSEI_THIRDPARTY_INCLUDE_DIR}
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

if(SHINSEI_BUILD_EX)
	message(STATUS "shinsei: Building EX modules...")
	add_subdirectory(ex)
endif()