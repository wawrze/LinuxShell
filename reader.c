/*!
* @file
* @author Mateusz Wawreszuk
*/

#include "shell.h"

/*!
* \brief Array of characters to store command prompt.
*/
char *command_prompt;
/*!
* \brief Array of characters to store current users name.
*/
char *username;

/**
* \brief Waits for input and executes it.
*/
void main_loop() {
    command_prompt = malloc(COMMAND_PROMPT_MAX_SIZE * sizeof(char));
    update_prompt();
    do {
        print_prompt();
    } while (execute_command_or_program(split_input(read_line())));
}

/**
* \brief Reads script file and executes every line.
*
* @param filename script file name and path
*/
void main_loop_file(char *filename) {
    char *input = malloc(INPUT_BUFFER_SIZE * sizeof(char));
    int position = 0;
    char c;
    FILE *file;
    file = fopen(filename, "r");

    if (file == NULL) {
        printf("\"%s\": File doesn't exist!", "r");
        clean_up();
        exit(EXIT_FAILURE);
    }

    while ((c = fgetc(file)) != EOF) {
        if (c == '\n') {
            input[position] = '\0';
            position = 0;
            if (strncmp(input, "#", 1) == 0) {
                continue;
            } else {
                execute_command_or_program(split_input(input));
            }
        } else {
            input[position] = c;
            position++;
        }
    }

    fclose(file);
}

/**
* \brief Prints command prompt.
*
* Command prompt contains: current user, current working directory, # if current user is superuser or $ for other users
*/
void print_prompt() {
    printf("%s", command_prompt);
}

/**
* \brief Frees memory.
*/
void read_clean_up() {
    free(command_prompt);
}

/**
* \brief Reads one line from standard input.
*
* @return line as char array
*/
char *read_line() {
    char *input = malloc(INPUT_BUFFER_SIZE * sizeof(char));
    int input_position = 0;
    char c;

    while (1) {
        scanf("%c", &c);

        switch (c) {
            case '\n':
                input[input_position] = '\0';
                save_to_history(input);
                return input;
            case EOF:
                clean_up();
                exit(EXIT_SUCCESS);
            default:
                input[input_position] = c;
        }
        input_position++;

        if(input_position == INPUT_BUFFER_SIZE) {
            input = realloc(input, sizeof(input) + INPUT_BUFFER_SIZE);
        }
    }
}

/**
* \brief Splits input to words (command and its arguments).
*
* @param input single input line
* @return array of command and arguments
*/
char **split_input(char *input) {
    int argument_counter = 0;
    char **arguments = malloc(INPUT_BUFFER_SIZE * ARGUMENT_BUFFER_SIZE * sizeof(char*));
    char *argument;
    argument = strtok(input, DELIMITERS);
    while (argument != NULL) {
        arguments[argument_counter] = argument;
        argument_counter++;
        argument = strtok(NULL, DELIMITERS);
    }
    arguments[argument_counter] = NULL;
    return arguments;
}

/**
* \brief Updates prompt with username and current path.
*/
void update_prompt() {
    char pwd[COMMAND_PROMPT_MAX_SIZE];
    char *new_username;
    if (username == NULL) {
        username = malloc(ARGUMENT_BUFFER_SIZE * sizeof(char));
        username[0] = '\0';
    }

    getcwd(pwd, sizeof(pwd));
    if (strcmp(new_username = getenv("USER"), username) != 0) {
        initialize_commands_history();
    }
    username = new_username;

    if (command_prompt != NULL) {
        strcpy(command_prompt, username);
        strcat(command_prompt, ":");
        strcat(command_prompt, pwd);
        if (geteuid() != 0) {
            strcat(command_prompt, "$ ");
        } else {
            strcat(command_prompt, "# ");
        }
    }
}