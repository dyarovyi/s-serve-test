#include <iostream>

#include "task_1.cpp"

class Test {
    int failed;
    int success;

public:
    Test();

    void test_append();
    void test_remove();
    void test_size();
    void test_index();
    void test_duplicates();
    void test_sort();
};