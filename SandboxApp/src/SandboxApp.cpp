#include "Library.hpp"

int main(int argc, char** argv) {
	Logger::LogMessage("Hello, World");
#if defined(APP_DEBUG)
	std::cout << "Debug Build Sandbox\n";
#elif defined(APP_RELEASE)
	std::cout << "Release Build Sandbox\n";
#elif defined(APP_DIST)
	std::cout << "Distribution Build Sandbox\n";
#else

#endif
	std::cin.get();
	return 0;
}