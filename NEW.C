#include <stdio.h>
#include <conio.h>
void main ()
{
char name[20], department[10];
int age, year, semester;
long int roll_no;
clrscr();
printf("Enter your Name and Department: ");
scanf("%s %s", &name, &department);
printf("Enter your age, year, and Semester: ");
scanf("%d %d %d", &age, &year, &semester);
printf("Enter your roll no: ");
scanf("%ld", &roll_no);
printf("\n Your Age is %d", age);
printf("\n Your Roll no is %ld", roll_no);
printf("\n Your Year is %d", year);
printf("\n Your departmenet is %s", department);
printf("\n Your Semester is %d", semester);
getch();
}