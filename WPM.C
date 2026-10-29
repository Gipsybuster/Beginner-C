#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <string.h>
void main()
{
char text[] = "small dihh big dreams";
char input[100];
time_t start, end;
long seconds;
int words, wpm;
clrscr();

printf("=========================\n");
printf("====Typing Speed Test====\n");
printf("=========================\n\n");


printf("Type the following sentence:\n\n");
printf("%s\n\n", text);


printf("Press ENTER when Ready:\n\n");
getch();

printf("Start typing:\n\n");

time(&start);

gets(input);

time(&end);

seconds = (long)(end - start);


words = strlen(input) / 5;


if (seconds > 0)
{
wpm = (int)((words * 60)/ seconds);
}
else {
wpm = 0;
}
printf("\n======================\n");
printf("Time Taken is: %.1f\n",seconds);
printf("Your Speed is: %d wpm\n", wpm);
printf("\n======================\n");
printf("Press any key to exit.(>_<)");
getch();
}


