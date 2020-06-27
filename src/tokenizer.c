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

char is_valid_character(char c){
    switch(c){
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



