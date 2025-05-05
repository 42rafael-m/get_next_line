#include <string.h>
#include "get_next_line.h"

int main()
{
    char    *r;
    char *str = strdup("holaque");
    char *str2 = strdup("tal");
    
    r = ft_strjoin(str, str2);
    int len = ft_strlen(r);
    printf("len = %d\n", len);
    printf("%s\n", r);
    free (str);
    char*s = str + 8;
}