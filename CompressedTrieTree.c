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

    return node;
}

Node* NewNode(Ocurrence ocurrence){
    Node *node = malloc(sizeof(Node));    

    node->children = NULL;
    node->ocurrence = ocurrence;
    node->isWordEnd = 1;

    return node;
}

 void Insert(CompressedTrieTree *tree, Ocurrence ocurrence){

    int index = ocurrence.word[0] - 'a';    /*Calcula a posição correta para inserir a palavra baseado no valor do 
                                                caracter 'a' na tabela ASCII*/
                                            /*Calculates the correct position to insert the word based on the value 
                                                of the character 'a' in the ASCII table*/
    //Node *node = NewNode(ocurrence);

    if(isEmpty(*tree)){

        tree->root = CreateRoot();
        tree->root->children[index] = NewNode(ocurrence); //inserts a new occurrence of a new word in an empty tree
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


