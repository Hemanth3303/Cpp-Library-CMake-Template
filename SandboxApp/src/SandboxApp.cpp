#include "Library.hpp"

int main(int argc, char** argv) {
	Logger::LogMessage("Hello, World");

#if defined(SANDBOX_APP_DEBUG_BUILD)
	std::cout << "Debug Build\n";
#elif defined(SANDBOX_APP_PROFILE_BUILD)
	std::cout << "Profile Build\n";
#elif defined(SANDBOX_APP_RELEASE_BUILD)
	std::cout << "Release Build\n";
#else

#endif

	std::cin.get();
	return 0;
}