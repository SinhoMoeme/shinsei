cmake_minimum_required(VERSION 3.5...3.31)
set(MODULE_NAME ex)
project(Shinsei_SinhoMoeme_${MODULE_NAME})

if(SHINSEI_BUILD_EX_PYTHON3)
	add_subdirectory(python3)
endif()