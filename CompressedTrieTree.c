/*
    Compressed Trie Tree
    GitHub - https://github.com/carlasanches/CompressedTrieTree
    Author - Carla Sanches
*/

#include "CompressedTrieTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET 26

void Initialize(CompressedTrieTree *tree){
    tree->root = malloc(sizeof(Node));
    tree->root->children = malloc(ALPHABET * sizeof(Node));

    int i;

    for(i = 0; i < ALPHABET; i++){
        tree->root->children[i].word[0] = '\0';
        tree->root->children[i].num_ocurrences = 0;
        tree->root->children[i].children = NULL;
    }

    //Outros atributos da raiz não são importantes
    //Other root attributes are not important
}

void Insert(Node *node, char *word, int position){

    int index = word[0] - 'a'; /*Calcula a posição correta para inserir a palavra baseado no valor do
                                  caracter 'a' na tabela ASCII*/
                               /*Calculates the correct position to insert the word based on the value
                                            of the character 'a' in the ASCII table*/


    if(node->children[index].word[0] != '\0'){

        char suffix_1[50];
        char suffix_2[50];
        char prefix[50];

        int i = 0;
        int j = 0;
        int k = 0;
        int current_position = 0;

        while(word[i] != '\0' && word[i] == node->children[index].word[i] && node->children[index].word[i] != '\0'){
            prefix[i] = word[i];
            i++;
            j++;
        }
        prefix[i] = '\0';

        if(node->children[index].word[i] == '\0' && word[i] == '\0'){
            node->children[index].is_word_end = 1;
            node->children[index].ocurrences[node->children[index].num_ocurrences] = position;
            node->children[index].ocurrences[(node->children[index].num_ocurrences + 1)] = -1;
            node->children[index].num_ocurrences++;
        }
        else if(node->children[index].word[i] == '\0' && word[i] != '\0'){

            k = 0;

            while(word[i] != '\0'){
                suffix_1[k] = word[i];
                i++;
                k++;
            }
            suffix_1[k] = '\0';

            if(node->children[index].children == NULL){

                node->children[index].children = malloc(ALPHABET * sizeof(Node));

                for(i = 0; i < ALPHABET; i++){
                    node->children[index].children[i].word[0] = '\0';
                    node->children[index].children[i].num_ocurrences = 0;
                    node->children[index].children[i].children = NULL;
                }
            }

            Insert(&node->children[index],suffix_1,position);
        }
        else if(node->children[index].word[i] != '\0' && word[i] == '\0'){

            k = 0;

            while(node->children[index].word[j] != '\0'){
                suffix_2[k] = node->children[index].word[j];
                j++;
                k++;
            }
            suffix_2[k] = '\0';

            i = 0;

            while(prefix[i] != '\0'){
                node->children[index].word[i] = prefix[i];
                i++;
            }
            node->children[index].word[i] = '\0';
            current_position = node->children[index].ocurrences[0];

            Node *temp = node->children[index].children;

            node->children[index].children = malloc(ALPHABET * sizeof(Node));

            for(i = 0; i < ALPHABET; i++){
                node->children[index].children[i].word[0] = '\0';
                node->children[index].children[i].num_ocurrences = 0;
                node->children[index].children[i].children = NULL;
            }

            Insert(&node->children[index],suffix_2,current_position);

            node->children[index].children[suffix_2[0] - 'a'].children = temp;

            //Resolve temporariamente o problema de não poder inserir todas as ocorrências de um nó quando este é dividido
            //Temporarily resolves the problem of not being able to insert all occurrences of a node when it is split
            i = 0;
            while(node->children[index].ocurrences[i] >= 0){
                node->children[index].children[suffix_2[0] - 'a'].ocurrences[i] = node->children[index].ocurrences[i];
                i++;
            }
            node->children[index].children[suffix_2[0] - 'a'].ocurrences[i] = -1;

            node->children[index].ocurrences[0] = position;
            node->children[index].ocurrences[1] = -1;
            node->children[index].num_ocurrences = 1;
        }
        else{
            while(word[i] != '\0'){
                suffix_1[k] = word[i];
                i++;
                k++;
            }
            suffix_1[k] = '\0';

            k = 0;

            while(node->children[index].word[j] != '\0'){
                suffix_2[k] = node->children[index].word[j];
                j++;
                k++;
            }
            suffix_2[k] = '\0';

            i = 0;

            while(prefix[i] != '\0'){
                node->children[index].word[i] = prefix[i];
                i++;
            }
            node->children[index].word[i] = '\0';

            current_position = node->children[index].ocurrences[0];

            Node *temp = node->children[index].children;

            node->children[index].children = malloc(ALPHABET * sizeof(Node));

            for(i = 0; i < ALPHABET; i++){
                node->children[index].children[i].word[0] = '\0';
                node->children[index].children[i].num_ocurrences = 0;
                node->children[index].children[i].children = NULL;
            }

            Insert(&node->children[index],suffix_1,position);
            Insert(&node->children[index],suffix_2,current_position);

            node->children[index].children[suffix_2[0] - 'a'].children = temp;

            //se o nó tiver filhos e não for uma terminação de palavra, o sufixo receberá esses filhos e não poderá ser um final de palavra
            //if the node has children and is not a word ending, the suffix will receive those children and cannot be an end of word
            if(temp != NULL && node->children[index].is_word_end == 0){
                node->children[index].children[suffix_2[0] - 'a'].is_word_end = 0;
            }

            //Resolve temporariamente o problema de não poder inserir todas as ocorrências de um nó quando este é dividido
            //Temporarily resolves the problem of not being able to insert all occurrences of a node when it is split
            i = 0;
            while(node->children[index].ocurrences[i] >= 0){
                node->children[index].children[suffix_2[0] - 'a'].ocurrences[i] = node->children[index].ocurrences[i];
                i++;
            }
            node->children[index].children[suffix_2[0] - 'a'].ocurrences[i] = -1;

            node->children[index].ocurrences[0] = -1;

            node->children[index].is_word_end = 0;
        }
    }
    else{
        int i = 0;

        while(word[i] != '\0'){

            node->children[index].word[i] = word[i];
            i++;
        }
        node->children[index].word[i] = '\0';
        node->children[index].ocurrences[node->children[index].num_ocurrences] = position;
        node->children[index].ocurrences[(node->children[index].num_ocurrences + 1)] = -1;
        node->children[index].num_ocurrences++;
        node->children[index].is_word_end = 1;
    }
}

