file(GLOB_RECURSE SANDBOX_APP_SRC CONFIGURE_DEPENDS "*.h" "*.c" "*.hpp" "*.cpp")

add_executable(SandboxApp
	${SANDBOX_APP_SRC}
)

set_target_properties(SandboxApp PROPERTIES
	CXX_STANDARD 20
	CXX_STANDARD_REQUIRED ON
	CXX_EXTENSIONS OFF
	C_STANDARD 17
	C_STANDARD_REQUIRED ON
	C_EXTENSIONS OFF
	OUTPUT_NAME SandboxApp
)

target_include_directories(SandboxApp
	PUBLIC

	PRIVATE
		${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(SandboxApp
	PUBLIC

	PRIVATE
		MyLibrary
)

cmake_base_configure_target(SandboxApp)
cmake_base_apply_target_definitions(SandboxApp SANDBOX_APP)
cmake_base_apply_os_definitions_to_target(SandboxApp SANDBOX_APP)
cmake_base_apply_architecture_definitions_to_target(SandboxApp SANDBOX_APP)
cmake_base_apply_compiler_definitions_to_target(SandboxApp SANDBOX_APP)
cmake_base_apply_sanitizers(SandboxApp SANITIZERS ASAN UBSAN CONFIGS Debug)

# POST-BUILD RESOURCE COPY
add_custom_command(
	TARGET SandboxApp POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_directory
		"${CMAKE_CURRENT_SOURCE_DIR}/res"
		"$<TARGET_FILE_DIR:SandboxApp>/res"
	COMMENT "Copying resource folder to binary directory"
)

# adding res to install
# cmake-base already handles bin, lib and include
# Note to future self:
# res/ means copy contents of res to bin/res
# if just res, then it will copy to bin/res/res
install(
	DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/res/"
    DESTINATION bin/res
)
