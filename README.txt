The program consists of three C files.
  1) UI.c
    This file contains all the code related to the interaction with the user, it translates the commands to their proper action.
    The commands must start with a dash (-) followed by a letter or a combination of characters. Specifically the main UI supports two commands:
      -q: This exits the program.
      -t: this enters the tokenizer mode. 
    Any other text that is inputted will be echoed, or any commands not supported will be discarded and the user will get a message telling it that the command is not recognized.
    
    Now, to the tokenizing mode.
    In this mode there are two commands available:
      -q: again this exits to the previous UI
      -!#: this tries to recall a certain item in history, the # has to be subtituted by a number, the history number that one wants.
    Any other text entered will be tokenized directly, and the program will print the tokens.
    
   2) tokenizer.c
    The tokenizer file contains the definitions of the different functions used by the UI, it does not contain a main and should only be compiled with the rest, not executed on its own.
    
   3)history.c
   This file contains the definition of methods to provide a history, with the use of a linked list of struct types.
   
The program also contains a makefile, this makefile when called will compile the three C files and will generate an executable file named "program" that will start the program. When called with the command "clean" the makefile will remove all generated files including the executable.

So to use the program one must execute the command "make", then execute the file "program" and there one will be at the program command line. From there one uses the commands as stated before. In general the program will not fail if different input that is not the commands is entered, but such things are still discouraged, for the most part if one does not type a valid command, the text will be just echoed.

Summary:
  1) Execute command "make"
  2) Execute "program" file.
  3) Use only commands '-t' or '-q' when in main command line, any other text will be echoed.
  4) To enter tokenize mode use '-t'
  5) To tokenize a line type that line and just press enter.
  6) To access a history item use '-!#' and subsitute '#' for the desired number.
  7) To quit from that command line use '-q'
  
  
  
