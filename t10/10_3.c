#include <stdio.h>
#include <stdbool.h>
#include <time.h>
typedef struct Date { int day, month, year; } Date;
bool validDate(Date d) {
    struct tm t={0}; t.tm_mday=d.day; t.tm_mon=d.month-1; t.tm_year=d.year-1900; t.tm_hour=12;
    if (d.year<1900 || d.year>9999 || d.month<1 || d.month>12 || d.day<1 || d.day>31) return false;
    if (mktime(&t)==(time_t)-1) return false;
    return t.tm_mday==d.day && t.tm_mon==d.month-1 && t.tm_year==d.year-1900;
}
Date tomorrow(Date d) {
    struct tm t={0}; t.tm_mday=d.day+1; t.tm_mon=d.month-1; t.tm_year=d.year-1900; t.tm_hour=12;
    mktime(&t); return (Date){t.tm_mday,t.tm_mon+1,t.tm_year+1900};
}
int weekday(Date d) { // 0=Sunday, 1=Monday, ..., 6=Saturday
    struct tm t={0}; t.tm_mday=d.day; t.tm_mon=d.month-1; t.tm_year=d.year-1900; t.tm_hour=12;
    mktime(&t); return t.tm_wday;
}
int main() {
    Date d; printf("Date (day month year): ");
    if (scanf("%d%d%d", &d.day,&d.month,&d.year)!=3 || !validDate(d)) { printf("Invalid date\n"); return 1; }
    Date next=tomorrow(d);
    printf("Tomorrow: %02d.%02d.%04d\n",next.day,next.month,next.year);
    time_t now=time(NULL); struct tm* cur=localtime(&now);
    if (d.year==cur->tm_year+1900) {
        const char* days[]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
        printf("Weekday: %s\n",days[weekday(d)]);
    } else printf("Weekday is requested for a date in the current year only.\n");
    return 0;
}
