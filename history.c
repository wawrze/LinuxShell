/*!
* @file
* @author Mateusz Wawreszuk
*/

#include "shell.h"

/*!
* \brief Array to store commands history.
*/
char **commands_history;
/*!
* \brief Commands history file path - users home directory.
*/
char *history_file_path;
/*!
* \brief Pointer to last position in commands history array.
*/
volatile int history_counter = 0;

/**
* \brief Frees memory, saves commands history to file.
*/
void history_clean_up() {
    save_history_to_file();
    for (int i = 0;i < COMMANDS_HISTORY_SIZE;i++) {
        free(commands_history[i]);
    }
    free(commands_history);
    free(history_file_path);
}

/**
* \brief Initializes commands history.
*
* Allocates commands_history array and reads current history from file.
* Sets history_counter pointer to commands_history size.
*/
void initialize_commands_history() {
    char *homedir;
    char c;
    int i = 0;
    int position = 0;

    commands_history = malloc(COMMANDS_HISTORY_SIZE * sizeof(char*));

    history_file_path = malloc(ARGUMENT_BUFFER_SIZE * sizeof(char));
    if ((homedir = getenv("HOME")) == NULL) {
        homedir = getpwuid(getuid())->pw_dir;
    }
    strcpy(history_file_path, homedir);
    strcat(history_file_path, HISTORY_FILE_NAME);

    FILE *file = fopen(history_file_path, "r");
    commands_history[0] = malloc((INPUT_BUFFER_SIZE + 19)  * sizeof(char));
    if (file != NULL) {
        while ((c = fgetc(file)) != EOF && i < COMMANDS_HISTORY_SIZE) {
            if (c == '\n') {
                commands_history[i][position] = '\0';
                position = 0;
                i++;
                commands_history[i] = malloc((INPUT_BUFFER_SIZE + 19)  * sizeof(char));
            } else {
                (commands_history[i][position]) = c;
                position++;
            }
        }
        fclose(file);
        history_counter = (history_counter + i);
    }

    while (i < COMMANDS_HISTORY_SIZE) {
        commands_history[i] = malloc((INPUT_BUFFER_SIZE + 19)  * sizeof(char));
        commands_history[i][0] = '\0';
        i++;
    }
}

/**
* \brief Prints commands history to standard output.
*
* @return success code
*/
int print_history() {
    int i = 0;

    printf("\nCommands history:\n");
    while (i < 20) {
        if (commands_history[i][0] != '\0') {
            printf("%s\n", commands_history[i]);
        }
        i++;
    }
    printf("\n");
    return 1;
}

/**
* \brief Saves command_history array to file.
*
*/
void save_history_to_file() {
    FILE *file;
    int position = 0;
    int i = 0;
    char c;

    file = fopen(history_file_path, "w");
    if (file != NULL) {
        while (i < 20) {
            if (commands_history[i][0] != '\0') {
                while ((c = commands_history[i][position]) != '\0') {
                    fputc(c, file);
                    position++;
                }
                fputc('\n', file);
                position = 0;
            }
            i++;
        }
        fclose(file);
    }
}

/**
* \brief Saves command to history.
*
* If history_counter pointer points that history is full, removes first command from history.
*
* @param input command to save
*/
void save_to_history(char *input) {
    char *time = get_current_time();

    if (history_counter == COMMANDS_HISTORY_SIZE) {
        for (int i = 1;i < COMMANDS_HISTORY_SIZE;i++) {
            free(commands_history[i - 1]);
            commands_history[i - 1] = malloc((INPUT_BUFFER_SIZE + 19) * sizeof(char));
            strcpy(commands_history[i - 1], commands_history[i]);
        }
        free(commands_history[COMMANDS_HISTORY_SIZE - 1]);
        commands_history[COMMANDS_HISTORY_SIZE - 1] = malloc((INPUT_BUFFER_SIZE + 19)  * sizeof(char));
        strcpy(commands_history[COMMANDS_HISTORY_SIZE - 1], time);
        strcat(commands_history[COMMANDS_HISTORY_SIZE - 1], ": ");
        strcat(commands_history[COMMANDS_HISTORY_SIZE - 1], input);
    } else {
        commands_history[history_counter] = malloc((INPUT_BUFFER_SIZE + 19)  * sizeof(char));
        strcpy(commands_history[history_counter], time);
        strcat(commands_history[history_counter], ": ");
        strcat(commands_history[history_counter], input);
        history_counter++;
    }

    free(time);
}