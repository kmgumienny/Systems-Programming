Kamil Gumienny - kmgumienny

This program accepts input text and counts the amount of times any word in the text is used. 

	main

* main creates the root treeItem and checks to make sure the right parameters have
* been entered. It then loops the rest of the code for as many input files as there
* are. Finally it prints the tree, and then clears it.

	addItem

 * The function addItem takes a tree and a character
 * if first checks to see if the tree is null, which it
 * will be the first time the function is ran and every
 * other time when there is a word it has never seen
 * before. If the treeItem is not null, it will compare
 * the word w to the word stored in p. If the function
 * strcmp returns 0, the function has seen the word before
 * and adds a count to that words leaf. If strcmp returns
 * returns <0, this function will run again with the leaf
 * stored to the left of that leaf, otherwise it will run
 * the function again and check the right leaf.

	printTree

 * the function prints recursively by first navigating to the leftmost
 * leaf and printing it's contents, and then printing the right one.
 * if a leaf doesn't exist, the function goes back one generation and tries
 * printing again until all the printing is done.

	clearTree

 * clearTree goes through every leaf in a tree in a recursive manner,
 * exactly like the printTree method, navigating to the leftmost
 * leaf in the BST and removing it from memory.


	checkIsWord

 * the function goes through all the characters in
 * a char array and checks to see if there is at least
 * one letter inside.
 * int isWord acts like a boolean where if it is a 1,
 * it implies true and 0 if false.
 * loop invariant is i is always greater than 0 and always
 * less than the size of the char array word.

	toLowerCase

 * Function goes through all the characters in an array
 * and makes all the characters lower case in the char
 * array.
 * int i is used as an index that is later used to insert a
 * EOF character into the string.
 * loop invariant is i is always greater than 0 and always
 * less than the size of the char array word.


	removeALetter

 * function takes a char array and an index name counter.
 * It navigates to the indexed number in the array and moves
 * the character after it, into it's spot and continues until
 * there are no more characters to move.
 * the loop invariant is that counter will never be greater than
 * largest index in the char c

	isLetter

 * function looks at a character and checks to see if it is
 * a letter in the alphabet

	copyWord

 * function goes though two char arrays and copies the content
 * in char array c from starting index to one less than the end
 * index to char array aWord.
 * int i and x are index arrays used in the for loop
 * the loop invariant is that x and i are always int start
 * number apart and x is never greater than int end

	WordConditioning

 * function takes two char arrays and a start and end index
 * first it copies char array c to char array aWord from the
 * start to end index. Then, the resulting aWord array is checked
 * to see if it has any letters inside of it. If it does, the function
 * looks at the array of chars and sees if there is anything in the front
 * of the array, aside from an apostrophe and a dash and removes it.
 * It is also looks at the end of an array and removes anything that isn't
 * a letter from the end. Lastly, it takes the aWord char array and makes all
 * the letters lowercase.
 * int i is the index for the start of the char array.
 * int endIndex is the last index of the char array.
 * the loop invariant the loop is that the loop will continue
 * until there are no more characters in the loop


	readAFile

 * function takes the location of a file and opens it. The function then
 * looks at how long the file is and creates a char array that can store all
 * the values in the txt file in the array. The array is then traversed and
 * all characters are pulled out until a space, tab, new line, etc... case is
 * encountered. The string is then sent to the WordConditioning function
 * along with another char array that was malloced to be able to hold all the
 * characters between the last line break and the one it is at.
 * int counterStart and counterEnd are indexes for when a new string of characters
 * starts and ends.
 * int boolLetter is used to check whether the current string should be sent to
 * WordConditioning, just in case the text file has a break between words with 2 dashes.
 * int letter is used to store the value of the current character in the string.
 * int actualWord acts as a boolean to see whether a string should be sent to
 * WordConditioning.
 * char Current is the current character in the text file.
 * char* word and currentWord are char array.
 * The loop invariant is that the loop will continue as long as there are more characters
 * in the text file.


*****************

I used stackoverflow.com and tutorialspoint.com as references for my code whenever I had a problem.

PROBLEMS I HAD

For the life of me, I could not figure out why some words print out with random characters after them. It has to do with memory allocation but no matter where I tried to insert an EOF character, I would always get a few problematic results. I could not fix them so I left them alone before messing up more of the code, which would have probably been inevitable if I kept messing with it. I would appreciate it it you, the grader, could leave a comment letting me know where the error occurred.
