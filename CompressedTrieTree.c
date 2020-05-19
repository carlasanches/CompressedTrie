/*
    Compressed Trie Tree
    GitHub - https://github.com/carlasanches/CompressedTrieTree
    Author - Carla Sanches
*/

#include "CompressedTrieTree.h"
#include <stdio.h>
#include <stdlib.h>

#define NUM_CHILDREN 26

void Initialize(CompressedTrieTree *tree){
   tree->root = NULL;
}

int isEmpty(CompressedTrieTree tree){
    return(tree.root == NULL);
}

/*Essa função inicializa os filhos da raiz e foi criada para lidar com a particularidade
   da trie possuir uma raiz vazia*/
Node* CreateRoot(){

    Node *node = malloc(sizeof(Node));

    node->children = malloc(26 * sizeof(Node*));
    node->ocurrence.ocurrences = NULL;
    node->ocurrence.word = NULL;
    node->isWordEnd = 0;

    int i;

    for(i = 0; i < 26; i++){
        node->children[i] = NULL;
    }

    return node;
}

void CreateOcurrence(Ocurrence *ocurrence, char *word, int length, int position){

    ocurrence->ocurrences = (int*) malloc(sizeof(int));
    ocurrence->word = (char*) malloc(sizeof(char));

    ocurrence->length = length;
    ocurrence->ocurrences_length = 1;
    ocurrence->ocurrences[ocurrence->ocurrences_length-1] = position;

    int x;

    for(x = 0; x < 5; x++){
        ocurrence->word[x] = word[x];
    }
}

Node* CreateNode(Ocurrence ocurrence, int isWordEnd){

    Node *node = malloc(sizeof(Node));

    node->children = malloc(26 * sizeof(Node*));
    node->ocurrence = ocurrence;
    node->isWordEnd = isWordEnd;

    int i;

    for(i = 0; i < 26; i++){
        node->children[i] = NULL;
    }

    return node;
}

 void Insert(CompressedTrieTree *tree, Ocurrence ocurrence, char *prefix, char *sufix, char *sufix2){

    int index = ocurrence.word[0] - 'a';    /*Calcula a posição correta para inserir a palavra baseado no valor do
                                                caracter 'a' na tabela ASCII*/
                                            /*Calculates the correct position to insert the word based on the value
                                                of the character 'a' in the ASCII table*/

    if(isEmpty(*tree)){

        int isWordEnd = 1;

        tree->root = CreateRoot();
        tree->root->children[index] = CreateNode(ocurrence, isWordEnd);
    }
    else{
        if(tree->root->children[index] == NULL){
            int isWordEnd = 1;
            tree->root->children[index] = CreateNode(ocurrence, isWordEnd);
        }
        else{

            int isWordEnd = 1;

            int i = 0;
            int j = 0;

            while(ocurrence.word[i] == tree->root->children[index]->ocurrence.word[i]){
               prefix[i] = ocurrence.word[i];
               i++;
            }

            int k = i;

            while(tree->root->children[index]->ocurrence.word[i] != '\0'){
                sufix[j] = tree->root->children[index]->ocurrence.word[i];
                i++;
                j++;
            }

            j = 0;

            while(ocurrence.word[k] != '\0'){
                sufix2[j] = ocurrence.word[k];
                k++;
                j++;
            }

            int children_index = sufix[0] - 'a';
            int children2_index = sufix2[0] - 'a';

            tree->root->children[index]->ocurrence.word = prefix;
            tree->root->children[index]->isWordEnd = 0;
            ocurrence.word = sufix;

            Ocurrence *ocurrence2 = malloc(sizeof(Ocurrence));
            ocurrence2->word = sufix2;

            tree->root->children[index]->children[children_index] = CreateNode(ocurrence, isWordEnd);
            tree->root->children[index]->children[children2_index] = CreateNode(*ocurrence2, isWordEnd);
        }
    }
 }

 void FreeMemory(Node *node){
    //int i;

    free(node);

    // if(!node){
    //     for(i = 0; i <= 25; i++){
    //         FreeMemory(node->children[i]);
    //     }
    //     free(node);
    // }
 }


