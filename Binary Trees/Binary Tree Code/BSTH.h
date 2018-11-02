/*
 * BSTH.h -- Kamil Gumienny
 */

#ifndef BSTH_H_
#define BSTH_H_


typedef struct TreeItem treeItem;

struct TreeItem {
	char *word;
	int count;
	struct TreeItem *left, *right;
};
treeItem *addItem(treeItem *p, char *w);
treeItem *findItem(treeItem *p, char *w);
void printTree(treeItem *p, FILE *output);
void clearTree(treeItem *p);


#endif /* READING_H_ */
