#include "histor.h"
#include <stdlib.h>
#include <stdio.h>

/* We need to have a method to copy strings, function to copy string*/

char* copy_str(char* string){
    short counter = 1;
    for (i = 0; string[i] != '\0'; i++)
    {
        counter++;
    }
    char* twin = (char*)malloc(counter*sizeof(char));
    i =0;
    while(*string){
        twin[i] = *string;
        i++;
        string++;
    }
    return copy;
}

/* We need a linked list in order to keep track of the history, fuction to initialize a list*/
List* init_history(){
    List* history;
    history = (List*)malloc(sizeof(List));
    history->root = NULL;
    return history;
}

/* Then we need to be able to add an element to the end of the list, function to add element to a list*/
void add_to_list(List* list, char* string){
    if(list->root == NULL){
        list->root == (Item*) malloc(sizeof(Item));
        list->root->id = 1;
        list->root->str = str_duplicate(string);
        list->root->next = NULL;
    }
    else{
        Item* temp;
        temp = (list->root);
        while((temp->next)!= NULL){
            temp = temp->next;
        }
        temp->next = (Item*) malloc(sizeof(Item));
        (*temp).next -> id = ((*temp).id) + 1;
        (*temp).next -> str = ((*temp).id) + 1;
    }


}