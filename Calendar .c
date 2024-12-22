#include <stdio.h>

int getFirstDayofTheYear(int year) {
    int day = (year * 365 + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400) % 7;
    return day;
}

int main() {
    char *months[] = {"January", "February", "March", "April", "May", "June", "July", 
                      "August", "September", "October", "November", "December"};
    int daysinMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int i, j, totalDays, weekday = 0, spaceCounter = 0, year;

    printf("Enter your favorite year:\n");
    scanf("%d", &year);

    printf("Welcome to %d\n", year);

    // Check for leap year
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        daysinMonth[1] = 29;
    }

    // Get the first day of the year
    weekday = getFirstDayofTheYear(year);

    for (i = 0; i < 12; i++) {
        printf("\n\n\n-------%s------\n", months[i]);
        printf("\n Sun Mon Tue Wed Thu Fri Sat \n");

        for (spaceCounter = 1; spaceCounter <= weekday; spaceCounter++) {
            printf("    "); // 4 spaces
        }

        totalDays = daysinMonth[i];
        for (j = 1; j <= totalDays; j++) {
            printf("%4d", j); // 4 spaces
            weekday++;
            if (weekday > 6) {
                weekday = 0;
                printf("\n");
            }
        }
    }

    return 0;
}
