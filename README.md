# Advent of Code 2017

This repository represents my personal solutions for the 'Advent Of Code 2017' challenges.

The solutions are numbered by day, with a title describing the challenge itself. I use CMake to compile and tests everything (the building system has been taken from [here](https://github.com/snikulov/google-test-examples)

# Solved challenges
1. Circular Sum
1.  
1. 
1.  
1. 
1.  
1. 
1.  
1. 
1. 
1.  
1. 
1.  
1. 
1. 
1.  
1. 
1.  
1. 
1. 
1.  
1. 
1.  
1. 
1. 

## Running
To run all tests, just do
```bash
cmake -P build.cmake
```
A version of google test is download, compiled and linked so the unittest can be tested.

I added a coverage call. While it is not absolutely necessary, I did just for fun and for future (self) reference.
To call it just do
```bash
cmake -P gcov.cmake
```

## Requirements
- cmake (>= 2.8)
- Google Test

## Optional
I used Visual Studio Code with ```clang-format``` to format the code