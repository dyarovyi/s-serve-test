#include "task_4.cpp"

#define SIZE 9

int main() {
    Date date[SIZE] = { 
        { 3, 9, 7, 20 },
        { 5, 23, 9, 90 },
        { 6, 15, 9, 99 },
        { 6, 17, 5, 11 },
        { 5, 3, 3, 3 },
        { 6, 23, 11, 15 },
        { 6, 9, 7, 38 },
        { 1, 23, 9, 8 },
        { 0, 0, 9, 21 }
    };
    
    std::cout << "Sizeof date: " << SIZE << std::endl;

    for (int i = 0; i < sizeof(date); i++) {
        if (date[i].nYear >= 0 && date[i].nYear <= 22 && date[i].nMonth == 9) {
            set(date[i], MonthDay, 2);
            std::cout << date[i].nMonthDay << std::endl;
            reset(date[i], MonthDay, 2);
            std::cout << date[i].nMonthDay << std::endl;
            invert(date[i], MonthDay, 2);
            std::cout << date[i].nMonthDay << std::endl;
        }
    }

    return 0;
}