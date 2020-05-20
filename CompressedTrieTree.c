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
    node->ocurrence.word = NULL;
    node->ocurrence.ocurrences = NULL;
    node->isWordEnd = 0;

    int i;

    for(i = 0; i < 26; i++){
        node->children[i] = NULL;
    }

    return node;
}

void CreateOcurrence(Ocurrence *ocurrence, char *word, int length, int position){

    length++; //aumento o tamanho da palavra para que ela receba o primeiro \0 de word
    ocurrence->ocurrences = (int*) malloc(sizeof(int));
    ocurrence->word = (char*) malloc(length * sizeof(char));
    ocurrence->length = length;

    ocurrence->ocurrences[0] = position;

    int x;

    for(x = 0; x < length; x++){
        ocurrence->word[x] = word[x];
    }
}

Node* CreateNode(Ocurrence ocurrence, int isWordEnd){

    Node *node = malloc(sizeof(Node));

    node->children = malloc(26 * sizeof(Node*));
    node->ocurrence.word = (char*) malloc(ocurrence.length * sizeof(char));
    node->ocurrence.ocurrences = (int*) malloc(sizeof(int));

    *node->ocurrence.word = ocurrence.word;
    *node->ocurrence.ocurrences = ocurrence.ocurrences;
    node->ocurrence.length = ocurrence.length;
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

            while(ocurrence.word[i] == tree->root->children[index]->ocurrence.word[i] && ocurrence.word[i] != '\0'
                                                                    && tree->root->children[index]->ocurrence.word[i] != '\0'){
               prefix[i] = ocurrence.word[i];
               i++;
            }

            int k = i;

            if(ocurrence.word[k] != '\0'){
                while(ocurrence.word[k] != '\0'){
                    sufix2[j] = ocurrence.word[k];
                    k++;
                    j++;
                }

                int children2_index = sufix2[0] - 'a';
                printf("%d\n", children2_index);

                Ocurrence ocurrence2;

                CreateOcurrence(&ocurrence2, sufix2, 1, 1);
                tree->root->children[index]->children[children2_index] = CreateNode(ocurrence2, isWordEnd);
            }

            j = 0;

            if(tree->root->children[index]->ocurrence.word[i] != '\0'){
                while(tree->root->children[index]->ocurrence.word[i] != '\0'){
                    sufix[j] = tree->root->children[index]->ocurrence.word[i];
                    i++;
                    j++;
                }

                int children_index = sufix[0] - 'a';
                printf("%d\n", children_index);

                tree->root->children[index]->ocurrence.word = prefix;
                tree->root->children[index]->isWordEnd = 0;
                *ocurrence.word = sufix;

                tree->root->children[index]->children[children_index] = CreateNode(ocurrence, isWordEnd);
            }
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


