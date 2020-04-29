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
Node* CreateNode(){

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

void RefreshNode(Node *node, Ocurrence ocurrence){
    node->ocurrence = ocurrence;
    node->isWordEnd = 1;
}

 void Insert(CompressedTrieTree *tree, Ocurrence ocurrence){

     #define typeof(var) _Generic( (var),\
        char: "Char",\
        int: "Integer",\
        float: "Float",\
        char *: "String",\
        void *: "Pointer",\
        default: "Undefined")

    int index = ocurrence.word[0] - 'a';    /*Calcula a posição correta para inserir a palavra baseado no valor do
                                                caracter 'a' na tabela ASCII*/
                                            /*Calculates the correct position to insert the word based on the value
                                                of the character 'a' in the ASCII table*/

    if(isEmpty(*tree)){

        tree->root = CreateNode();
        tree->root->children[index] = CreateNode();
        RefreshNode(tree->root->children[index], ocurrence);//inserts a new occurrence of a new word in an empty tree
    }
    else{
        if(tree->root->children[index] == NULL){
            tree->root->children[index] = CreateNode();
            RefreshNode(tree->root->children[index], ocurrence);
        }
        else{
            int i = 0;

            while(ocurrence.word[i] == tree->root->children[index]->ocurrence.word[i]){
               i++;
            }

            Ocurrence new_ocurrence;

            new_ocurrence.ocurrences = (int*) malloc(sizeof(int));
            new_ocurrence.word = (char*) malloc(4 * sizeof(char));

            int children_index = ocurrence.word[i] - 'a';
            int j = 0;

            while(ocurrence.word[i] != '\0'){

                new_ocurrence.word[j] = ocurrence.word[i];
                j++;
                i++;
            }

            new_ocurrence.ocurrences[0] = ocurrence.ocurrences[0];

            tree->root->children[index]->children[children_index] = CreateNode();
            RefreshNode(tree->root->children[index]->children[children_index], new_ocurrence);

            free(new_ocurrence.ocurrences);
            free(new_ocurrence.word);
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


