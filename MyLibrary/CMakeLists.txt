file(GLOB_RECURSE LIBRARY_SRC CONFIGURE_DEPENDS "*.h" "*.c" "*.hpp" "*.cpp")

add_library(MyLibrary
	${LIBRARY_SRC}
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
		${PROJECT_SOURCE_DIR}/MyLibrary/src
	PRIVATE
		
)

target_compile_definitions(MyLibrary
	PUBLIC
		
	PRIVATE
		MY_LIBRARY
)

if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
	target_compile_definitions(MyLibrary
		PUBLIC
			
		PRIVATE
			NOMINMAX
			_CRT_SECURE_NO_WARNINGS
			WIN32_LEAN_AND_MEAN
			LIB_WINDOWS
	)
	if (MSVC)
		target_compile_options(MyLibrary
			PUBLIC
				
			PRIVATE
				/Zc:__cplusplus
		)
	elseif (MINGW)
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
		PRIVATE
		LIB_LINUX
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
			LIB_OSX
	)
endif()

if(CMAKE_BUILD_TYPE STREQUAL Debug)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS_DEBUG}" CACHE STRING "CXX flags" FORCE)
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS_DEBUG}" CACHE STRING "C flags" FORCE)
	set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS_DEBUG}" CACHE STRING "Linker flags" FORCE)
	target_compile_definitions(MyLibrary
		PUBLIC
				
		PRIVATE
			LIB_DEBUG
			DEBUG
	)
endif()

if(CMAKE_BUILD_TYPE STREQUAL Release)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS_RELEASE}" CACHE STRING "CXX flags" FORCE)
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS_RELEASE}" CACHE STRING "C flags" FORCE)
	set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS_RELEASE}" CACHE STRING "Linker flags" FORCE)
	target_compile_definitions(MyLibrary
		PUBLIC
				
		PRIVATE
			LIB_RELEASE
			NDEBUG
	)
endif()

if(CMAKE_BUILD_TYPE STREQUAL Dist)
	remove_definitions(-DLIB_RELEASE)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS_RELEASE}" CACHE STRING "CXX flags" FORCE)
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS_RELEASE}" CACHE STRING "C flags" FORCE)
	set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS_RELEASE}" CACHE STRING "Linker flags" FORCE)

	target_compile_definitions(MyLibrary
		PUBLIC
				
		PRIVATE
			LIB_DIST
			NDEBUG
	)
endif()