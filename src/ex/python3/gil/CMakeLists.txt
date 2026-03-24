cmake_minimum_required(VERSION 3.18)

set(MODULE_NAME shinsei_ex_python3)
set(SOURCE_NAME gil)

project(SinhoMoeme_${MODULE_NAME}_${SOURCE_NAME})

# ex object
add_library(${MODULE_NAME}_${SOURCE_NAME}_obj OBJECT
    ${CMAKE_CURRENT_SOURCE_DIR}/${SOURCE_NAME}.c
)

set_target_properties(${MODULE_NAME}_${SOURCE_NAME}_obj PROPERTIES
    C_STANDARD 23
    C_EXTENSIONS ON
)

target_compile_options(${MODULE_NAME}_${SOURCE_NAME}_obj PRIVATE
    $<$<CONFIG:Release>:-O3>
    $<$<CONFIG:Release>:-flto>
	-Wall
	-Wextra
	-Wpedantic
	-Wconversion
	-Wshadow
	-Wdouble-promotion
	-Wformat=2
	-Wsign-conversion
	-Wcast-align
	-Wundef
	-Wpointer-arith
	-Wstrict-prototypes
)

target_include_directories(${MODULE_NAME}_${SOURCE_NAME}_obj
    PRIVATE
        ${_SHINSEI_INCLUDE_DIR}
        ${SHINSEI_THIRDPARTY_INCLUDE_DIR}
)

target_link_libraries(${MODULE_NAME}_${SOURCE_NAME}_obj
    PUBLIC shinsei::ex::python
)

# ex static
add_library(${MODULE_NAME}_${SOURCE_NAME}_static STATIC
    $<TARGET_OBJECTS:${MODULE_NAME}_${SOURCE_NAME}_obj>
)

set_target_properties(${MODULE_NAME}_${SOURCE_NAME}_static PROPERTIES
    OUTPUT_NAME shinsei_ex_python3_${SOURCE_NAME}
)

target_link_libraries(${MODULE_NAME}_${SOURCE_NAME}_static
    PUBLIC shinsei::ex::python
)

shinseiApplyOutputDirs(${MODULE_NAME}_${SOURCE_NAME}_static ex/python3)

# ex shared
add_library(${MODULE_NAME}_${SOURCE_NAME}_shared SHARED
    $<TARGET_OBJECTS:${MODULE_NAME}_${SOURCE_NAME}_obj>
)

set_target_properties(${MODULE_NAME}_${SOURCE_NAME}_shared PROPERTIES
    OUTPUT_NAME shinsei_ex_python3_${SOURCE_NAME}
)

target_link_libraries(${MODULE_NAME}_${SOURCE_NAME}_shared
    PUBLIC shinsei::ex::python
)

shinseiApplyOutputDirs(${MODULE_NAME}_${SOURCE_NAME}_shared ex/python3)

# install
install(TARGETS
    ${MODULE_NAME}_${SOURCE_NAME}_static
    ${MODULE_NAME}_${SOURCE_NAME}_shared
    EXPORT shinseiTargets
)