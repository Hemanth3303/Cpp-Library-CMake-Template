#include "Library.hpp"

void myLibraryPrintConfigInfo();
void myLibraryPrintArchitectureInfo();
void myLibraryPrintOSInfo();
void myLibraryPrintCompilerInfo();

void Logger::LogMessage(const std::string& message) {
	std::cout << message << "\n";
	myLibraryPrintConfigInfo();
	myLibraryPrintOSInfo();
	myLibraryPrintArchitectureInfo();
	myLibraryPrintCompilerInfo();
}


void myLibraryPrintConfigInfo() {
#if defined(MY_LIBRARY_DEBUG_BUILD)
    std::cout << "MY_LIBRARY: Debug Build\n";
#elif defined(MY_LIBRARY_PROFILE_BUILD)
    std::cout << "MY_LIBRARY: Profile Build\n";
#elif defined(MY_LIBRARY_RELEASE_BUILD)
    std::cout << "MY_LIBRARY: Release Build\n";
#else
    std::cout << "MY_LIBRARY: Unknown Build\n";
#endif
}

void myLibraryPrintArchitectureInfo() {
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
    std::cout << "\n";
}

void myLibraryPrintOSInfo() {
    std::cout << "OS: ";
#if defined(MY_LIBRARY_OS_WINDOWS)
    std::cout << "Windows";
#elif defined(MY_LIBRARY_OS_LINUX)
    std::cout << "Linux";
#elif defined(MY_LIBRARY_OS_DARWIN)
    std::cout << "Darwin";
#elif defined(MY_LIBRARY_OS_FREEBSD)
    std::cout << "FreeBSD";
#elif defined(MY_LIBRARY_OS_OPENBSD)
    std::cout << "OpenBSD";
#elif defined(MY_LIBRARY_OS_NETBSD)
    std::cout << "NetBSD";
#elif defined(MY_LIBRARY_OS_ANDROID)
    std::cout << "Android";
#elif defined(MY_LIBRARY_OS_EMSCRIPTEN)
    std::cout << "Emscripten WebAssembly";
#elif defined(MY_LIBRARY_OS_IOS)
    std::cout << "iOS";
#elif defined(MY_LIBRARY_OS_UNKNOWN)
    std::cout << "Unknown";
#else
    std::cout << "Unknown";
#endif
    std::cout << "\n";
}

void myLibraryPrintCompilerInfo() {
    std::cout << "COMPILER: ";
#if defined(MY_LIBRARY_COMPILER_GNU_GCC)
    std::cout << "GNU GCC";
#elif defined(MY_LIBRARY_COMPILER_MINGW_W64_GCC)
    std::cout << "MinGW-w64 GCC";
#elif defined(MY_LIBRARY_COMPILER_MINGW32_GCC)
    std::cout << "MinGW32";
#elif defined(MY_LIBRARY_COMPILER_LLVM_CLANG)
    std::cout << "LLVM Clang";
#elif defined(MY_LIBRARY_COMPILER_CLANG_CL)
    std::cout << "Clang-cl";
#elif defined(MY_LIBRARY_COMPILER_MSVC)
    std::cout << "MSVC";
#elif defined(MY_LIBRARY_COMPILER_APPLE_CLANG)
    std::cout << "AppleClang";
#elif defined(MY_LIBRARY_COMPILER_MINGW_W64_GCC)
    std::cout << "unknown";
#else
    std::cout << "unknown";
#endif
    std::cout << "\n";
}
