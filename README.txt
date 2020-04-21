Kyle McLain Kane (cssc1950), CS530 Spring 2020
Assignment #1, program to print the contents of a regular file in hexadecimal or binary format. Also a program
to convert regular files like txt, jpeg, and executable to human readable format.
 
FILE MANIFEST
	- dbx.cpp
	- README.txt
	- makefile

COMPILE CONSTRUCTIONS:
make 						(NOTE: has to be done in the file the code is in, with the makefile and .cpp file)

OPERATING INSTRUCTIONS(Options for either hex or binary):
dbx <filename> 					(NOTE: this is for Hexadecimal)
dbx -b <filename> 				(NOTE: this is for Binary)
make clean					(NOTE: removes the dbx file created)

Significant design features:
In this program I choose to have 2 arrays, one of char and another one of the respective converted values. I also
read this into a string and then split up that string into element by element after checking whether or not
they can be printed. 

Extra design features:
- I did the math for the blank space offset for both the Binary and Hex, (above its respective print is the very 
  long equation)
- I checked to make sure that the file had opened properly and a file had been named
- I replace unreadable char not between ASCII 32-126 with a .

All known deficiencies or bugs:
- None at the moment

Lessons learned
- Learned more about C++
- Learned more about the ASCII table
- Learned about xxd
- Learned more about how to print with blankspace with setw()
- Learned alot about ostringstream
- Learned some about using Bitset in c++
- Learned a bit more regarding comparisons (especially in c++)
- Learned how a makefile works/is coded

EXPLANATION OF PROCESS:
So for this, what I would do is I would read in the file into a string, and then using said string I would 
start to place each character in its own element within its own array. But first I would need to check whether or 
not the character is printable/readable, If not, I would replace that character with a '.'. Once I have gotten all values into their
respective place, I would then check for whether the user put -b into the terminal to begin the binary conversion,
or to do the Hexadecimal conversion. Once I have that done I would then either call bC (binary conversion) or hexC
(hexadecimal conversion). One in the respective places I used the ostringstream to convert then into either hex
or binary, then I would store that conversion into a new array that would store the converted values. After the
conversion, I would then go on to their own respective print functions. Each was different since they needed
different spacing, Hex wanted to have 16 bytes on one line while binary wanted 6 bytes on one line, also it is
important to note that the text does and has to match the line it is on.