#include "task_2.cpp"

int main()
{
    AnyType *a = new AnyType(false);
    cout << a->toInt() << endl;
    cout << a->toBool() << endl;
    cout << a->toChar() << endl;
    cout << a->toFloat() << endl;

    AnyType *b = new AnyType(true);

    a = b;
    cout << a->toInt() << endl;
    cout << a->toBool() << endl;
    cout << a->toChar() << endl;
    cout << a->toFloat() << endl;

    AnyType c(2);
    c = 5;
    cout << c.toInt() << endl;
    cout << c.toBool() << endl;
    cout << c.toChar() << endl;
    cout << c.toFloat() << endl;
    //cout << typeid(a->toChar()).name() << endl;

    a->swap(c);
    cout << a->toBool() << endl;
    cout << c.toBool() << endl;
    return 0;
}