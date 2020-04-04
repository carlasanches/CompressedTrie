/* 
    Compressed Trie Tree
    GitHub - https://github.com/carlasanches/CompressedTrieTree
    Author - Carla Sanches
*/

#ifndef COMPRESSEDTRIETREE_H_INCLUDED
#define COMPRESSEDTRIETREE_H_INCLUDED

#include <stdbool.h>

typedef struct{
    char words[26][50];
    int ocurrences[26];
}Ocurrence; //a word, prefix or sufix and the positions of your ocurrences

typedef struct node{
    struct node *children[26];
    Ocurrence ocurrence;
    bool isWordEnd;
}Node;

typedef struct{
    Node *root;
}CompressedTrieTree;

void Insert(CompressedTrieTree *tree, Ocurrence ocurrence);
void Initialize(CompressedTrieTree *tree);
int isEmpty(CompressedTrieTree tree);
Node* NewNode(Ocurrence ocurrence);
void FreeMemory(Node *node);


#endif // COMPRESSEDTRIETREE_H_INCLUDED