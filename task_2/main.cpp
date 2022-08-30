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

    //cout << typeid(a->toChar()).name() << endl;
    return 0;
}