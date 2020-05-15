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

void CreateOcurrence(Ocurrence *ocurrence, char *word){

    ocurrence->ocurrences = (int*) malloc(sizeof(int));
    ocurrence->word = (char*) malloc(sizeof(char));

    ocurrence->length = 5;
    ocurrence->ocurrences[0] = 1;

    int x;

    for(x = 0; x < 5; x++){
        ocurrence->word[x] = word[x];
    }
}

Node* CreateNode(Ocurrence ocurrence){

    Node *node = malloc(sizeof(Node));

    node->children = malloc(26 * sizeof(Node*));
    node->ocurrence = ocurrence;
    node->isWordEnd = 1;

    int i;

    for(i = 0; i < 26; i++){
        node->children[i] = NULL;
    }

    return node;
}

 void Insert(CompressedTrieTree *tree, Ocurrence ocurrence){

    int index = ocurrence.word[0] - 'a';    /*Calcula a posição correta para inserir a palavra baseado no valor do
                                                caracter 'a' na tabela ASCII*/
                                            /*Calculates the correct position to insert the word based on the value
                                                of the character 'a' in the ASCII table*/

    if(isEmpty(*tree)){

        tree->root = CreateRoot();
        tree->root->children[index] = CreateNode(ocurrence);
    }
    else{
        if(tree->root->children[index] == NULL){
            tree->root->children[index] = CreateNode(ocurrence);
        }
        else{

            int i = 0;
            int j = 0;

            char prefix[3];
            char sufix[3];
            char sufix2[3];

            int x;

            for(x = 0; x < 3; x++){
                prefix[x] = '\0';
                sufix[x] = '\0';
                sufix2[x] = '\0';
            }

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
            ocurrence.word = sufix;

            Ocurrence *ocurrence2 = malloc(sizeof(Ocurrence));
            ocurrence2->word = sufix2;

            tree->root->children[index]->children[children_index] = CreateNode(ocurrence);
            tree->root->children[index]->children[children2_index] = CreateNode(*ocurrence2);
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


