To Compile Program
==================
Simply run `make` in the project root.
You can optionally set the RUN_TESTS macro to 1 and recompile in order to run our timing tests.

To Run Program
==============
Simply run `./main`

The program expects MSS_TestProblems.txt to be in the same directory as the executable. It will gracefully exit if this file is not found.

Program Output
==============
The program will output a MSS_TestResults.txt file that will contain output for each algorithm as defined in the spec.
