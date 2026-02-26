cmake_minimum_required(VERSION 3.5...3.31)
set(MODULE_NAME ex_python)
project(Shinsei_SinhoMoeme_${MODULE_NAME})

target_include_directories(_shinsei_build_lib
    INTERFACE
    ${SHINSEI_THIRDPARTY_INCLUDE_DIR}/python3
)
target_link_libraries(_shinsei_build_lib
    INTERFACE
    ${SHINSEI_THIRDPARTY_LIBRARY_DIR}/python3/Python314.lib
)

shinseiAddModules(${CMAKE_CURRENT_SOURCE_DIR})