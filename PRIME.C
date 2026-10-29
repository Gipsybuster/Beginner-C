#include <stdio.h>
#include <conio.h>
void main()
{
int num, i, count=0;
clrscr();
printf("Enter the numbers: ");
scanf("%d", &num);
for(i = 1; i <= num; i++)
{
if(num % i == 0)
{
count++;
}
}
if (count == 2)
{
textcolor(2);
cprintf("%d is a PRIME number", num);
}
else
{
textcolor(9);
cprintf("%d is not a prime number", num);
}
getch();
}
