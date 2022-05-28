#include <stdio.h>

struct Date{
    int day;
    int month;
    int year;
} ;

struct Date inputDate(){
    int d,m,y;
    printf("input day:");
    scanf("%d",&d);
    printf("input month:");
    scanf("%d",&m);
    printf("input year:");
    scanf("%d",&y);
    
    struct Date res = {d,m,y};
    return res;
}

int inputDate2(struct Date * date){
    printf("input day:");
    scanf("%d",&date->day);
    printf("input month:");
    scanf("%d",&(*date).month);
    printf("input year:");
    scanf("%d",&date->year);
    return 0;
}

void printDate(struct Date date1){
    printf("%d.%d.%d \n",date1.day,date1.month,date1.year);
}

int main(){
    struct Date date1;
    date1.day = 12;
    date1.month = 10;
    date1.year = 2021;
    printDate(date1);
    
    struct Date date2, date3;
    date2 = inputDate();
    printDate(date2);
    
    inputDate2(&date3);
    printDate(date3);
}
