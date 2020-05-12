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

    char word[5];

    CompressedTrieTree tree;
    Ocurrence ocurrence;

    ocurrence.ocurrences = (int*) malloc(sizeof(int));
    ocurrence.word = (char*) malloc(5 * sizeof(char));

    ocurrence.ocurrences[0] = 1;
    ocurrence.length = 4;

    pointer_txt = fopen("test.txt","r");

    if(pointer_txt == NULL){
        printf("Error");
        return 1;
    }

    while(fgets(word,20,pointer_txt) != NULL){
        printf("%s", word);

        int i;

        for(i = 0; i < 4; i++){
            ocurrence.word[i] = word[i];
        }
    }

    fclose(pointer_txt);

    Initialize(&tree); /* ponteiro do parâmetro recebe o endereço de memória da variável tree.
                          Assim, ele consegue alterar os valores de tree na função Initialize */

    Insert(&tree, ocurrence);

    FreeMemory(tree.root);
    free(ocurrence.ocurrences);
    free(ocurrence.word);

    t = clock() - t;
    printf("%lf ms", (double) t);

    return 0;
}
