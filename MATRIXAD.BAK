#include <stdio.h>
#include <conio.h>
void main()
{
int a[2][2], b[2][2], c[2][2], s[2][2];
int i,j;
clrscr();
printf("Enter the first Number:\n ");
for(i=0;i<2;i++)
{
for(j=0;j<2;j++)
{
scanf("%d", &a[i][j]);
}
}
printf("\nEnter the Second Number:\n ");
for(i=0;i<2;i++)
{
for(j=0;j<2;j++)
{
scanf("%d", &b[i][j]);
}
}
textcolor(11);
cprintf("\nADDING MATRICES\n");
for(i=0;i<2;i++)
{
for(j=0;j<2;j++)
{
c[i][j] = a[i][j] + b[i][j];
s[i][j] = a[i][j] - b[i][j];
}
}
for(i=0;i<2;i++)
{
for(j=0;j<2;j++)
{
printf("\nThe answer is %d", c[i][j]);
printf("\nThe Subracted Answer is %d", s[i][j]);
}
}
getch();
}