#include <stdio.h>
#include <conio.h>
void main()
{
char choice;
char resume;
do{
clrscr();
textcolor(4);
cprintf("POV: A Psycho Killer is coming to kill you! What are you going to do? \t\t\t\t\t\t\t\t\t\t\n\na.run b.fight c.Call police d.do nothing\n");
scanf("%c",&choice);
switch (choice)
{
case 'a':
textcolor(2);
cprintf("Thinks about runnning, gets his legs Chopped off(^_-)");
break;

case 'b':
textcolor(6);
cprintf("Gets Crucified next to Jesus(-_-)");
break;

case 'c':
textcolor(8);
cprintf("Don't worry You'll get Drilled while you begin to call(*_*)");
break;

case 'd':
textcolor(9);
cprintf("Gets killed by a cockroach(^_^)");
break;

default :
textcolor(13);
cprintf("Someone's going to take a bullet in their Mouth and it's not the killer");
}
getch();
printf("Do you want to continue?");
scanf("%c", &resume);
