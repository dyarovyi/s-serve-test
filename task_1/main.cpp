#include <stdio.h>

// #include "task_1.cpp"
#include "test.cpp"

/* Read list from console */
void string_list_read_from_console(char*** list)
{
    size_t size = 0;
    printf("Enter number of strings to enter: ");
    scanf("%ld", &size);

    char** list_buffer = (char**)malloc(sizeof(char*) * (size + 1));
    
    size_t MAX_STR_LEN = 256;
    char *str_buffer = NULL;
    printf("Enter strings:\n");
    getchar();

    size_t i;
    for (i = 0; i < size; i++)
    {
        getline(&str_buffer, &MAX_STR_LEN, stdin);
        list_buffer[i] = (char*)malloc(sizeof(char) * strlen(str_buffer));
        strcpy(list_buffer[i], str_buffer);
    }
    list_buffer[i] = NULL;

    free(str_buffer);
    *list = list_buffer;
}

/* Prints out list of strings */
void string_list_print(char** list)
{
    printf("::::::::::::::::::::::::::::\n");
    printf("Here is the content of list:\n");
    for (size_t i = 0; list[i]; i++)
    {
        printf("%s\n", list[i]);
    }
    printf("::::::::::::::::::::::::::::\n");
}

int main()
{
    char **list = NULL;

    Test *UT = new Test();
    UT->test_append(); 

    // string_list_read_from_console(&list);
    // string_list_print(list);

    // char str0[] = "x";
    // string_list_append(list, str0);
    // string_list_print(list);

    // char str1[] = "y";
    // string_list_append(list, str1);
    // string_list_print(list);

    // char str2[] = "z";
    // string_list_append(list, str2);
    // string_list_print(list);

    // char str[] = "b\n";
    //string_list_destroy(&list);
    // string_list_remove(list, str);
    // string_list_print(list);
    //printf("%d", string_list_get_index(list, str));

// void string_list_init(char*** list);
// void string_list_destroy(char** list);
// void string_list_append(char** list, char* str);
// void string_list_remove(char** list, char *str);
// void string_list_remove_duplicates(char** list);
// void string_list_replace_in_strings(char** list, char* before, char* after);
// void string_list_sort(char** list);

    return 0;
}