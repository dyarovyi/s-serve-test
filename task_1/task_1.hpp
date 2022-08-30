#include <stdlib.h>
#include <string.h>

/* Initializes list */
void string_list_init(char*** list);

/* Destroys list and sets pointer to nullptr. */
void string_list_destroy(char*** list);

/* Inserts value at the end of the list. */
void string_list_append(char** list, char* str);

/* Removes all occurrences of str in the list. */
void string_list_remove(char** list, char *str);

/* Returns the number of items in the list. */
int string_list_get_size(char** list);

/* Returns the index position of the first occurrence of str in the list. */
int string_list_get_index(char** list, char* str);

/* Removes duplicate entries from the list. */
void string_list_remove_duplicates(char** list);

/* Replaces every occurrence of the before, in each of the string lists's strings, with after. */
void string_list_replace_in_strings(char** list, char* before, char* after);

/* Sorts the list of strings in ascending order */
void string_list_sort(char** list);