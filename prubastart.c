#include "get_next_line.h"
#include <string.h>
#define BUFFER_SIZE 25

int main(void)
{
    char    *line;
    char *start = strdup("Hola\nque\ntal");
    int start_len;

    start_len = 0;
    while (start[start_len] && start_len < BUFFER_SIZE)
    {   
        printf ("start_len = %d\n", start_len);
        if (start[start_len] == '\n')
        {
            line = ft_strdup(start);
            line[start_len] = '\0';
            start += (++start_len);
        }
        start_len++;
    }
    if (start[start_len] == '\0')
    {
        line = ft_strdup(start);
        free (start);
        start = NULL;
    }
        
}