# Change directory to the build folder
cd build

# Run CMake
cmake ..

# Build the project using MSBuild
msbuild G4_Brems.sln

# Change directory to the release folder
cd release

# Run the executable
.\G4_Brems

# Go back to the root directory
cd ..
cd ..