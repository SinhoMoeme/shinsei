cmake_minimum_required(VERSION 3.18...3.31)

set(MODULE_NAME shinsei_struct)
set(SOURCE_NAME struct)

project(Shinsei_SinhoMoeme_${MODULE_NAME})

# STATIC

add_library(${MODULE_NAME}_static STATIC
    ${CMAKE_CURRENT_SOURCE_DIR}/${SOURCE_NAME}.c
)

if(NOT SHINSEI_BUILD_MINIMAL)
    if(WIN32)
        target_sources(${MODULE_NAME}_static PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}/${SOURCE_NAME}-windows.c
        )
    elseif(UNIX)
        target_sources(${MODULE_NAME}_static PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}/${SOURCE_NAME}-linux.c
        )
    endif()
endif()

set_target_properties(${MODULE_NAME}_static PROPERTIES
    C_STANDARD 23
    C_EXTENSIONS ON
    OUTPUT_NAME "${SOURCE_NAME}"
)

target_compile_options(${MODULE_NAME}_static PRIVATE
    $<$<CONFIG:Release>:-flto>
    $<$<CONFIG:Release>:-O3>
	$<$<CONFIG:Release>:-static-libgcc>
    $<$<CONFIG:Release>:-static>
)

target_include_directories(${MODULE_NAME}_static
    PUBLIC
        $<BUILD_INTERFACE:${_SHINSEI_INCLUDE_DIR}>
        $<INSTALL_INTERFACE:include>
)

target_link_libraries(${MODULE_NAME}_static
    PRIVATE
        shinsei::minimal
        shinsei::std
)

# SHARED

add_library(${MODULE_NAME}_shared SHARED
    ${CMAKE_CURRENT_SOURCE_DIR}/${SOURCE_NAME}.c
)

if(NOT SHINSEI_BUILD_MINIMAL)
    if(WIN32)
        target_sources(${MODULE_NAME}_shared PRIVATE
            ${SOURCE_NAME}-windows.c
        )
    elseif(UNIX)
        target_sources(${MODULE_NAME}_shared PRIVATE
            ${SOURCE_NAME}-linux.c
        )
    endif()
endif()

set_target_properties(${MODULE_NAME}_shared PROPERTIES
    C_STANDARD 23
    C_EXTENSIONS ON
    OUTPUT_NAME "${SOURCE_NAME}"
)

target_compile_options(${MODULE_NAME}_shared PRIVATE
    $<$<CONFIG:Release>:-flto>
    $<$<CONFIG:Release>:-O3>
	$<$<CONFIG:Release>:-static-libgcc>
    $<$<CONFIG:Release>:-static>
)

target_include_directories(${MODULE_NAME}_shared
    PUBLIC
        $<BUILD_INTERFACE:${_SHINSEI_INCLUDE_DIR}>
        $<INSTALL_INTERFACE:include>
)

target_link_libraries(${MODULE_NAME}_shared
    PRIVATE
        shinsei::minimal
        shinsei::std
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

# PATH
set(SUBDIR "")

file(MAKE_DIRECTORY "${_SHINSEI_LIBRARY_DIR}/shinsei/${SUBDIR}")
file(MAKE_DIRECTORY "${_SHINSEI_BINARY_DIR}/libs/shinsei/${SUBDIR}")

shinseiApplyOutputDirs(${MODULE_NAME}_static "${SUBDIR}")
shinseiApplyOutputDirs(${MODULE_NAME}_shared "${SUBDIR}")

# INSTALL

install(TARGETS
    ${MODULE_NAME}_static
    ${MODULE_NAME}_shared
    EXPORT shinseiTargets
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)