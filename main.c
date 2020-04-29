/*
    Compressed Trie Tree
    GitHub - https://github.com/carlasanches/CompressedTrieTree
    Author - Carla Sanches
*/

#include "CompressedTrieTree.h"
#include <stdio.h>
#include <stdlib.h>

int main(){

    CompressedTrieTree tree;
    Ocurrence ocurrence, ocurrence2, ocurrence3;

    ocurrence.ocurrences = (int*) malloc(sizeof(int));
    ocurrence.word = (char*) malloc(5 * sizeof(char));

    ocurrence2.ocurrences = (int*) malloc(sizeof(int));
    ocurrence2.word = (char*) malloc(5 * sizeof(char));

    ocurrence3.ocurrences = (int*) malloc(sizeof(int));
    ocurrence3.word = (char*) malloc(5 * sizeof(char));

    char palavra[4];

    int i;
    for(i = 0; i < 4; i++){
        palavra[i] = 'a';
    }

    ocurrence.ocurrences[0] = 1;

    for(i = 0; i < 4; i++){
        ocurrence.word[i] = palavra[i];
    }

    Initialize(&tree); /* ponteiro do parâmetro recebe o endereço de memória da variável tree.
                          Assim, ele consegue alterar os valores de tree na função Initialize */

    Insert(&tree, ocurrence);

    for(i = 0; i < 4; i++){
        palavra[i] = 'b';
    }

    ocurrence2.ocurrences[0] = 1;

    for(i = 0; i < 4; i++){
        ocurrence2.word[i] = palavra[i];
    }

    Insert(&tree, ocurrence2);

    for(i = 0; i < 2; i++){
        palavra[i] = 'b';
    }

    for(i = 2; i < 4; i++){
        palavra[i] = 'a';
    }

    ocurrence3.ocurrences[0] = 1;

    for(i = 0; i < 4; i++){
        ocurrence3.word[i] = palavra[i];
    }

    Insert(&tree, ocurrence3);

    FreeMemory(tree.root);
    free(ocurrence.ocurrences);
    free(ocurrence.word);
    free(ocurrence2.ocurrences);
    free(ocurrence2.word);
    free(ocurrence3.ocurrences);
    free(ocurrence3.word);

    return 0;
}
