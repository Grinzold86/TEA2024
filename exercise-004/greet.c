#include <stdio.h> // wird für putc benötigt
#include "greet.h" // vorwärtsdeklaration

void gruss(void)
{
    putc('A', stdout);
    putc('\n', stdout);
}