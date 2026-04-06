#include "Library.hpp"

void Logger::LogMessage(const std::string& message) {
	std::cout << message << "\n";

#if defined(MY_LIBRARY_DEBUG_BUILD)
	std::cout << "Debug Build Library\n";
#elif defined(MY_LIBRARY_PROFILE_BUILD)
	std::cout << "Profile Build Library\n";
#elif defined(MY_LIBRARY_RELEASE_BUILD)
	std::cout << "Release Build Library\n";
#else

#endif
}
