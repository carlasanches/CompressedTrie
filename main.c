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
    Ocurrence ocurrence, ocurrence2;

    ocurrence.ocurrences = (int*) malloc(sizeof(int));
    ocurrence.word = (char*) malloc(5 * sizeof(char));

    ocurrence2.ocurrences = (int*) malloc(sizeof(int));
    ocurrence2.word = (char*) malloc(5 * sizeof(char));

    char palavra[4];

    int i;
    for(i = 0; i < 4; i++){
        palavra[i] = 'a';
    }

    ocurrence.ocurrences[0] = 1;

    for(i = 0; i < 4; i++){
        ocurrence.word[i] = palavra[i];
    }

    Initialize(&tree); /* ponteiro do par�metro recebe o endere�o de mem�ria da vari�vel tree.
                          Assim, ele consegue alterar os valores de tree na fun��o Initialize */

    Insert(&tree, ocurrence);

    for(i = 0; i < 4; i++){
        palavra[i] = 'b';
    }

    ocurrence2.ocurrences[0] = 1;

    for(i = 0; i < 4; i++){
        ocurrence2.word[i] = palavra[i];
    }

    Insert(&tree, ocurrence2);

    FreeMemory(tree.root);
    free(ocurrence.ocurrences);
    free(ocurrence.word); //n�o funciona
    free(ocurrence2.ocurrences);
    free(ocurrence2.word); //n�o funciona

    return 0;
}
