#include "history.h"
#include <stdlib.h>
#include <stdio.h>

/*Function to copy a string, with memory allocation and such*/
char* str_duplicate(char*);



/*Function to duplicate a string*/
char* str_duplicate(char* string){
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

/*Function to initialize linked list to keep the history*/
List* init_history(){
  List* history;
  history = (List*)malloc(sizeof(List));
  history->root = NULL;
  return history;
}

/*Function to add an element to end of list*/
void add_history(List* list, char* string){
  if(list->root == NULL){//initialize first value
    list->root = (Item*) malloc(sizeof(Item));
    list->root->id = 1;
    list->root->str = str_duplicate(string);
    list->root->next = NULL;
  }
  else{
    Item* temp;
    temp= (list->root);
    while((temp->next) != NULL){
      temp = temp->next;
    }
    temp->next = (Item*)malloc(sizeof(Item));
    (*temp).next->id = ((*temp).id) + 1;
    (*temp).next->str = str_duplicate(string);
    (*temp).next->next = NULL;

  }
}
char* get_history(List* list, int ident){
  Item* temp;
  if(list->root == NULL)
    return "List is empty";
  temp = (list->root);
  while(temp!=NULL){
    if((*temp).id == ident){
      return (*temp).str;
    }
    temp = temp->next;
  }
  return "ERROR ID NOT FOUND"; //return an empty string basically

}

void print_history(List* list){
  Item* temp;
  temp = (list->root);
  while(temp!=NULL){
    printf("Element %d: %s \n", temp->id, temp->str);
    temp = temp->next;
  }

}

/*Method to free the space used by list and its items*/
void free_history(List* list){
  Item* temp;
  Item* node;
  node = list->root;
  while(node!=NULL){
    temp = node;
    node = node->next;
    free(temp);
  }
  free(list);
}











