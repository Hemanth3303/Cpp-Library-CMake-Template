#include "Library.hpp"

int main(int argc, char** argv) {
	Logger::LogMessage("Hello, World\n------------------------------");

#if defined(SANDBOX_APP_DEBUG_BUILD)
	std::cout << "SANDBOX_APP: Debug Build\n";
#elif defined(SANDBOX_APP_PROFILE_BUILD)
	std::cout << "SANDBOX_APP: Profile Build\n";
#elif defined(SANDBOX_APP_RELEASE_BUILD)
	std::cout << "SANDBOX_APP: Release Build\n";
#else
	std::cout << "SANDBOX_APP: Unknown Build\n";
#endif

	std::cout << "PLATFORM: ";
#if defined(SANDBOX_APP_PLATFORM_WINDOWS)
	std::cout << "Windows";
#elif defined(SANDBOX_APP_PLATFORM_LINUX)
	std::cout << "Linux";
#elif defined(SANDBOX_APP_PLATFORM_DARWIN)
	std::cout << "Darwin";
#elif defined(SANDBOX_APP_PLATFORM_UNKNOWN)
	std::cout << "Unknown";
#else
	std::cout << "Unknown";
#endif
	std::cout << "\n";

	std::cout << "ARCHITECTURE: ";
#if defined(SANDBOX_APP_ARCHITECTURE_X86_64)
	std::cout << "x86-64";
#elif defined(SANDBOX_APP_ARCHITECTURE_X86_32)
	std::cout << "x86-32";
#elif defined(SANDBOX_APP_ARCHITECTURE_AARCH64)
	std::cout << "aarch64";
#elif defined(SANDBOX_APP_ARCHITECTURE_AARCH32)
	std::cout << "aarch32";
#elif defined(SANDBOX_APP_ARCHITECTURE_RISCV64)
	std::cout << "riscv64";
#elif defined(SANDBOX_APP_ARCHITECTURE_RISCV32)
	std::cout << "riscv32";
#elif defined(SANDBOX_APP_ARCHITECTURE_UNKNOWN)
	std::cout << "unknown";
#else
	std::cout << "unknown";
#endif
	std::cout << "\n------------------------------\n";
	std::cout << "Press Enter to exit...";

	std::cin.get();
	return 0;
}
