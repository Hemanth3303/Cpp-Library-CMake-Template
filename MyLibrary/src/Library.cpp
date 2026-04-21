#include "Library.hpp"

void Logger::LogMessage(const std::string& message) {
	std::cout << message << "\n";

#if defined(MY_LIBRARY_DEBUG_BUILD)
	std::cout << "MY_LIBRARY: Debug Build\n";
#elif defined(MY_LIBRARY_PROFILE_BUILD)
	std::cout << "MY_LIBRARY: Profile Build\n";
#elif defined(MY_LIBRARY_RELEASE_BUILD)
	std::cout << "MY_LIBRARY: Release Build\n";
#else
	std::cout << "MY_LIBRARY: Unknown Build\n";
#endif

	std::cout << "PLATFORM: ";
#if defined(MY_LIBRARY_PLATFORM_WINDOWS)
	std::cout << "Windows";
#elif defined(MY_LIBRARY_PLATFORM_LINUX)
	std::cout << "Linux";
#elif defined(MY_LIBRARY_PLATFORM_DARWIN)
	std::cout << "Darwin";
#elif defined(MY_LIBRARY_PLATFORM_UNKNOWN)
	std::cout << "Unknown";
#else
	std::cout << "Unknown";
#endif
	std::cout << "\n";

	std::cout << "ARCHITECTURE: ";
#if defined(MY_LIBRARY_ARCHITECTURE_X86_64)
	std::cout << "x86-64";
#elif defined(MY_LIBRARY_ARCHITECTURE_X86_32)
	std::cout << "x86-32";
#elif defined(MY_LIBRARY_ARCHITECTURE_AARCH64)
	std::cout << "aarch64";
#elif defined(MY_LIBRARY_ARCHITECTURE_AARCH32)
	std::cout << "aarch32";
#elif defined(MY_LIBRARY_ARCHITECTURE_RISCV64)
	std::cout << "riscv64";
#elif defined(MY_LIBRARY_ARCHITECTURE_RISCV32)
	std::cout << "riscv32";
#elif defined(MY_LIBRARY_ARCHITECTURE_UNKNOWN)
	std::cout << "unknown";
#else
	std::cout << "unknown";
#endif
	std::cout << "\n------------------------------\n";
}
