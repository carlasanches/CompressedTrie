/*
    Compressed Trie Tree
    GitHub - https://github.com/carlasanches/CompressedTrieTree
    Author - Carla Sanches
*/

#include "CompressedTrieTree.h"
#include <stdio.h>
#include <stdlib.h>

#define ALPHABET 26

void Initialize(CompressedTrieTree *tree){
    tree->root = malloc(sizeof(Node));
    tree->root->children = malloc(ALPHABET * sizeof(Node));

    int i;

    for(i = 0; i < ALPHABET; i++){
        tree->root->children[i].children = NULL;
    }

    //Other root attributes are not important
    //Outros atributos da raiz não são importantes
}

void Insert(CompressedTrieTree *tree, char *word, int position){

    int index = word[0] - 'a';  /*Calculates the correct position to insert the word based on the value
                                            of the character 'a' in the ASCII table*/
                                /*Calcula a posição correta para inserir a palavra baseado no valor do
                                  caracter 'a' na tabela ASCII*/

    int i = 0;

    while(word[i] != '\0'){
        tree->root->children[index].word[i] = word[i];
        i++;
    }
    tree->root->children[index].word[i] = '\0';
    tree->root->children[index].ocurrences[0] = position;
    printf("%d\n", tree->root->children[index].ocurrences[0]);
    tree->root->children[index].is_word_end = 1;
}

void FreeMemory(Node *node){
    int i;

    if(node->children != NULL){

        for(i = 0; i < ALPHABET; i++){
            FreeMemory(&node->children[i]);
        }
        free(node->children);
    }
}

/*void InitNode(char *word){


}*/

/*Node NewNode(char *word){

    Node *node = malloc(sizeof(Node));

    node->children = NULL;
    node->ocurrence.ocurrences = (int*) malloc(sizeof(int));

    node->ocurrence.ocurrences[0] = ocurrence.ocurrences[0];
    printf("%d\n", node->ocurrence.ocurrences[0]);
    node->ocurrence.length = ocurrence.length;
    node->isWordEnd = isWordEnd;

    int i = 0;

    while(word[i] != '\0'){
        node->word[i] = word[i];
        node->word[i+1] = '\0';
        i++;
    }



    for(i = 0; i < ocurrence.length; i++){
        node->ocurrence.word[i] = ocurrence.word[i];
    }

    for(i = 0; i < 26; i++){
        node->children[i] = NULL;
    }

    return node;
}*/

int isEmpty(CompressedTrieTree tree){
    return(tree.root == NULL);
}

/*Essa função inicializa os filhos da raiz e foi criada para lidar com a particularidade
   da trie possuir uma raiz vazia*/
/*Node* CreateRoot(){

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
}*/

/*void CreateOcurrence(Ocurrence *ocurrence, char *word, int length, int position){

    length++; //aumento o tamanho da palavra para que ela receba o primeiro \0 de word
    ocurrence->ocurrences = (int*) malloc(sizeof(int));
    ocurrence->word = (char*) malloc(length * sizeof(char));
    ocurrence->length = length;

    ocurrence->ocurrences[0] = position;

    int x;

    for(x = 0; x < length; x++){
        ocurrence->word[x] = word[x];
    }
}*/

/* void Insert(CompressedTrieTree *tree, Ocurrence ocurrence, char *prefix, char *sufix, char *sufix2){

    int index = ocurrence.word[0] - 'a';*/    /*Calcula a posição correta para inserir a palavra baseado no valor do
                                                caracter 'a' na tabela ASCII*/
                                            /*Calculates the correct position to insert the word based on the value
                                                of the character 'a' in the ASCII table*/
/*
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
            int flag = 0;

            while(ocurrence.word[i] == tree->root->children[index]->ocurrence.word[i] && ocurrence.word[i] != '\0'
                                                                    && tree->root->children[index]->ocurrence.word[i] != '\0'){
               prefix[i] = ocurrence.word[i];
               i++;
            }

            int k = i;

            if(ocurrence.word[k] != '\0'){
                flag = 1;
                while(ocurrence.word[k] != '\0'){
                    sufix2[j] = ocurrence.word[k];
                    k++;
                    j++;
                }

                int children2_index = sufix2[0] - 'a';

                Ocurrence ocurrence2;

                CreateOcurrence(&ocurrence2, sufix2, j, ocurrence.ocurrences[0]);
                tree->root->children[index]->children[children2_index] = CreateNode(ocurrence2, isWordEnd);
            }

            j = 0;

            if(tree->root->children[index]->ocurrence.word[i] != '\0'){
                flag = 1;
                while(tree->root->children[index]->ocurrence.word[i] != '\0'){
                    sufix[j] = tree->root->children[index]->ocurrence.word[i];
                    i++;
                    j++;
                }

                int children_index = sufix[0] - 'a';

                int x;

                for(x = 0; x < tree->root->children[index]->ocurrence.length; x++){
                    tree->root->children[index]->ocurrence.word[x] = '\0';
                }

                x = 0;

                do{
                    tree->root->children[index]->ocurrence.word[x] = prefix[x];
                    x++;
                }while(prefix[x] != '\0');

                tree->root->children[index]->isWordEnd = 0;

                for(x = 0; x < ocurrence.length; x++){
                    ocurrence.word[x] = '\0';
                }

                x = 0;

                do{
                    ocurrence.word[x] = sufix[x];
                    x++;
                }while(sufix[x] != '\0');

                ocurrence.length = x+1;
                tree->root->children[index]->children[children_index] = CreateNode(ocurrence, isWordEnd);
            }
        }
    }
 }*/

/*void Print(Ocurrence ocurrence){
    printf("%s\n", ocurrence.word);
}*/

/*Node* Search(Node *node, char prefix){

    if(node == NULL || node->ocurrence.word[0] == prefix){
        return node;
    }
}*/


