#include <iostream>

enum DatePiece {
    WeekDay,
    MonthDay,
    Month,
    Year
};

struct Date {
    unsigned nWeekDay : 3;
    unsigned nMonthDay : 6;
    unsigned nMonth : 5;
    unsigned nYear : 8;
};

void set(Date &date, DatePiece datePiece, unsigned bit);
void reset(Date &date, DatePiece datePiece, unsigned bit);
void invert(Date &date, DatePiece datePiece, unsigned bit);