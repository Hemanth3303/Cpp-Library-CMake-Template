#include "Library.hpp"

void Logger::LogMessage(const std::string& message) {
	std::cout << message << "\n";

#if defined(LIB_DEBUG)
	std::cout << "Debug Build Library\n";
#elif defined(LIB_RELEASE)
	std::cout << "Release Build Library\n";
#elif defined(LIB_DIST)
	std::cout << "Distribution Build Library\n";
#else

#endif
}
