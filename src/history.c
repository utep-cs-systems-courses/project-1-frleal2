#include "history.h"
#include <stdlib.h>
#include <stdio.h>

/* We need to have a method to copy strings, function to copy string*/

char* copy_str(char* string){
    short i = 0;
  while(string[i] != '\0'){
    i++;
  }
  i++;
  char* copy = (char*) malloc(i*sizeof(char));
  i =0;
  while(*string){
    copy[i] = *string;
    i++;
    string++;
  }
  return copy;
}

/* We need a linked list in order to keep track of the history, fuction to initialize a list*/
List* init_history(){
    List* head;
    head = (List*)malloc(sizeof(List));
    head->root = NULL;
    return head;
}

/* Then we need to be able to add an element to the end of the list, function to add element to a list*/
void add_history(List* list, char* string){
    if(list->root == NULL){
        list->root == (Item*) malloc(sizeof(Item));
        list->root->id = 1;
        list->root->str = copy_str(string);
        list->root->next = NULL;
    }
    else{
        Item* tail;
        tail = (list->root);
        while((tail->next)!= NULL){
            tail = tail->next;
        }
        tail->next = (Item*) malloc(sizeof(Item));
        (*tail).next -> id = ((*tail).id) + 1;
        (*tail).next -> str = copy_str(string);
        (*tail).next -> next = NULL;
    }
}

/* Function to retrieve string stored in node according to id*/
char* get_history(List* list, int id){
    Item* head;
    if(list -> root == NULL){
        return "Error, List is empty";
    }
    else{
        head = (list->root);
        while(head != NULL){
            if((*head).id == id){
                return (*head).str;
            }
            head = head->next;
        }
        return "ERROR, ID not in list";
    }
}

/* Function in order to print the entire */
void print_history(List* list){
    Item* head;
    if(list -> root == NULL){
        printf("ERROR, List is empty");
    }
    else{
        head = (list->root);
        while(head != NULL){
            printf("Element %d: $s \n", head->id, head->str);
            head = head -> next;
        }
    }
}

/*Function to free the memory allocated in the list along with its elements*/
void free_history(List* list){
    Item* head;
    Item* temp;
    head = (list ->root);
    while(head != NULL){
        temp = head;
        head = head->next;
        free(temp);
    }
    free(list);
}