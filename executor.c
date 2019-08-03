/*!
* @file
* @author Mateusz Wawreszuk
*/

#include "shell.h"

/*!
* \brief Array of built in commands.
*/
char *built_in_commands[] = {"cd", "help", "history", "time", "exit"};
/*!
* \brief Last executed program name.
*/
char active_process_name[INPUT_BUFFER_SIZE];
/*!
* \brief Id of process that executes program.
*/
int active_process_id;

/**
* \brief Calls built-in command or executes external program.
*
* Checks if program should be executed in background (first argument is "&").
*
* @param args array of command and its arguments
* @return execution success or error code
*/
int execute_command_or_program(char **args) {
    int i = 0;
    int exec_in_bg = 0;
    if (args[0] == NULL || strncmp(args[0], "&", 2) == 0) {
        return 1;
    }
    while (args[i] != NULL) i++;
    if (strncmp(args[i - 1], "&", 2) == 0) {
        args[i - 1] = NULL;
        exec_in_bg = 1;
    }
    for (i = 0; i < 5; i++) {
        if (strcmp(args[0], built_in_commands[i]) == 0) {
            return execute_command(i, args);
        }
    }
    return execute_program(args, exec_in_bg);
}

/**
* \brief Executes external program.
*
* @param args array of command and its arguments
* @param exec_in_bg 1 if program should be executed in background, 0 if not
* @return WYJSCIE
*/
int execute_program(char **args, int exec_in_bg) {
    pid_t pid;

    pid = fork();
    if (pid == 0) {
        if (execvp(args[0], args) < 0) {
            printf("\"%s\" is not correct command or executable!\n", args[0]);
        }
        return 0;
    } else if (pid < 0) {
        return 0;
    } else {
        if (!exec_in_bg) {
            strcpy(active_process_name, args[0]);
            active_process_id = pid;
            while ((wait(NULL)) > 0);
            active_process_id = 0;
        }
    }

    return 1;
}

/**
* \brief Prints information witch process has been killed.
*
* @param signum signal number
*/
void print_process_signal(int signum) {
    if (active_process_id != 0) {
        switch (signum) {
            case SIGINT:
                printf("\n\nKill signal sent to process %i (\"%s\")\n\n", active_process_id, active_process_name);
                break;
            case SIGTSTP:
                printf("\n\nStop signal sent to process %i (\"%s\")\n\n", active_process_id, active_process_name);
                break;
            default:
                break;
        }
    }
}