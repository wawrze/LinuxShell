/*!
* @file
* @author Mateusz Wawreszuk
*/

#include "shell.h"

/*!
 * @brief Handles signals.
 *
 * Handled signals: SIGQUIT, SIGINT, SIGTSTP.
 *
 * @param signum signal number
 */
void signals_handler(int signum) {
    switch (signum) {
        case SIGQUIT:
            printf("\n");
            print_history();
            break;
        case SIGINT:
            print_process_signal(SIGINT);
            break;
        case SIGTSTP:
            print_process_signal(SIGTSTP);
            break;
        default:
            break;
    }
}