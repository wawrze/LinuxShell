/*!
* @file
* @author Mateusz Wawreszuk
*/

#include "shell.h"

/**
* \brief Change directory command.
*
* If change is not possible, prints to standard output error message.
*
* @param args directory
* @return execution success or error code
*/
int cd(char **args) {
    if (args[1] == NULL) {
        printf("You have to pass argument to \"cd\" command!\n");
    } else {
        switch (chdir(args[1])) {
            case EACCES:
                printf("Access denied!\n");
                break;
            case ELOOP:
                printf("Loop in symbolic links!\n");
                break;
            case ENAMETOOLONG:
                printf("Path too long!\n");
                break;
            case ENOENT:
                printf("There is no directory \"%s\"!\n", args[1]);
                break;
            case ENOTDIR:
                printf("Some component of pathname is not a directory!\n");
                break;
            case 0:
                update_prompt();
                break;
            default:
                printf("There is no directory \"%s\"!\n", args[1]);
                break;
        }
    }
    return 1;
}

/**
* \brief Calls built-in command.
*
* @param command_number number of command in built_in_commands array
* @param args arguments
* @return execution success or error code
*/
int execute_command(int command_number, char **args) {
    switch (command_number) {
        case 0:
            return cd(args);
        case 1:
            return help();
        case 2:
            return print_history();
        case 3:
            return print_time();
        case 4:
            printf("Goodbye!\n");
            return 0;
        default:
            return 1;
    }
}

/**
* \brief Prints list of built-in commands and other functionalities.
*
* @return success code
*/
int help() {
    printf("\nPossible commands:\n\n");
    printf("cd [dir]\tChange working directory to \"dir\".\n");
    printf("help\t\tDisplay this help.\n");
    printf("history\t\t(or ctrl + \\) Display last %i commands.\n", COMMANDS_HISTORY_SIZE);
    printf("time\t\tDisplay current date and time.\n");
    printf("exit\t\tExit shell.\n\n");
    printf("To run program in background, put \"&\" as last argument.\n\n");
    return 1;
}

/**
* \brief Prints current date and time.
*
* @return success code
*/
int print_time() {
    char *time = get_current_time();

    printf("\n%s\n\n", time);

    return 1;
}