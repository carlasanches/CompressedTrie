/* 
    Compressed Trie Tree
    GitHub - https://github.com/carlasanches/CompressedTrieTree
    Author - Carla Sanches
*/

#include "CompressedTrieTree.h"
#include <stdio.h>
#include <stdlib.h>

void Initialize(CompressedTrieTree *tree){
    tree->root = NULL;
}

int isEmpty(CompressedTrieTree tree){
    return(tree.root == NULL);
}

Node* NewNode(Ocurrence ocurrence){
    Node *node = malloc(sizeof(Node));

    node->ocurrence = ocurrence;
    node->isWordEnd = true;

    int i; 

    for(i = 0; i <= 25; i++){
        node->children[i] = NULL;
    }

    return node;
}

 void Insert(CompressedTrieTree *tree, Ocurrence ocurrence){

    if(isEmpty(*tree)){
        tree->root = NewNode(ocurrence); //inserts a new occurrence of a new word in an empty tree
    }
 }

void FreeMemory(Node *node){
    //int i;

    free(node);

    // if(!node){
    //     for(i = 0; i <= 25; i++){
    //         FreeMemory(node->children[i]);
    //     }
    //     free(node);
    // }
}


