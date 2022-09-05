#include "task_4.hpp"

void set(Date &date, DatePiece date_piece, unsigned bit)
{
    switch (date_piece) {
        case 0 : date.nWeekDay |= 1 << bit; break;
        case 1 : date.nMonthDay |= 1 << bit; break;
        case 2 : date.nMonth |= 1 << bit; break;
        case 3 : date.nYear |= 1 << bit; break;
    }
}

void reset(Date &date, DatePiece date_piece, unsigned bit)
{
    switch (date_piece) {
        case 0 : date.nWeekDay &= ~(1 << bit); break;
        case 1 : date.nMonthDay &= ~(1 << bit); break;
        case 2 : date.nMonth &= ~(1 << bit); break;
        case 3 : date.nYear &= ~(1 << bit); break;
    }
}

void invert(Date &date, DatePiece date_piece, unsigned bit) 
{
    switch (date_piece) {
        case 0 : date.nWeekDay ^= 1 << bit; break;
        case 1 : date.nMonthDay ^= 1 << bit; break;
        case 2 : date.nMonth ^= 1 << bit; break;
        case 3 : date.nYear ^= 1 << bit; break;
    }
}