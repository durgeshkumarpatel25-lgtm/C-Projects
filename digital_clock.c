#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>  // for sleep()

void fill_time(char* buffer);
void fill_date(char* buffer);

int main() {
    char time_str[50], date[100];

    while(1) {
        fill_time(time_str);
        fill_date(date);

        printf("\rDate: %s | Current time: %s", date, time_str); // overwrite same line
        fflush(stdout);
        sleep(1);
    }

    return 0;
}

void fill_time(char* buffer) {
    time_t raw_time;
    struct tm *current_time;

    time(&raw_time);
    current_time = localtime(&raw_time);

    strftime(buffer, 50, "%I:%M:%S %p", current_time);
}

void fill_date(char* buffer) {
    time_t raw_time;
    struct tm *current_time;

    time(&raw_time);
    current_time = localtime(&raw_time);

    strftime(buffer, 100, "%Y-%m-%d", current_time);
}