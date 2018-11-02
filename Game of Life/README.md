This project goes over creating a game in the terminal value while learning about concepts such as avoiding outofbounds exceptions, using malloc to allocate space, and accepting user input.

	int main(int argc, char **argv)


Main initialized integers width, height, gens, print, and pause to store the variables
in argv.
char c is a char that is used with pause. It the parameter pause is used, a scanf function
will wait for input and store it in c before going on to the next generation. c is never used
for anything other than that
integers booleanSame and booleanEmpty are used when testing between generations. A function
assigns either a 1 or a 0 to them. If they are 1, the program stops. Otherwise, nothing happens.
There is a for loop in the main function with an invariant of c being > 0 and < number of gens.

	void allocateSpaceA(char **A, int width, int height)
	void allocateSpaceB(char **B, int width, int height)
	void allocateSpaceC(char **C, int width, int height)


The functions allocates space in the heap for three 2D arrays by making pointers to pointers named A, B, and C. The original pointers are initizalized in the main function and these
functions only initialize space for the amount of columns.
They each have a loop and the invariant is  i >= 0 & i < height. Will run *height* number of times

	void readAFile(char* fileSource, char** A, int width, int height)


function goes through the input file, determines the longest line and centers the array, if
necessary, and then prints to the array. It also declares the FILE variables and rewinds it
after every time it has been traversed.
int fileWidth and fileHeight are integers that store how wide and how tall the information in the
txt file is.
int startAtWidth and startAtHeight are used for centering the array after finding out how long
the source file width and height.
FILE *sourcefile is the variable for the txt.file


	int getFileDimensions(FILE *input, int x)


this function goes though the file that has been provided by the user and gets the size
of the longest row and the amount of columns in the file using a while loop
int height and width counter are used in the for loops and increment heightCounter every time
there is a new line and widthCounter every time there is another variable in a line
int longestRow keeps track of what the longest row was and returns that instead of widthCounter.
The loop invariant is that the loop will continue until it reaches the end-of-file variable
**** the function takes in an extra parameter int booleanX that determines whether to return
the height or width. I tried returning both values at once but got an error, even after
mallocing space for that 2D array.


	void FillArray(FILE *input, char **A, int startAtWidth, int startAtHeight,
		int endAtWidth, int endAtHeight, int width, int height)


originally fills the entire Malloc'd array with "o" characters, then centerers the input file.
It goes to the starting position for the height and width and continues to read the starting
document until it reaches both end width and end height.
int num[1000] is an array with 1000 slots that stores the contents of the input file
int currCharacter is an integer that stores the value of the current character in the text file
until end of file is reached.
int counter and counter2 are integers that are used as counters inside of nested for loops.
The first loop invariant is i >= 1 and <1000. Continues until EOF is reached unless input file
is >1000 characters
The second two loops both have invariants of i >= 0 & i < height and j >= 0 & j < width


	void switchBoards(char **new, char **old, int width, int height)


this function takes in two 2D arrays and switches the contents from the old array to the new
array by using a nested for loop.
The loop invariants are i >= 0 & i < height and j >= 0 & j < width


	int checkSameArrays(char **A, char **C, int width, int height)


This function goes through an array by using a nested for loop and checks the current
generation's board to the old generation's board to see if there is a loop. As soon as there
is one difference between the two arrays, it returns 0. Otherwise it returns a 1.
The loop invariants are i >= 0 & i < height and j >= 0 & j < width


	int checkEmpty(char **A, int width, int height)


This function goes through the current generation array and checks every cell in the array
to see if there is an 'x'. If there is the function returns 0. Otherwise, it returns a 1.
The loop invariants are i >= 0 & i < height and j >= 0 & j < width


	void PlayOnce(int width, int height, char** Old, char** New)


PlayOne is a function that cycles through the New 2D array by using two nested for loops
and for every space in the array, calls the function countNeighbors with the old array to
determine how many neighbors a cell has and then either places an 'x' or an 'o' depending
on how many neighbors the old array had
The loop invariants are i >= 0 & i < height and j >= 0 & j < width


	int countNeighbors(char** Old, int i, int j, int width, int height)


the function looks at the cell, determines if it is inhabited ('x' for inhabited, 'o' for empty)
and then passes it along to NeighborCheck to see how many neighbors it has.  If there are
0,1,4,5,6,7, or 8 neighbors and the cell is inhabited, the function returns an 'o'. If the cell
is not inhabited and has 3 neighbors, the function returns an 'x'. If the cell is inhabited and
has 2 or 3 neighbors, an 'x' is returned.
int numberNeighbors stores the amount of 'x's around the cell being looked at.


	int NeighborCheck(char **Old, int i, int j, int width, int height)


looks at the neighbors of the given cell and determines how many surround that block in the 2D
array.  Conditions for when the block being checked is on the edge of the board;
int counter stores the amount of times an 'x' is spotted around a cell.


	void printArrays(int width, int height, char** anArray)


a method that prints the contents of a 2D array by looking at every element and printing a space
if the spot holds an 'o' and and 'x' if the array holds an x
The loop invariants are i >= 0 & i < height and j >= 0 & j < width




The two main sources that I used for information were stackoverflow.com and tutorialspoint.com to
summarize how to use standard library functions and to search for functions.
I struggled with mallocing space for the three 2D arrays so I visited
www.eskimo.com/~scs/cclass/int/sx9b.html
and learned how to make 2D arrays by looking at their diagrams. First you
malloc a 1D array to account for all the rows and then you run a forloop
that mallocs column sizes.