void Search(Node *node, char *word, char *aux_word, int length, int prev_length, Ocurrence *ocurrences){
    int i = 0;

    prev_length = length;
    if(node->children != NULL){
        for(i = 0; i < ALPHABET; i++){
            if(node->children[i].word[0] != '\0'){
                length = strlen(node->children[i].word);
                strcat(aux_word,node->children[i].word);
                if(node->children[i].is_word_end == 1){

                    int j = 0;

                    while(aux_word[j] == word[j]){
                        j++;
                    }

                    if(j > 0 && j >= strlen(word)){
                        //printf("\n              %s (%d)", aux_word,node->children[i].num_ocurrences);

                        if(ocurrences[0].num_ocurrences > 0){
                            int k, x;

                            for(k = 0; k < ocurrences->num_ocurrences; k++){
                                if(ocurrences[k].num_ocurrences < node->children[i].num_ocurrences){
                                    break;
                                }
                            }

                            for(x = ocurrences->num_ocurrences; x > k; x--){
                                ocurrences[x] = ocurrences[x-1];
                            }
                            strcpy(ocurrences[k].word,aux_word);
                            ocurrences[k].num_ocurrences = node->children[i].num_ocurrences;
                            ocurrences->num_ocurrences++;
                        }
                        else{
                            strcpy(ocurrences[0].word,aux_word);
                            ocurrences[0].num_ocurrences = node->children[i].num_ocurrences;
                            ocurrences->num_ocurrences = 1;
                        }
                    }
                }
                Search(&node->children[i],word,aux_word,length,prev_length,ocurrences);
            }
        }
    }
    else{
        int position = strlen(aux_word) - length;
        aux_word[position] = '\0';
        return;
    }
    int position = strlen(aux_word) - prev_length;
    aux_word[position] = '\0';
}

void PrintWords(Node *node, char *aux_word, int length, int prev_length){
    int i = 0;

    prev_length = length;
    if(node->children != NULL){
        for(i = 0; i < ALPHABET; i++){
            if(node->children[i].word[0] != '\0'){
                length = strlen(node->children[i].word);
                strcat(aux_word,node->children[i].word);
                if(node->children[i].is_word_end == 1){
                    printf("%s\n", aux_word);
                }
                PrintWords(&node->children[i],aux_word,length,prev_length);
            }
        }
    }
    else{
        int position = strlen(aux_word) - length;
        aux_word[position] = '\0';
        return;
    }
    int position = strlen(aux_word) - prev_length;
    aux_word[position] = '\0';
}

void PrintTrie(Node *node){

    int i;

    if(node->children != NULL){
        for(i = 0; i < ALPHABET; i++){
            if(node->children[i].word[0] != '\0'){
                printf("%s ", node->children[i].word);
                printf("%d ", node->children[i].is_word_end);

                int j = 0;
                while(node->children[i].ocurrences[j] >= 0){
                    printf("%d ", node->children[i].ocurrences[j]);
                    j++;
                }
                printf("\n");
                PrintTrie(&node->children[i]);
            }
        }
    }
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

int isEmpty(CompressedTrieTree tree){
    return(tree.root == NULL);
}


