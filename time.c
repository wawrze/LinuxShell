/*!
* @file
* @author Mateusz Wawreszuk
*/

#include "shell.h"

/**
 * \brief Gets system time and converts it to yyyy-MM-dd hh:mm:ss format.
 *
 * @return current local time as char array
 */
char *get_current_time() {
    time_t rawtime;
    struct tm *timeinfo;
    int day, month, year, hour, minute, second;
    char *current_time = malloc(19 * sizeof(char));
    char tmp_string[4];

    time(&rawtime);
    timeinfo = localtime ( &rawtime );
    day = timeinfo->tm_mday;
    month = timeinfo->tm_mon + 1;
    year = timeinfo->tm_year + 1900;
    hour = timeinfo->tm_hour;
    minute = timeinfo->tm_min;
    second = timeinfo->tm_sec;

    sprintf(tmp_string, "%d", year);
    strcpy(current_time, tmp_string);
    strcat(current_time, "-");

    if (month < 10) {
        strcat(current_time, "0");
    } else {
        strcat(current_time, "");
    }
    sprintf(tmp_string, "%d", month);
    strcat(current_time, tmp_string);
    strcat(current_time, "-");

    if (day < 10) {
        strcat(current_time, "0");
    } else {
        strcat(current_time, "");
    }
    sprintf(tmp_string, "%d", day);
    strcat(current_time, tmp_string);
    strcat(current_time, " ");

    if (hour < 10) {
        strcat(current_time, "0");
    } else {
        strcat(current_time, "");
    }
    sprintf(tmp_string, "%d", hour);
    strcat(current_time, tmp_string);
    strcat(current_time, ":");

    if (minute < 10) {
        strcat(current_time, "0");
    } else {
        strcat(current_time, "");
    }
    sprintf(tmp_string, "%d", minute);
    strcat(current_time, tmp_string);
    strcat(current_time, ":");

    if (second < 10) {
        strcat(current_time, "0");
    } else {
        strcat(current_time, "");
    }
    sprintf(tmp_string, "%d", second);
    strcat(current_time, tmp_string);

    return current_time;
}