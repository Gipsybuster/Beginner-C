#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
void main()
{
srand(time(NULL));
int flip = srand()%2;
if (flip == 0)
{
printf("Heads");
}
else
{
printf("Tails");
}
getch();
}