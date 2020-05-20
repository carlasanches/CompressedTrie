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

    clock_t t;
    t = clock();

    FILE *pointer_txt;
    char c;
    char alphabet[26] = "abcdefghijklmnopqrstuvwxyz";

    CompressedTrieTree tree;
    Ocurrence *ocurrence;
    char word[50];

    char prefix[30];
    char sufix[30];
    char sufix2[30];

    int x;

    for(x = 0; x < 30; x++){
        prefix[x] = '\0';
        sufix[x] = '\0';
        sufix2[x] = '\0';
    }

    int y;

    for(y = 0; y < 50; y++){
        word[y] = '\0';
    }

    Initialize(&tree); /* ponteiro do parâmetro recebe o endereço de memória da variável tree.
                          Assim, ele consegue alterar os valores de tree na função Initialize */

    pointer_txt = fopen("baskervilles.txt","r");

    if(pointer_txt == NULL){
        printf("Error");
        return 1;
    }

    c = tolower(getc(pointer_txt));

    int k = 0;

    ocurrence = malloc(sizeof(Ocurrence));
    int position = 0;

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
            position++;
        }

        if(word[0] != '\0'){
            CreateOcurrence(&ocurrence[k], word, i,position);
            printf("%s\n", word);

            Insert(&tree, ocurrence[k], prefix, sufix, sufix2);
            k++;

            for(y = 0; y < 50; y++){
                word[y] = '\0';
            }
        }

        for(x = 0; x < 30; x++){
            prefix[x] = '\0';
            sufix[x] = '\0';
            sufix2[x] = '\0';
        }

        c = tolower(getc(pointer_txt));
        position++;
    }

    fclose(pointer_txt);

    FreeMemory(tree.root);

    t = clock() - t;
    printf("%lf ms", (double) t);

    return 0;
}
