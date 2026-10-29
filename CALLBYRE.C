#include <stdio.h>
#include <conio.h>
void swapnum(int *n1, int *n2)
{
int tempnum;

tempnum = *n1;
*n1 = *n2;
*n2 = tempnum;
}
void main()
{
int v1=11,v2=88;
clrscr();
textcolor(RED);
cprintf("================");
printf("\nBefore swapping:\n");
cprintf("================");
printf("\nValue of v1 is: %d",v1);
printf("\nValue of v2 is: %d\n",v2);

swapnum(&v1,&v2);

textcolor(GREEN);
cprintf("================\n");
printf("After Swapping:\n");
cprintf("================");
printf("\nValue of v1 is: %d",v1);
printf("\nValue of v2 is: %d",v2);
getch();
}