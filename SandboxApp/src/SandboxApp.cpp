#include "Library.hpp"

#include <iostream>

void printConfigInfo();
void printArchitectureInfo();
void printOSInfo();
void printCompilerInfo();

int main(int argc, char **argv) {
	Logger::LogMessage("Hello World!");

	printConfigInfo();
	printOSInfo();
	printArchitectureInfo();
	printCompilerInfo();

    std::cout << "Press Enter Key To Exit...";
    std::cin.get();

    return 0;
}

void printConfigInfo() {
#if defined(SANDBOX_APP_DEBUG_BUILD)
    std::cout << "SANDBOX_APP: Debug Build\n";
#elif defined(SANDBOX_APP_PROFILE_BUILD)
    std::cout << "SANDBOX_APP: Profile Build\n";
#elif defined(SANDBOX_APP_RELEASE_BUILD)
    std::cout << "SANDBOX_APP: Release Build\n";
#else
    std::cout << "SANDBOX_APP: Unknown Build\n";
#endif
}

void printArchitectureInfo() {
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
    std::cout << "\n";
}

void printOSInfo() {
    std::cout << "OS: ";
#if defined(SANDBOX_APP_OS_WINDOWS)
    std::cout << "Windows";
#elif defined(SANDBOX_APP_OS_LINUX)
    std::cout << "Linux";
#elif defined(SANDBOX_APP_OS_DARWIN)
    std::cout << "Darwin";
#elif defined(SANDBOX_APP_OS_FREEBSD)
    std::cout << "FreeBSD";
#elif defined(SANDBOX_APP_OS_OPENBSD)
    std::cout << "OpenBSD";
#elif defined(SANDBOX_APP_OS_NETBSD)
    std::cout << "NetBSD";
#elif defined(SANDBOX_APP_OS_ANDROID)
    std::cout << "Android";
#elif defined(SANDBOX_APP_OS_EMSCRIPTEN)
    std::cout << "Emscripten WebAssembly";
#elif defined(SANDBOX_APP_OS_IOS)
    std::cout << "iOS";
#elif defined(SANDBOX_APP_OS_UNKNOWN)
    std::cout << "Unknown";
#else
    std::cout << "Unknown";
#endif
    std::cout << "\n";
}

void printCompilerInfo() {
    std::cout << "COMPILER: ";
#if defined(SANDBOX_APP_COMPILER_GNU_GCC)
    std::cout << "GNU GCC";
#elif defined(SANDBOX_APP_COMPILER_MINGW_W64_GCC)
    std::cout << "MinGW-w64 GCC";
#elif defined(SANDBOX_APP_COMPILER_MINGW32_GCC)
    std::cout << "MinGW32";
#elif defined(SANDBOX_APP_COMPILER_LLVM_CLANG)
    std::cout << "LLVM Clang";
#elif defined(SANDBOX_APP_COMPILER_CLANG_CL)
    std::cout << "Clang-cl";
#elif defined(SANDBOX_APP_COMPILER_MSVC)
    std::cout << "MSVC";
#elif defined(SANDBOX_APP_COMPILER_APPLE_CLANG)
    std::cout << "AppleClang";
#elif defined(SANDBOX_APP_COMPILER_MINGW_W64_GCC)
    std::cout << "unknown";
#else
    std::cout << "unknown";
#endif
    std::cout << "\n";
}
