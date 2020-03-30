#ifndef COMPRESSEDTRIETREE_H_INCLUDED
#define COMPRESSEDTRIETREE_H_INCLUDED

typedef struct{
    char *words[26][50];
    int ocurrences[100];
}Item; //prefix or sufix of a word

typedef struct node{
    struct node *children[26];
    Item item;
    bool isWordEnd;
}Node;

typedef struct{
    Node *root;
}CompressedTrieTree;


#endif // COMPRESSEDTRIETREE_H_INCLUDED