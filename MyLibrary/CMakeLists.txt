file(GLOB_RECURSE MY_LIBRARY_SRC CONFIGURE_DEPENDS "*.h" "*.c" "*.hpp" "*.cpp")

add_library(MyLibrary
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

target_compile_definitions(MyLibrary
	PUBLIC

	PRIVATE
		MY_LIBRARY
)

# PLATFORM AND COMPILER SPECIFIC

if(CMAKE_SYSTEM_NAME STREQUAL "Windows")

	target_compile_definitions(MyLibrary
		PUBLIC

		PRIVATE
			NOMINMAX
			_CRT_SECURE_NO_WARNINGS
			WIN32_LEAN_AND_MEAN
			MY_LIBRARY_PLATFORM_WINDOWS
	)

	if(MSVC)
		target_compile_options(MyLibrary
			PUBLIC

			PRIVATE
				/Zc:__cplusplus
		)
	elseif(MINGW)
		target_link_libraries(MyLibrary
			PUBLIC

			PRIVATE
				m
		)
		target_link_options(MyLibrary
			PUBLIC

			PRIVATE
				-static
				-static-libgcc
				-static-libstdc++
		)
	elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
		target_link_libraries(MyLibrary
			PUBLIC

			PRIVATE
		)
		target_link_options(MyLibrary
			PUBLIC

			PRIVATE
				-static
		)
	endif()

endif()

if(CMAKE_SYSTEM_NAME STREQUAL "Linux")

	target_compile_definitions(MyLibrary
		PUBLIC

		PRIVATE
			MY_LIBRARY_PLATFORM_LINUX
	)

	if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
		target_link_libraries(MyLibrary
			PUBLIC

			PRIVATE
				dl
				m
				pthread
		)
		target_link_options(MyLibrary
			PUBLIC

			PRIVATE
				-static
				-static-libgcc
				-static-libstdc++
		)
	elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
		target_link_libraries(MyLibrary
			PUBLIC

			PRIVATE
		)
		target_link_options(MyLibrary
			PUBLIC

			PRIVATE
				-static
		)
	endif()

endif()

if(CMAKE_SYSTEM_NAME STREQUAL "Darwin")

	target_compile_definitions(MyLibrary
		PUBLIC

		PRIVATE
			MY_LIBRARY_PLATFORM_OSX
	)

endif()

# bCONFIGURATION SPECIFIC

target_compile_definitions(MyLibrary
	PUBLIC

	PRIVATE
		$<$<CONFIG:Debug>:MY_LIBRARY_DEBUG_BUILD>
		$<$<CONFIG:Debug>:DEBUG>

		$<$<CONFIG:Profile>:MY_LIBRARY_PROFILE_BUILD>
		$<$<CONFIG:Profile>:NDEBUG>

		$<$<CONFIG:Release>:MY_LIBRARY_RELEASE_BUILD>
		$<$<CONFIG:Release>:NDEBUG>
)
