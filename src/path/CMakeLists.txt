cmake_minimum_required(VERSION 3.18)

shinseiAddModule(shinsei_path path)

addShinseiDependency(shinsei_path shinsei_str)

if(NOT SHINSEI_BUILD_MINIMAL AND WIN32)
    addShinseiDependency(shinsei_path shinsei_struct)
endif()