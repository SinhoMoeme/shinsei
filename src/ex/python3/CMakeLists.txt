cmake_minimum_required(VERSION 3.5...3.31)
set(MODULE_NAME ex_python)
project(Shinsei_SinhoMoeme_${MODULE_NAME})

add_library(_shinsei_ex_python INTERFACE)
add_library(shinsei::ex_python ALIAS _shinsei_ex_python)
target_link_libraries(_shinsei_ex_python INTERFACE _shinsei_ex)

target_include_directories(_shinsei_ex_python
    INTERFACE ${_SHINSEI_THIRDPARTY_INCLUDE_DIR}/python3
)
target_link_libraries(_shinsei_ex_python
    INTERFACE
        ${SHINSEI_THIRDPARTY_LIBRARY_DIR}/python3/Python314.lib
)

shinseiAddModules(${CMAKE_CURRENT_SOURCE_DIR})

install(TARGETS _shinsei_ex_python EXPORT shinseiTargets)