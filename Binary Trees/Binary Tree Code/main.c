/*
 * main.c -- Kamil Gumienny
 */
#include <stdio.h>
#include <stdlib.h>
#include "ReadWrite.h"
#include "BSTH.h"

/*
 * main creates the root treeItem and checks to make sure the right parameters have
 * been entered. It then loops the rest of the code for as many input files as there
 * are. Finally it prints the tree, and then clears it.
 */
int main(int argc, char **argv) {

	treeItem *root = NULL;
	if(argc < 3){
		printf("Missing either output file or input text file");
		return 1;
	}

	for (int i = 2; i < argc; i++) {
		// the loop invariant is i is always < argc
		// and always greater than 2.
		root = readAFile(argv[i], root);
	}
	FILE *input;
	input = fopen(argv[1], "w+");
	printTree(root, input);
	fclose(input);
	clearTree(root);
	return 1;
}
