#ifndef COMPRESSEDTRIETREE_H_INCLUDED
#define COMPRESSEDTRIETREE_H_INCLUDED

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

void Insert(CompressedTrieTree *tree, Ocurrence ocurrence, char *prefix, char *sufix, char *sufix2);
void Initialize(CompressedTrieTree *tree);
int isEmpty(CompressedTrieTree tree);
Node* CreateRoot();
Node* CreateNode(Ocurrence ocurrence, int isWordEnd);
void CreateOcurrence(Ocurrence *ocurrence, char *word, int length, int position);
void FreeMemory(Node *node);

#endif // COMPRESSEDTRIETREE_H_INCLUDED
