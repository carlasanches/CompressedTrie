/*
    Compressed Trie Tree
    GitHub - https://github.com/carlasanches/CompressedTrieTree
    Author - Carla Sanches
*/

#include "CompressedTrieTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    clock_t t;
    t = clock();

    FILE *pointer_txt;
    char c;
    char alphabet[52] = "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz";

    CompressedTrieTree tree;
    Ocurrence *ocurrence;
    char word[5];

    int y;

    for(y = 0; y < 5; y++){
        word[y] = '\0';
    }

    Initialize(&tree); /* ponteiro do parâmetro recebe o endereço de memória da variável tree.
                          Assim, ele consegue alterar os valores de tree na função Initialize */

    pointer_txt = fopen("test.txt","r");

    if(pointer_txt == NULL){
        printf("Error");
        return 1;
    }

    c = getc(pointer_txt);

    int k = 0;

    ocurrence = malloc(sizeof(Ocurrence));

    while(c != EOF){

        int j = 0;

        while(c != ' ' && c != EOF){

            int i;

            for(i = 0; i < 52; i++){
                if(c == alphabet[i]){

                    word[j] = c;
                    break;
                }
            }

            j++;
            c = getc(pointer_txt);
        }

        CreateOcurrence(&ocurrence[k], word);

        Insert(&tree, ocurrence[k]);
        k++;

        c = getc(pointer_txt);
    }

    printf("%s\n", tree.root->children[0]->ocurrence.word);
    printf("%s\n", tree.root->children[0]->children[0]->ocurrence.word);
    printf("%s\n", tree.root->children[0]->children[1]->ocurrence.word);
    printf("%s\n", tree.root->children[1]->ocurrence.word);

    fclose(pointer_txt);

    FreeMemory(tree.root);

    t = clock() - t;
    printf("%lf ms", (double) t);

    return 0;
}
