#ifndef COMPRESSEDTRIETREE_H_INCLUDED
#define COMPRESSEDTRIETREE_H_INCLUDED

#include <stdbool.h>

typedef struct{
    char *word;
    int length;
    int *ocurrences;
}Ocurrence; //a word, prefix or sufix and the positions of your ocurrences

typedef struct node{
    struct node **children;
    Ocurrence ocurrence;
    int isWordEnd;
}Node;

typedef struct{
    Node *root;
}CompressedTrieTree;

void Insert(CompressedTrieTree *tree, Ocurrence ocurrence);
void Initialize(CompressedTrieTree *tree);
int isEmpty(CompressedTrieTree tree);
Node* CreateRoot();
void RefreshNode(Node *node, Ocurrence ocurrence);
void FreeMemory(Node *node);

#endif // COMPRESSEDTRIETREE_H_INCLUDED
