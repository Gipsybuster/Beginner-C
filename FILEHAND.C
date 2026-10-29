#include <stdio.h>
#include <conio.h>
void main()
{
FILE *fp;
clrscr();
fp = fopen("MATRIX.BAT","w");
if (fp == NULL)
{
printf("Error");
getch();
return;
}

fprintf(fp, "color 0a\n");
fprintf(fp, "@ echo off\n");
fprintf(fp, ":loop\n");
fprintf(fp, "echo %%random%% %%random%% %%random%% %%random%% %%random%% %%random%% %%random%% %%random%% %%random%%\n");
fprintf(fp, "goto loop\n");

fclose(fp);

printf("Data written successfully.\n");
getch();
}