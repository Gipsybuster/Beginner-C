#include <stdio.h>
#include <conio.h>
void main()
{
int mark;
clrscr();
printf("Enter your Marks: ");
scanf("%d", &mark);
if (mark >= 90)
{
printf("You Have Secured S Rank");
}
else if(mark >= 80)
{
printf("You have secured A Rank");
}
else if (mark >= 70)
{
printf("You Have secured B Rank");
}
else if (mark >= 60)
{
printf("You have secured C Rank");
}
else if (mark >= 50)
{
printf("You have secured D Rank");
}
else if (mark >= 40)
{
printf("You have Secured E Rank");
}
else
{
printf("You Failed, You have to Reappear");
}
getch();
}
