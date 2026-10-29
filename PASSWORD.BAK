#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
void main()
{
int i, len;
char pool[] = "abcdefghijklmnopqrstvuwxyz"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"1234567890";
int poolSize = sizeof(pool) - 1;
clrscr();
randomize();
printf("Enter the Length: ");
scanf("%d", &len);

for(i=0;i<len;i++)
{
int randomindex = random(poolSize);
textcolor(5);
cprintf("Your Password is: %c\n", pool[randomindex]);
}
getch();
}
