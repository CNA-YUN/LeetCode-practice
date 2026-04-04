#include <malloc.h>
#include <stdio.h>
typedef struct {
    int calendar[1000][2];
} MyCalendar;


MyCalendar* myCalendarCreate() {
    MyCalendar mycalendar;
    for (int i = 0;i < 1000;i++) {
        for (int j = 0;j < 2;j++) {
            mycalendar.calendar[i][j] = 0;
        }
    }

    MyCalendar* p = &mycalendar;
    return p;
}

bool myCalendarBook(MyCalendar* obj, int startTime, int endTime) {
    for (int i = 0;i < 1000;i++) {
        if (obj->calendar[i][0] <= startTime && startTime < obj->calendar[i][1]) {
            return false;
        }
        else if (obj->calendar[i][0] < endTime && endTime <= obj->calendar[i][1]) {
            return false;
        }
        else if (startTime <= obj->calendar[i][0] && obj->calendar[i][1] <= endTime) {
            return false;
        }
        if (obj->calendar[i][0] == obj->calendar[i][1]) {
            obj->calendar[i][0] = startTime;
            obj->calendar[i][1] = endTime;
            return true;
        }
        return true;
    }
    return true;
}

void myCalendarFree(MyCalendar* obj) {
    free(obj);
}
/**
 * Your MyCalendar struct will be instantiated and called as such:
 * MyCalendar* obj = myCalendarCreate();
 * bool param_1 = myCalendarBook(obj, startTime, endTime);

 * myCalendarFree(obj);
*/
void problem729() {
    MyCalendar* obj = myCalendarCreate();
    bool param_1= myCalendarBook(obj, 10, 20);
    bool param_4 = myCalendarBook(obj, 20, 30);
    bool param_2 = myCalendarBook(obj, 15, 25);
    bool param_3 = myCalendarBook(obj, 9, 31);
    printf("%d\n", param_1);
    printf("%d\n", param_4);
    printf("%d\n", param_2);
    printf("%d\n", param_3);

    //myCalendarFree(obj);
}