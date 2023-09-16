#include "main.h"

char *_strstr(char *haystack, char *needle)
{
    if (haystack == NULL || needle == NULL)
    {
        return NULL;
    }

    
    while (haystack == " ")
    {
        haystack++;
    }

    for (; *haystack != '\0'; haystack++)
    {
        char *a = haystack;
        char *b = needle;

        while (*a == *b && *b != '\0')
        {
            a++;
            b++;
        }

        if (*b == '\0')
        {
            return haystack;
        }
    }

    return NULL;
}
