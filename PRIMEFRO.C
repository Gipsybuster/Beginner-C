#include <stdio.h>
#include <conio.h>
void main()
{
int num, i, count;
clrscr();
for(num = 1; num <= 100; num++)
{
count = 0;

for(i = 1; num <= 100; i++)
{
if(num % i == 0)
{
count++;
}
if (count == 2)
{
printf("%d\n", num);
}
}
}
getch();
}