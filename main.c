/*
    Compressed Trie Tree
    GitHub - https://github.com/carlasanches/CompressedTrieTree
    Author - Carla Sanches
*/

#include "CompressedTrieTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[]){

    if(argc != 3){
        return 1;
    }

    if(strcmp(argv[2],"-interactive") != 0 && strcmp(argv[2],"-exp") != 0){
        printf("parametro invalido!");
        return 1;
    }

    FILE *pointer_txt;
    char c;
    char word[50];
    char alphabet[26] = "abcdefghijklmnopqrstuvwxyz";

    CompressedTrieTree tree;
    Initialize(&tree);

    int x;

    for(x = 0; x < 50; x++){
        word[x] = '\0';
    }

    pointer_txt = fopen(argv[1],"r");

    if(pointer_txt == NULL){
        printf("Error");
        return 1;
    }

    int position = 0;
    c = tolower(getc(pointer_txt));

    while(c != EOF){
        int j = 0;
        int i;

        while(c != ' ' && c != EOF && c != '\n'){

            for(i = 0; i < 26; i++){
                if(c == alphabet[i]){

                    word[j] = c;
                    j++;
                    break;
                }
            }

            c = tolower(getc(pointer_txt));
        }

        if(word[0] != '\0'){
            position = ftell(pointer_txt) - (j+1);

            Insert(tree.root, word, position);

            for(x = 0; x < 50; x++){
                word[x] = '\0';
            }
        }

        c = tolower(getc(pointer_txt));
    }

    //PrintTrie(tree.root);

    char aux_word[50];
    strcpy(aux_word,"\0");

    //PrintWords(tree.root,aux_word,0,0);

    if(strcmp(argv[2],"-interactive") == 0){
        char prefix[50];

        while(strcmp(prefix,"0") != 0){
            printf("\nEntre com o prefixo ou digite 0 para sair: ");
            fflush(stdin);
            scanf("%s", prefix);

            if(strcmp(prefix,"0") != 0){

                printf("   Sugestoes: ");
                Search(tree.root,prefix,aux_word,0,0);
            }
        }
    }
    else if(strcmp(argv[2],"-exp") == 0){

        char *prefix[10] = {"a","e","i","o","u","b","c","d","z","a"};

        int i;

        for(i = 0; i < 10; i++){
            printf("\n   Sugestoes: ");
            Search(tree.root,prefix[i],aux_word,0,0);
        }
    }

    FreeMemory(tree.root);
    free(tree.root);

    return 0;
}
