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
  char command[100];
  List* history = init_history();
  char ** tokens;
  while(1){
    printf("Enter string to tokenize or /e to exit the program or /l# for history access:");
    scanf(" %99[^\n]s",command);
    if(command[0]== '/'){
      if(command[1] == 'e'){
          printf("Exiting Program");
          break;
      }
      else if(command[1] == 'l'){
          printf("Searchng for ID %d \n",command[2]-'0'); // minus 0 to get real count
          tokens = tokenize(get_history(history,com[2]-'0'));
          print_tokens(tokens);
      }
      else if(command)
      else{
          printf("ERROR, command not recognized, please try again or type /h for help.");
      }
    }
    else{
      tokens = tokenize(command);
      print_tokens(tokens);
      add_history(history,command);
      free_tokens(tokens);
    }
    printf("\n");
  }
  free_history(history);
}
