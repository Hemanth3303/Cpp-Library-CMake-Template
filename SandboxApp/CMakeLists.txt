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
	POSITION_INDEPENDENT_CODE ON
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

target_compile_definitions(SandboxApp
	PUBLIC

	PRIVATE
		SANDBOX_APP
)

# PLATFORM AND COMPILER SPECIFIC

if(CMAKE_SYSTEM_NAME STREQUAL "Windows")

	target_compile_definitions(SandboxApp
		PUBLIC

		PRIVATE
			NOMINMAX
			_CRT_SECURE_NO_WARNINGS
			WIN32_LEAN_AND_MEAN
			SANDBOX_APP_PLATFORM_WINDOWS
	)

	if(MSVC)
		target_compile_options(SandboxApp
			PUBLIC

			PRIVATE
				/Zc:__cplusplus
		)
	elseif(MINGW)
		target_link_libraries(SandboxApp
			PUBLIC
				m
			PRIVATE

		)
		target_link_options(SandboxApp
			PUBLIC

			PRIVATE
				-static
				-static-libgcc
				-static-libstdc++
		)
	elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
		target_link_libraries(SandboxApp
			PUBLIC

			PRIVATE
		)
		target_link_options(SandboxApp
			PUBLIC

			PRIVATE
				-static
				-static-libstdc++
		)
	endif()

endif()

if(CMAKE_SYSTEM_NAME STREQUAL "Linux")

	target_compile_definitions(SandboxApp
		PUBLIC

		PRIVATE
			SANDBOX_APP_PLATFORM_LINUX
	)

	if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
		target_link_libraries(SandboxApp
			PUBLIC
				dl
				m
				pthread
			PRIVATE

		)
		target_link_options(SandboxApp
			PUBLIC

			PRIVATE
		)
	elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
		target_link_libraries(SandboxApp
			PUBLIC

			PRIVATE
		)
		target_link_options(SandboxApp
			PUBLIC

			PRIVATE
		)
	endif()

endif()

if(CMAKE_SYSTEM_NAME STREQUAL "Darwin")

	target_compile_definitions(SandboxApp
		PUBLIC

		PRIVATE
			SANDBOX_APP_PLATFORM_OSX
	)

endif()

# CONFIGURATION SPECIFIC

target_compile_definitions(SandboxApp
	PUBLIC

	PRIVATE
		$<$<CONFIG:Debug>:SANDBOX_APP_DEBUG_BUILD>
		$<$<CONFIG:Debug>:DEBUG>

		$<$<CONFIG:Profile>:SANDBOX_APP_PROFILE_BUILD>
		$<$<CONFIG:Profile>:NDEBUG>

		$<$<CONFIG:Release>:SANDBOX_APP_RELEASE_BUILD>
		$<$<CONFIG:Release>:NDEBUG>
)

# POST-BUILD RESOURCE COPY

add_custom_command(
	TARGET SandboxApp POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_directory
		${CMAKE_CURRENT_SOURCE_DIR}/res
		${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/res
	COMMENT "Copying resource folder to binary directory"
)
