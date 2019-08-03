/*!
* @file
* @author Mateusz Wawreszuk
*/

#include "shell.h"

/*!
* @brief Shells main function.
*
* @param argc arguments count
* @param argv arguments array
* @return EXIT_SUCCESS or error code
*/
int main(int argc, char **argv) {
    signal(SIGQUIT, signals_handler);
    signal(SIGINT, signals_handler);
    signal(SIGTSTP, signals_handler);
    if (argc > 1) {
        main_loop_file(argv[1]);
    } else {
        main_loop();
    }
    clean_up();
    exit(EXIT_SUCCESS);
}

/*!
* @brief Cleans up before exit.
*
* Frees memory and saves commands history to file.
*/
void clean_up() {
    read_clean_up();
    history_clean_up();
}