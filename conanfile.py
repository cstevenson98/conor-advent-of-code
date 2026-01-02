from conan import ConanFile
from conan.tools.cmake import CMake, CMakeToolchain, CMakeDeps


class AdventOfCodeConan(ConanFile):
    name = "conor-advent-of-code"
    version = "1.0.0"
    settings = "os", "compiler", "build_type", "arch"
    exports_sources = "CMakeLists.txt", "src/*"

    def requirements(self):
        self.requires("gtest/1.15.0")
        # Import the cpp-cli library from local path
        # This will be used once cpp-cli is installed to conan cache
        # For now, we'll use it as a CMake dependency

    def layout(self):
        build_type = str(self.settings.build_type)
        self.folders.build = f"build/{build_type}"
        self.folders.generators = f"build/{build_type}/generators"

    def generate(self):
        deps = CMakeDeps(self)
        deps.generate()
        tc = CMakeToolchain(self)
        tc.variables["CMAKE_EXPORT_COMPILE_COMMANDS"] = "ON"
        # Add path to cpp-cli for find_package
        tc.variables["cpp-cli_DIR"] = "/home/conor/dev/cpp-cli/build/Debug"
        tc.generate()

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

