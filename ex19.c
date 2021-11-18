/*
    Este programa imprime a si proprio.
    Autora: Gardenia Georgia Barbosa De Siqueira
    Contato: gardenia.georgia.b.s@gmail.com
*/

#include <stdio.h>

int main(void)
{
    char *s = "/*%c    Este programa imprime a si proprio.%c    Autora: Gardenia Georgia Barbosa De Siqueira%c    Contato: gardenia.georgia.b.s@gmail.com%c*/%c%c#include <stdio.h>%c%cint main(void)%c{%c    char *s = %c%s%c;%c    printf(s,10,10,10,10,10,10,10,10,10,10,34,s,34,10,10,10,10);%c    return 0;%c}%c";
    printf(s,10,10,10,10,10,10,10,10,10,10,34,s,34,10,10,10,10);
    return 0;
}
