#pragma once
typedef struct {
    int calendar[1000][2];
} MyCalendar;
MyCalendar* myCalendarCreate();
void myCalendarFree(MyCalendar* obj);
bool myCalendarBook(MyCalendar* obj, int startTime, int endTime);
void problem729();