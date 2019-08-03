/*!
* @file
* @author Mateusz Wawreszuk
*/

/*! \mainpage shell - Description.
\htmlinclude main_page.html
*/

#include <errno.h>
#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <time.h>

/*!
* \brief Name of file storing commands history, path is always set to users home directory.
*/
#define HISTORY_FILE_NAME "/.shellhistory"
/*!
* \brief Number of commands to store in commands history file.
*/
#define COMMANDS_HISTORY_SIZE 20
/*!
* \brief Maximum number of characters in single input line.
*/
#define INPUT_BUFFER_SIZE 1024
/*!
* \brief Maximum number of characters in command prompt.
*/
#define COMMAND_PROMPT_MAX_SIZE 128
/*!
* \brief Maximum number of parameters for single command.
*/
#define ARGUMENT_BUFFER_SIZE 64
/*!
* \brief Command arguments delimiters.
*/
#define DELIMITERS " \t\r\n\a"

int cd(char **args);
void clean_up();
int execute_command(int command_number, char **args);
int execute_command_or_program(char **args);
int execute_program(char **args, int exec_in_bg);
char *get_current_time();
int help();
void history_clean_up();
void initialize_commands_history();
void main_loop();
void main_loop_file(char *filename);
int print_history();
void print_process_signal(int signum);
void print_prompt();
int print_time();
void read_clean_up();
char *read_line();
void save_history_to_file();
void save_to_history(char *input);
void signals_handler(int signum);
char **split_input(char *input);
void update_prompt();