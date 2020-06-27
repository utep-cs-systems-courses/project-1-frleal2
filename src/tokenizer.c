#include "tokenizer.h"
#include <stdlib.h>
#include <stdio.h>

/*Function to count the number of characters in a string*/

int string_length(char* string){
    int counter = 0;
    while(*string){
        counter++;
        string++;
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
int find_word_start(char* sentence, int index){
    while(*sentence){
        if(is_valid_character(sentence[index]) == 1){
            return index;
        }
        else{
            index++;
        }
        return index;
    }
}

/*Function to find the end of a word*/
int find_word_end(char* sentence, int index){
    while(*sentence){
        if(is_valid_character(sentence[index]) == 0){
            return index;
        }
        else{
            index++;
        }
        return index;
    }
}











