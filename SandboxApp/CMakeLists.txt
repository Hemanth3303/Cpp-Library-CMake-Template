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
		${PROJECT_SOURCE_DIR}/MyLibrary/src
		${PROJECT_SOURCE_DIR}/SandboxApp/src
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

if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
	target_compile_definitions(SandboxApp
		PUBLIC
			
		PRIVATE
			NOMINMAX
			_CRT_SECURE_NO_WARNINGS
			WIN32_LEAN_AND_MEAN
			APP_WINDOWS
	)
	if (MSVC)
		target_compile_options(SandboxApp
			PUBLIC
				
			PRIVATE
				/Zc:__cplusplus
		)
	elseif (MINGW)
		target_link_libraries(SandboxApp
			PUBLIC
				
			PRIVATE
				m
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
		)
	endif()
endif()

if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
	target_compile_definitions(SandboxApp
		PRIVATE
		APP_LINUX
	)
	if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
		target_link_libraries(SandboxApp
			PUBLIC
				
			PRIVATE
				dl
				m
  				pthread
		)
		target_link_options(SandboxApp
			PUBLIC
				
			PRIVATE
				-static
				-static-libgcc
				-static-libstdc++
		)
	elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
		target_link_libraries(SandboxApp
			PUBLIC
				
			PRIVATE
		)
		target_link_options(SandboxApp
			PUBLIC
				
			PRIVATE
				-static
		)
	endif()
endif()

if(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
	target_compile_definitions(SandboxApp
		PUBLIC
				
		PRIVATE
			APP_OSX
	)
endif()

if(CMAKE_BUILD_TYPE STREQUAL Debug)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS_DEBUG}" CACHE STRING "CXX flags" FORCE)
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS_DEBUG}" CACHE STRING "C flags" FORCE)
	set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS_DEBUG}" CACHE STRING "Linker flags" FORCE)
	target_compile_definitions(SandboxApp
		PUBLIC
				
		PRIVATE
			APP_DEBUG
			DEBUG
	)
endif()

if(CMAKE_BUILD_TYPE STREQUAL Release)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS_RELEASE}" CACHE STRING "CXX flags" FORCE)
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS_RELEASE}" CACHE STRING "C flags" FORCE)
	set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS_RELEASE}" CACHE STRING "Linker flags" FORCE)
	target_compile_definitions(SandboxApp
		PUBLIC
				
		PRIVATE
			APP_RELEASE
			NDEBUG
	)
endif()

if(CMAKE_BUILD_TYPE STREQUAL Dist)
	remove_definitions(-DAPP_RELEASE)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS_RELEASE}" CACHE STRING "CXX flags" FORCE)
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS_RELEASE}" CACHE STRING "C flags" FORCE)
	set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS_RELEASE}" CACHE STRING "Linker flags" FORCE)

	target_compile_definitions(SandboxApp
		PUBLIC
				
		PRIVATE
			APP_DIST
			NDEBUG
	)
endif()

add_custom_command(
	TARGET SandboxApp POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_directory
		${PROJECT_SOURCE_DIR}/SandboxApp/res
		${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/res
	COMMENT "Copying resource folder to binary directory"
)