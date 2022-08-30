#include "task_2.hpp"

AnyType::AnyType()
{
    value = nullptr;
}

AnyType::AnyType(bool new_value)
{
    value = new bool(new_value);
    isBool = true;
}

AnyType::AnyType(char new_value)
{
    value = new char(new_value);
    isChar = true;
}

AnyType::AnyType(int new_value)
{
    value = new int(new_value);
    isInt = true;
}

AnyType::AnyType(float new_value)
{
    value = new float(new_value);
    isFloat = true;
}

AnyType::~AnyType()
{
    value = nullptr;
}

bool AnyType::toBool()
{
    value = (bool*)(value);
    return *(bool*)(value);
}

char AnyType::toChar()
{
    value = (char*)(value);
    return *(char*)(value);
}

int AnyType::toInt()
{
    value = (int*)(value);
    return *(int*)(value);
}

float AnyType::toFloat()
{
    value = (float*)(value);
    return *(float*)(value);
}

void AnyType::setValue(void* new_value)
{
    value = new_value;
}

void* AnyType::getValue()
{
    return value;
}

void AnyType::swap(AnyType& B)
{
    static void* temp = B.getValue();
    B.setValue(getValue());
    setValue(temp);
}

AnyType& AnyType::operator = (AnyType& B)
{
    if (isBool)
    {
        static AnyType a = AnyType(*(bool*)B.getValue());
        return a;
    }
    else if (isChar)
    {
        static AnyType a = AnyType(*(char*)B.getValue());
        return a;
    }
    else if (isInt)
    {
        static AnyType a = AnyType(*(int*)B.getValue());
        return a;
    }
    else 
    {
        static AnyType a = AnyType(*(float*)B.getValue());
        return a;
    }
}

AnyType& AnyType::operator = (bool b)
{
    static AnyType a = AnyType(b);
    return a;
}

AnyType& AnyType::operator = (char c)
{
    static AnyType a = AnyType(c);
    return a;
}

AnyType& AnyType::operator = (int i)
{
    static AnyType a = AnyType(i);
    return a;
}

AnyType& AnyType::operator = (float f)
{
    static AnyType a = AnyType(f);
    return a;
}