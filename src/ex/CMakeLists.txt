cmake_minimum_required(VERSION 3.5...3.31)
set(MODULE_NAME ex)
project(Shinsei_SinhoMoeme_${MODULE_NAME})

add_library(_shinsei_ex INTERFACE)
add_library(shinsei::ex ALIAS _shinsei_ex)
target_link_libraries(_shinsei_ex
	INTERFACE
		_shinsei_minimal
		_shinsei_std
)

if(SHINSEI_BUILD_EX_PYTHON3)
	add_subdirectory(python3)
endif()

install(TARGETS _shinsei_ex EXPORT shinseiTargets)