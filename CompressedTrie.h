/*
    Compressed Trie Tree
    GitHub - https://github.com/carlasanches/CompressedTrieTree
    Author - Carla Sanches
*/

#ifndef COMPRESSEDTRIE_H_INCLUDED
#define COMPRESSEDTRIE_H_INCLUDED

typedef struct{
    char word[50];
    int num_ocurrences;
}Ocurrence; //Estrutura usada inicialmente para a pesquisa de palavras.

typedef struct node{
    struct node *children;
    char word[50];
    int ocurrences[100];
    int num_ocurrences; //conta o número de ocorrências de uma palavra //counts the number of occurrences of a word
    int is_word_end;
}Node;

typedef struct{
    Node *root;
}CompressedTrie;

void Initialize(CompressedTrie *tree);
void Insert(Node *node, char *word, int position);
void FreeMemory(Node *node);
void PrintWords(Node *node, char *aux_word, int length, int prev_length);
void PrintTrie(Node *node);
void Search(Node *node, char *word, char *aux_word, int length, int prev_length, Ocurrence *ocurrences);

#endif // COMPRESSEDTRIE_H_INCLUDED
