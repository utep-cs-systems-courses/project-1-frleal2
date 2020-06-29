#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

void read_command();
void read_tokens();


int main(){
  read_command();
}

void read_command(){
  char c;
  char command[50];
  
  while(1){
    printf("Welcome to Tokenizer by Felipe Leal, read the README in order to use this tool or type /h for help, have fun :)");
    printf("#");
    scanf("%s", command);
    if(command[0]=='/'){
      if(command[1] == 'e'){
          printf("Exiting program");
          break;
      }
      else if(command[1] == 't'){
          read_tokens();
      }
      else if(command[1] == 'h'){
          printf("/e: will exit the program.");
          printf("/t: will enter tokenize mode.");
          printf("/h: will print tokenizer commnads (HELP).");
          printf("any input: will be echoed.");
      }
      else{
          printf("Command not recognized");
      }
    }
    else{
      printf("%s \n", command);
    }
    
  }

}

void read_tokens(){
  char com[100];
  List* history = init_history();
  char ** tokens;
  while(1){
    printf("Enter string to tokenize or -q to quit or -!# for history access:");
    scanf(" %99[^\n]s",com);
    if(com[0]== '-'){
      if(com[1] == 'q')
	break;
      else if(com[1] == '!'){
	printf("Searchng for ID %d \n",com[2]-'0'); //we substract character zero to get the numerical equivalent of the char
	tokens = tokenize(get_history(history,com[2]-'0'));
	print_tokens(tokens);
      }
      else
	printf("Command not recognized.");
    }
    else{
      tokens = tokenize(com);
      print_tokens(tokens);
      add_history(history,com);
      free_tokens(tokens);
    }
    printf("\n");
  }
  free_history(history);
}
