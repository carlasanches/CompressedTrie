#ifndef COMPRESSEDTRIETREE_H_INCLUDED
#define COMPRESSEDTRIETREE_H_INCLUDED

typedef struct node{
    struct node *children;
    char word[50];
    int ocurrences[100];
    int is_word_end;
}Node;

typedef struct{
    Node *root;
}CompressedTrieTree;

void Initialize(CompressedTrieTree *tree);
void Insert(CompressedTrieTree *tree, char *word);
//void InitNode(CompressedTrieTree *tree, int position, char *word);

void FreeMemory(Node *node);
//
//void CreateOcurrence(Ocurrence *ocurrence, char *word, int length, int position);
//void Insert(CompressedTrieTree *tree, Ocurrence ocurrence, char *prefix, char *sufix, char *sufix2);
int isEmpty(CompressedTrieTree tree);
Node* CreateRoot();
//void Print(Ocurrence ocurrence);
Node* Search(Node *node, char prefix);

#endif // COMPRESSEDTRIETREE_H_INCLUDED
