/*
 * BST.c -- Kamil Gumienny
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BSTH.h"

/*
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
 */
treeItem *addItem(treeItem *p, char *w) {
	if (p == NULL) {
		p = malloc(sizeof(treeItem));
		char *c = malloc(strlen(w) + 1);
		p->word = strcpy(c, w);
		p->count = 1;
		p->left = p->right = NULL;
		return p;
	}
	int c = strcmp(w, p->word);
	if (c == 0)
		p->count++;
	else if (c < 0)
		p->left = addItem(p->left, w);
	else
		p->right = addItem(p->right, w);
	return p;
}

/*
 * the function prints recursively by first navigating to the leftmost
 * leaf and printing it's contents, and then printing the right one.
 * if a leaf doesn't exist, the function goes back one generation and tries
 * printing again until all the printing is done.
 */
void printTree(treeItem *p, FILE *output){
	if (p != NULL){
		printTree(p->left, output);
		fprintf(output, "%4d %s\n", p->count, p->word);
		printTree(p->right, output);
	}
}

/*
 * clearTree goes through every leaf in a tree in a recursive manner,
 * exactly like the printTree method, navigating to the leftmost
 * leaf in the BST and removing it from memory.
 */
void clearTree(treeItem *p){
	if (p != NULL){
		clearTree(p->left);
		free(p);
		clearTree(p->right);
	}
}

