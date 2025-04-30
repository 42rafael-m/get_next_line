#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int main(void)
{
    char    **s = NULL;
    char    *str;
    int i = 0;
    
    str = ft_strndup("holaa", 4);
    s = &str;
    printf("%p\n", *s);
    printf("%p\n", str);
    while (**s)
    {
        printf("%c\n", **s);
        *s++;
    }
    free (*s);
}