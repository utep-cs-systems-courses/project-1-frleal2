#include "tokenizer.h"
#include <stdlib.h>
#include <stdio.h>

/*Function to count the number of characters in a string*/

int string_length(char* str){
  int counter = 0;
  while(*str++){
    ++counter;
  }
  
  return counter;
}

/*Evaluates weather a character is valid or invalid*/
char is_valid_character(char c){
    switch(c){     //switch method allows you to try different cases
        case '\v':
        case '\\':
        case '\'':
        case '\"':
        case ' ':
        case '\0':
        case '\n':
        case '\t':
        case '\b':
        case '\a':
        case '\f':
        case '\r': 
            return 0;
        default:
            return 1;
    }
}

/*Function to find the start of a word*/
int find_word_start(char* line, int index){
  if(!is_valid_character(line[index])){ //first we check if we are in a valid character, if not we look for one
    while(!is_valid_character(line[index])){
      index++;
    }
  }else{//we are in a valid character, so we are the word beginning
    return index;
  }
  return index;
}

/*Function to find the end of a word*/
int find_word_end(char* line, int index){
  int beg_of_word = find_word_start(line, index);
  //Now having the beginning we can get to the end
  while(is_valid_character(line[beg_of_word])){
    beg_of_word++;//when the loop is done this will be the end of the word
  }
  //here we went one over the end so we just return
  beg_of_word--;
  return beg_of_word;

}

/*Function to find the number of words there is in a line or sentence*/
int count_words(char* line){
    int counter = 0;//counts words
    int index = 0;
    short end = 0;
    short length = string_length(line);
    while(1){
      index = find_word_start(line, index);
      if(index>=length) break;
      counter ++;
      end = find_word_end(line, index);
      index = end+1;
    }
    return counter;
  }

/* Function that prints all tokens*/
void print_tokens(char** tokens){
    while(*tokens){
        printf("[%s]", *tokens);
        tokens++;
    }
}

/*Function that frees all tokens and the array containing the tokens. */
void free_tokens(char** tokens){
    while(*tokens){
        free(*tokens);
        tokens++;
    }
    free(tokens);
}

/*Function that tokenizes the string that is passed on to the argument into an array of tokens*/
char** tokenize(char* line){
  short num_words = count_words(line);
  short word_leng =0;
  int index = 0;
  char** tokens = (char**) malloc((num_words+1)*sizeof(char*));//we allocate memory for the number of pointers needed
  
  for(short i=0;i<num_words;i++){ //we will calculate length of each string and allocate memory for each
    word_leng = (find_word_end(line, index) - find_word_start(line, index)) + 1;
    tokens[i] =(char *) malloc((word_leng + 1)*sizeof(char));//we allocate one extra for the NULL character
    index = find_word_start(line, index);
    for(short j = 0;j<word_leng;j++){
      tokens[i][j] = line[index+j];
    }
    index = (find_word_end(line, index) +1);
  }
  tokens[num_words] = (char*) malloc(sizeof(char));
  tokens[num_words] = '\0';
  return tokens;
}













