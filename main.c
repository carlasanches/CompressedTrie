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

int main(){

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

    pointer_txt = fopen("test.txt","r");

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

    Print(tree.root);

    FreeMemory(tree.root);
    free(tree.root);

    return 0;
}
