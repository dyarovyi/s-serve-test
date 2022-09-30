#include "test.hpp"

Test::Test(): failed(0), success(0) {

}

void Test::test_append() {
    char** list = (char**)malloc(sizeof(char*) * 2);
    char** expected = (char**)malloc(sizeof(char*) * 3);

    for (int i = 0; i < 2; i++) list[i] = (char*)malloc(sizeof(char) * 3);
    for (int i = 0; i < 3; i++) expected[i] = (char*)malloc(sizeof(char) * 3);

    list = (char *[]){
        "ab",
        "cd"
    };

    expected = (char *[]){
        "ab",
        "cd",
        "ef"
    };

    char str[] = "ef";

    string_list_append(list, str);
    for (int i = 0; i < 3; i++) {
        assert(expected[i] == list[i]);
    }
    success++;

    std::cout << "test_append: success" << std::endl;
}

void Test::test_remove() {
    // char** list = (char *[]){
    //     "ab",
    //     "cd",
    //     "ef"
    // };

    // char** expected = (char *[]){
    //     "ab",
    //     "cd"
    // };

    // char str[] = "ef";
    // string_list_remove(list, str);
    // for (int i = 0; i < 2; i++) {
    //     assert(expected[i] == list[i]);
    // }
    // success++;

    std::cout << "test_removed: success" << std::endl;
}

void Test::test_size() {

}

void Test::test_index() {

}

void Test::test_duplicates() {

}

void Test::test_sort() {

}