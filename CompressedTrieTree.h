/*
    Compressed Trie Tree
    GitHub - https://github.com/carlasanches/CompressedTrieTree
    Author - Carla Sanches
*/

#ifndef COMPRESSEDTRIETREE_H_INCLUDED
#define COMPRESSEDTRIETREE_H_INCLUDED

typedef struct node{
    struct node *children;
    char word[50];
    int ocurrences[100];
    int num_ocurrences; //counts the number of occurrences of a word
    int is_word_end;
}Node;

typedef struct{
    Node *root;
}CompressedTrieTree;

void Initialize(CompressedTrieTree *tree);
void Insert(Node *node, char *word, int position);
void FreeMemory(Node *node);
void PrintWords(Node *node, char *aux_word, int length, int prev_length);
void PrintTrie(Node *node);
void Search(Node *node, char *word, char *aux_word, int length, int prev_length);

#endif // COMPRESSEDTRIETREE_H_INCLUDED
