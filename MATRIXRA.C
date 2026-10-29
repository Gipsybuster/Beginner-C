#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <dos.h>
void main()
{
clrscr();
textcolor(GREEN);
textbackground(BLACK);

while(!kbhit())
{
cprintf("%c", 33 + rand() % 94);
if (rand() % 50 == 0)
{
cprintf("\n\r");
}
}
getch();
}