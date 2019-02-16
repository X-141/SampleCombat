# SampleCombat
Simple implementation of a turnbased combat system that is reserved as mostly sample code
for performing basic program development.

# Requirements
1. C/C++ compilier -> 
  * Linux gcc/g++ v8.2.1 tested -> working
  * MacOS AppleClang v10.0.0 tested -> working
  * Windows MingW gcc/g++ v6.3.0 tested -> working
2. Make -> minimum version tested 3.81
3. Cmake -> minimum required 3.12

# How to Compile
Windows w/ Mingw
1. Make a build directory -> "mkdir build"
1. in the project directory -> "cd build"
2. compile using cmake -> "cmake -G "Unix Makefiles" .."
3. after compilation finishes -> "make"
4. A windows executable named "SampleFigher.exe" should've been created
5. "./Run"

Linux/Unix
1. Make a build directory -> "mkdir build"
1. in the project directory -> "cd build"
2. compile using cmake -> "cmake .."
3. after compilation finishes -> "make"
4. executable file named "SampleFighter" should've been created
5. "./Run"
