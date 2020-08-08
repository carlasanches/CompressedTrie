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
            printf("%s\n", word);

            Insert(&tree, word);

            for(x = 0; x < 50; x++){
                word[x] = '\0';
            }
        }

        c = tolower(getc(pointer_txt));
    }

    FreeMemory(tree.root);
    free(tree.root);

    /*

    FILE *pointer_txt;
    char c;
    char alphabet[26] = "abcdefghijklmnopqrstuvwxyz";

    CompressedTrieTree tree;
    Ocurrence ocurrence;
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

    Initialize(&tree); */ /* ponteiro do parâmetro recebe o endereço de memória da variável tree.
                          Assim, ele consegue alterar os valores de tree na função Initialize */

   /* pointer_txt = fopen("test.txt","r");

    if(pointer_txt == NULL){
        printf("Error");
        return 1;
    }

    c = tolower(getc(pointer_txt));

    int k = 0;

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
        }

        if(word[0] != '\0'){
            position = ftell(pointer_txt) - j;
            CreateOcurrence(&ocurrence, word, j,position);
            printf("%s\n", word);

            Insert(&tree, ocurrence, prefix, sufix, sufix2);
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

    int param; //para teste: 0 = interactive / other = exp
    fflush(stdin);
    scanf("%d", &param);

    char prefixo[10];

    for(y = 0; y < 10; y++){
        prefixo[y] = '\0';
    }

    if(param == 0){

        printf("entre com o prefixo ou digite 0 para sair: ");
        fflush(stdin);
        scanf("%c", &prefixo[0]);

        int index = prefixo[0] - 'a';

        if(prefixo[0] != '0'){

            Node *node;
            node = malloc(sizeof(Node));

            printf("sugestões: ");
            node = Search(tree.root->children[index], prefixo[0]);

            Print(node->ocurrence);
        }
    }
    else{
        rewind(pointer_txt);

        clock_t t;
        t = clock();

        Node *exp_node;
        exp_node = malloc(sizeof(Node));

        printf("sugestões: ");
        exp_node = Search(tree.root->children[0], 'a');

        Print(exp_node->ocurrence);

        t = clock() - t;
        printf("TEMPO: %lf ms", (double) t);

    }

    fclose(pointer_txt);

    FreeMemory(tree.root);*/



    return 0;
}
