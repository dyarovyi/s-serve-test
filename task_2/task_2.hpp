#include <iostream>

using std::cout;
using std::cin;
using std::endl;

class AnyType
{
    void* value;

public:
    AnyType();
    AnyType(bool value);
    AnyType(char value);
    AnyType(int value);
    AnyType(float value);

    bool isBool = false;
    bool isChar = false;
    bool isInt = false;
    bool isFloat = false;

    bool toBool();
    char toChar();
    int toInt();
    float toFloat();

    void setValue(void* new_value);
    void* getValue();

    void swap(AnyType& B);

    AnyType& operator = (AnyType& b);
};