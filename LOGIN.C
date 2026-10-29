#include <stdio.h>
#include <conio.h>
void main()
{
char username[20], password[10];
clrscr();
printf("Enter the Username and password: ");
scanf("%s %s", &username, &password);
if(strcmp(username,"DSA")==0 && strcmp(password,"SLCS")==0)
{
printf("\nLogin successful,Welcome to C lab");
}
else
{
printf("\nLogin failed,Try again or debug the code");
}
getch();
}
