# SyntaxChecker-Fall2019
Kaitlyn Abdo CPSC 350 - 03 Professor Rene German Chapman University

How to run: make realclean make all

Shortcomings: The program does not use the destructor because of this error:
*** Error in `./a.out': double free or corruption (!prev): 0x000055fb3741dc20 ***
I am sorry

The program: Checks the syntax for delimeters: {}, [], and (). If an error is detected, it displays the error at the line and terminates. If no error is found, it asks if the user wants to check a new file, it asks for file path. If not, it terminates the program
