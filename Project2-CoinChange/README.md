To Compile Program
==================
Run `make` in the project root. You can change what algorithm gets run by setting the `ALGO` definition in src/main.cpp.
Proper values are integers 1, 2, and 3 for ChangeSlow, ChangeGreedy, and ChangeDynamic respectively.

To Run Program
===============
`./main -h` will print out help

`./main filename.txt` will attempt to read in a file and write results to filenamechange.txt. No attempt was made on
our part to ensure files are in the proper format, as that was not part of the defined specs. We do check to make sure
the file exists.
