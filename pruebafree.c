#include <string.h>
int main()
{
    char *str = strdup("holaquetal");
    
    //str += 2;
    str[5] = '\0';
    free (str);
    char*s = str + 8;
}