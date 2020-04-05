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
    Ocurrence ocurrence;

    ocurrence.ocurrences = (int*) malloc(sizeof(int));
    ocurrence.word = (char*) malloc(5 * sizeof(char));

    char palavra[4];    

    int i;
    for(i = 0; i <= 4; i++){
        palavra[i] = 'a';
    } 

    ocurrence.ocurrences[0] = 1;
    
    for(i = 0; i <= 4; i++){
        ocurrence.word[i] = palavra[i];
    }

    Initialize(&tree); /* ponteiro do parâmetro recebe o endereço de memória da variável tree. 
                          Assim, ele consegue alterar os valores de tree na função Initialize */

    Insert(&tree, ocurrence);
      
    FreeMemory(tree.root);   
    free(ocurrence.ocurrences);
    free(ocurrence.word); //não é assim que dá free em vetor

    return 0;
}