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
            sentence++;
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
            sentence++;
        }
        return index;
    }
}

/*Function to find the number of words there is in a line or sentence*/
int count_words(char* sentence){
    int words = 0;
    int start_of_word = 0;
    int end_of_word = 0;
    int sentence_length = string_length(sentence);

    while(*sentence){
        if(start_of_word >= sentence_length){
            break;
        }
        start_of_word = find_word_start(sentence, start_of_word);
        end_of_word = find_word_end(sentence, start_of_word);
        words++;
        sentence++;
    }
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
char** tokenize(char* sentence){
    int num_words = count_words(sentence);
    int index = 0;

    char** tokens = (char**) malloc((num_words + 1) * sizeof(char*)); //allocate memory for pointers
    
    for (size_t i = 0; i < num_words; i++)
    {
        int index = find_word_start(sentence, index);
        int end_word = find_word_end(sentence, index);
        int word_length = (end_word - index);
        word_length++;

        tokens[i] = (char*) malloc((word_length + 1) * sizeof(char)); //allocate memory for each word plus extra char for NULL
        
        for (size_t j = 0; j < word_length; j++)
        {
            tokens[i][j] = sentence[index + j];
        }
        index = (find_word_end(sentence, index) + 1);
    }

    tokens[num_words] = (char*) malloc(sizeof(char));
    tokens[num_words] = '\0';
    return tokens;
}













