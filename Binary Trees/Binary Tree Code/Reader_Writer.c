/*
 * Reader_Writer.c -- Kamil Gumienny
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ReadWrite.h"
#include "BSTH.h"


/*
 * the function goes through all the characters in
 * a char array and checks to see if there is at least
 * one letter inside.
 * int isWord acts like a boolean where if it is a 1,
 * it implies true and 0 if false.
 * loop invariant is i is always greater than 0 and always
 * less than the size of the char array word.
 */
int checkIsWord(char* word){
	int isWord = 0;
	//loop invariant is i is always greater than 0 and always
	// less than the size of the char array word.
	for(int i = 0; word[i]; i++){
		if(isLetter(word[i])){
			isWord=1;
		}
	}
	return isWord;
}
/*
 * Function goes through all the characters in an array
 * and makes all the characters lower case in the char
 * array.
 * int i is used as an index that is later used to insert a
 * EOF character into the string.
 * loop invariant is i is always greater than 0 and always
 * less than the size of the char array word.
 */

void toLowerCase(char* c){
	int i = 0;
	//loop invariant is i is always greater than 0 and always
	//less than the size of the char array word.
	for(; isLetter(c[i]); i++){
		if(i ==0)
			c[i] = tolower(c[i]);
	}
	c[i+1] = '\0';

}

/*
 * function takes a char array and an index name counter.
 * It navigates to the indexed number in the array and moves
 * the character after it, into it's spot and continues until
 * there are no more characters to move.
 * the loop invariant is that counter will never be greater than
 * largest index in the char c
 */

void removeALetter(char* c, int counter){
	//the loop invariant is that counter will never be greater than
	// largest index in the char c
	while (c[counter]) {
			c[counter] = c[counter + 1];
			counter++;
	}
}

/*
 * function looks at a character and checks to see if it is
 * a letter in the alphabet
 */

int isLetter(char c){
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return 1;
	return 0;
}

/*
 * function goes though two char arrays and copies the content
 * in char array c from starting index to one less than the end
 * index to char array aWord.
 * int i and x are index arrays used in the for loop
 * the loop invariant is that x and i are always int start
 * number apart and x is never greater than int end
 *
 */

void copyWord(char* c, char* aWord, int start, int end){
	int i = 0;
	int x = start;
	//the loop invariant is that x and i are always int start
	// number apart and x is never greater than int end.
	while (c[x] && x < end){
		aWord[i] = c[x];
		i++;
		x++;
	}
}


/*
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
 */
int WordConditioning(char* c, char* aWord, int start, int end) {
	int i = start;
	int endIndex = (end - start) - 1;
	copyWord(c, aWord, start, end);
	if (checkIsWord(aWord) == 1) {

		//the loop invariant the loop is that the loop will continue
		// until there are no more characters in the loop
		for (i = 0; aWord[i]; i++) {
			if (isLetter(aWord[i]) == 0 && i == 0) {
				if (!((aWord[i] == '-' && isLetter(aWord[i+1])) || aWord[i] == '\'')){
					removeALetter(aWord, i);
					i = 0;
				}
			}
			if (isLetter(aWord[i]) == 0 && i == endIndex) {
				removeALetter(aWord, i);
				aWord[i] = '\0';
				endIndex--;
				i = 0;
			}
		}
		toLowerCase(aWord);
		return 1;
	}
	else
		return 0;
}

/*
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
 */
treeItem *readAFile(char* fileSource, treeItem *p){
	int counterStart = 0, counterEnd=0, boolLetter = 0, letter, actualWord = 0;
	char current;
	char* word;
	FILE *input;
	input = fopen(fileSource, "r");
	if (!input) {
		printf("Unable to open file");
		exit(0);
	}

	fseek(input, 0, SEEK_END);
	long inputSize = ftell(input);
	char currentWord[inputSize + 2];
	rewind(input);

	//The loop invariant is that the loop will continue as long as there are more characters
	// in the text file.
	while ((current = fgetc(input)) != EOF) {
		letter = current;
			if (!(letter == ' ' || letter == '\n' || letter == '\t' ||
					letter == '\v' || letter == '\r' ||
					letter == '\f')) {
				currentWord[counterEnd] = current;
				counterEnd++;
				boolLetter=1;
			}
			else if (boolLetter) {
			word = malloc((counterEnd - counterStart) * sizeof(char *));
			actualWord = WordConditioning(currentWord, word, counterStart,
					counterEnd);
			if (actualWord == 1)
				p = addItem(p, word);
			free(word);
			if(counterEnd > 500){
				counterEnd=0;
				memset(currentWord, 0, inputSize);
			}
			counterStart = counterEnd;
			boolLetter = 0;

		}
	}
	fclose(input);
	return p;

}
