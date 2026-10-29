#include <stdio.h>
#include <conio.h>
#include <math.h>
void main()
{
int a,b, result;
char op;
clrscr();
printf("Enter the first number: ");
scanf("%d", &a);
printf("Enter an operator(+,-,*,/):  ");
scanf("%d", &op);
printf("Enter the second number: ");
scanf("%d", &b);

switch (op)
{
case '+':
result = a + b;
printf("%d + %d = %d", a,b,a + b, result);
break;

case '-':
result = a - b;
printf("%d - %d = %d", a ,b, a - b, result);
break;

case '*':
result = a * b;
printf("%d * %d = %d", a , b, a * b, result);
break;

case '/':
if(b != 0)
result = a / b;
printf("%d / %d = %d", a , b, a / b, result);

else
      printf("ERROR Division by zero is not allowed");
      break;

default:
printf("Invalid operator");

}
getch();
}