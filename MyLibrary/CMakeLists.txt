file(GLOB_RECURSE MY_LIBRARY_SRC CONFIGURE_DEPENDS "*.h" "*.c" "*.hpp" "*.cpp")

add_library(MyLibrary
	STATIC
	${MY_LIBRARY_SRC}
)

set_target_properties(MyLibrary PROPERTIES
	CXX_STANDARD 20
	CXX_STANDARD_REQUIRED ON
	CXX_EXTENSIONS OFF
	C_STANDARD 17
	C_STANDARD_REQUIRED ON
	C_EXTENSIONS OFF
	POSITION_INDEPENDENT_CODE ON
	OUTPUT_NAME MyLibrary
)

target_include_directories(MyLibrary
	PUBLIC
		${CMAKE_CURRENT_SOURCE_DIR}/src
	PRIVATE

)

cmake_base_configure_target(MyLibrary)
cmake_base_apply_target_definitions(MyLibrary MY_LIBRARY)
cmake_base_apply_os_definitions_to_target(MyLibrary MY_LIBRARY)
cmake_base_apply_architecture_definitions_to_target(MyLibrary MY_LIBRARY)
cmake_base_apply_compiler_definitions_to_target(MyLibrary MY_LIBRARY)
cmake_base_apply_sanitizers(MyLibrary SANITIZERS ASAN UBSAN CONFIGS Debug)
