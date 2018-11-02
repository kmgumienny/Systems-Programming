/*
 * ReadWrite.h -- Kamil Gumienny
 */

#ifndef READWRITE_H_
#define READWRITE_H_
typedef struct TreeItem treeItem;


void toLowerCase(char* c);
int checkIsWord(char* word);
void removeALetter(char* c, int counter);
int isLetter(char c);
void copyWord(char* c, char* aWord, int start, int end);
int WordConditioning(char* c, char* aWord, int start, int end);
treeItem *readAFile(char* fileSource, treeItem *p);




#endif /* READWRITE_H_ */
