#include "task_1.hpp"
#include<stdio.h>

/* Initializes list */
void string_list_init(char*** list)
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

/* Destroys list and sets pointer to nullptr. */
void string_list_destroy(char*** list)
{
    for (int i = 0; *list[i]; i++)
    {
        free(*list[i]);
    }
    *list = NULL;
}

/* Inserts value at the end of the list. */
void string_list_append(char** list, char* str)
{
    size_t size = 0;
    while (list[size]) size++;

    char* new_str = (char*)malloc(sizeof(char) * strlen(str));
    strcpy(new_str, str);

    list = (char**)realloc(list, sizeof(char*) * (size+1));
    list[size] = new_str;
    list[++size] = NULL;
}

/* Removes all occurrences of str in the list. */
void string_list_remove(char** list, char *str)
{
    int position = string_list_get_index(list, str);
    int size = string_list_get_size(list);
    if (position < 0) return;

    while (position < size - 1)
    {
        list[position] = list[position + 1];
        position++;
    }

    free(list[position]);
    list[position] = NULL;
}

/* Returns the number of items in the list. */
int string_list_get_size(char** list)
{
    int size = 0;
    while (list[size])
        ++size;

    return size;
}

/* Returns the index position of the first occurrence of str in the list or -1 if no such element. */
int string_list_get_index(char** list, char* str)
{
    for (int i = 0; list[i]; i++) 
        if (strcmp(str, list[i]) == 0) 
            return i;
    return -1;
}

/* Removes duplicate entries from the list. */
void string_list_remove_duplicates(char** list)
{
    int size = string_list_get_size(list);

    for (int i = 0; i < size - 1; i++)
        for (int j = 1; j < size; j++)
            if (list[i] == list[j])
                string_list_remove(list, list[j]);
    

}

/* Sorts the list of strings in ascending order using bubble sort*/
void string_list_sort(char** list)
{
    for (int i = 0; i < (string_list_get_size(list) - 1); i++)
    {
        for (int i = 0; i < (string_list_get_size(list) - 1); i++)
        {
            if (strcmp(list[i], list[i+1]) >  0)
            {
                char* buffer_string = (char*)malloc(sizeof(char*) * strlen(list[i+1]));
                strcpy(buffer_string, list[i+1]);
            
                list[i+1] = (char*)realloc(list[i+1], sizeof(char*) * strlen(list[i]));
                strcpy(list[i+1], list[i]);

                list[i] = (char*)realloc(list[i], sizeof(char*) * strlen(buffer_string));
                strcpy(list[i], buffer_string);
                
                free(buffer_string);
            }
        }
    }
}