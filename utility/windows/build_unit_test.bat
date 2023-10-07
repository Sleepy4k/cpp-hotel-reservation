@echo off

:: Script to compile and run a C++ program with g++
echo Compiling C++ program with g++

:: Source file name (change this to your C++ source file)
set source_file=../../tests/main_test.cpp

:: Output binary name (change this to your desired output name)
set output_binary=../../output/main_test.exe

:: Compile the C++ program
g++ -std=c++11 -o "%output_binary%" "%source_file%"

:: Check if compilation was successful
if %errorlevel% equ 0 (
  :: Run the compiled binary
  echo Compilation successful. Running %output_binary%
  "%output_binary%"
) else (
  echo Compilation failed.
)

:: Pause to keep the console window open (optional)
pause