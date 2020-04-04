#include <stdio.h>

#include "CompressedTrieTree.h"

int main(){

    CompressedTrieTree tree;
    Ocurrence ocurrence;
   
    /*==================== TEST =====================*/
    char palavra[4];    

    int i;
    for(i = 0; i <= 4; i++){
        palavra[i] = 'a';
    }    

    ocurrence.ocurrences[0] = 1;
    
    for(i = 0; i <= 4; i++){
        ocurrence.words[0][i] = palavra[i];
    }

    /*===============================================*/

    Initialize(&tree); /* ponteiro do parâmetro recebe o endereço de memória da variável tree. 
                          Assim, ele consegue alterar os valores de tree na função Initialize */

    Insert(&tree, ocurrence);
      
    FreeMemory(tree.root);   

    return 0;
}