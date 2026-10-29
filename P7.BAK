#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Account
{
    char name[50];
    long int accountNumber;
    int pass;
    float balance;
};

void createAccount(struct Account *user);
int login(struct Account *user);
void checkbalance(struct Account user);
void withdraw(struct Account *user);
void debit(struct Account *user);

int main()
{
    FILE *fp;
    int i,j;
    struct Account user;
    int choice;
    int loggedIn;

    clrscr();

    printf("\n=================================\n");
    printf("         ENERGON BANK\n");
    printf("       CREATE ACCOUNT\n");
    printf("=================================\n");

    createAccount(&user);

    printf("\n=================================\n");
    printf("          ACCOUNT LOGIN\n");
    printf("=================================\n");

    loggedIn = login(&user);

    if (loggedIn == 0)
    {
	printf("\nLogin failed. Program exiting.\n");
	getch();
	return 0;
    }

    do
    {
	printf("\n===============================\n");
	printf("        ENERGON BANK\n");
	printf("===============================\n");
	printf("Welcome, %s!\n", user.name);
	printf("===============================\n");
	printf("1. Check Balance\n");
	printf("2. Withdraw Cash\n");
	printf("3. Debit\n");
	printf("4. Exit\n");
	printf("===============================\n");

	printf("Enter your choice: ");
	scanf("%d", &choice);

	switch (choice)
	{
	    case 1:
		checkbalance(user);
		break;

	    case 2:
		withdraw(&user);
		break;

	    case 3:
		debit(&user);
		break;

	    case 4:
		printf("\nThank You for using ENERGON BANK.\n");
		break;

	    default:
		printf("\nInvalid choice. Please try again.\n");
	}

    } while (choice != 4);
    fp = fopen("INFO.TXT", "a");
    fprintf(fp, "%s,%ld,%.2f\n", user.name, user.accountNumber, user.balance);
    fclose(fp);
    fp = fopen("INFO.TXT", "r");

   while(fscanf(fp , "%s,%ld,%.2f\n", user.name, user.accountNumber, user.balance) != EOF)
   {
	printf("%s,%ld,%.2f\n", user.name, user.accountNumber, user.balance);
    }
    getch();
    return 0;
}


/* Create Account */
void createAccount(struct Account *user)
{
    printf("\nEnter your name: ");
    scanf(" %49[^\n]", user->name);

    printf("Create your account number: ");
    scanf("%ld", &user->accountNumber);

    printf("Set your PIN: ");
    scanf("%d", &user->pass);

    printf("Enter initial deposit: ");
    scanf("%f", &user->balance);

    printf("\n=================================\n");
    printf("      ACCOUNT CREATED!\n");
    printf("=================================\n");
    printf("Account Holder : %s\n", user->name);
    printf("Account Number : %ld\n", user->accountNumber);
    printf("Balance        : Rs. %.2f\n", user->balance);
    printf("=================================\n");
}


/* Login */
int login(struct Account *user)
{
    long int accountNumber;
    int enteredPin;

    printf("\nEnter your account number: ");
    scanf("%ld", &accountNumber);

    printf("Enter your PIN: ");
    scanf("%d", &enteredPin);

    if (accountNumber == user->accountNumber &&
	enteredPin == user->pass)
    {
	printf("\nLogin Successful!\n");
	return 1;
    }

    printf("\nIncorrect Account Number or PIN.\n");

    return 0;
}


/* Check Balance */
void checkbalance(struct Account user)
{

    printf("\n===============================\n");
    printf("          ACCOUNT DETAILS\n");
    printf("===============================\n");
    printf("Account Holder : %s\n", user.name);
    printf("Account Number : %ld\n", user.accountNumber);
    printf("Balance        : Rs. %.2f\n", user.balance);
    printf("===============================\n");
    scanf("name: %s\t , acc num: %ld\t, balance: %.2f\t", &user.name,&user.accountNumber , &user.balance);
}


/* Withdraw */
void withdraw(struct Account *user)
{
    float amount;

    printf("\nEnter the amount for withdrawal: ");
    scanf("%f", &amount);

    if (amount <= 0)
    {
	printf("Invalid amount.\n");
	return;
    }

    if (user->balance >= amount)
    {
	user->balance = user->balance - amount;

	printf("\nAmount Withdrawn : Rs. %.2f\n", amount);
	printf("Account Balance  : Rs. %.2f\n",
	       user->balance);
    }
    else
    {
	printf("\nInsufficient Funds. Cannot Withdraw.\n");
    }
}


/* Debit */
void debit(struct Account *user)
{
    char recipient[50];
    float amount;

    printf("\nEnter the Recipient's Name: ");
    scanf(" %49[^\n]", recipient);

    printf("Enter amount to be Debited: ");
    scanf("%f", &amount);

    if (amount <= 0)
    {
	printf("Invalid amount.\n");
	return;
    }

    if (user->balance >= amount)
    {
	user->balance = user->balance - amount;

	printf("\n");
	printf("-----Transaction-----\n");
	printf("Recipient : %s\n", recipient);
	printf("Amount    : Rs. %.2f\n", amount);
	printf("Status    : Successful\n");
	printf("Balance   : Rs. %.2f\n", user->balance);
	printf("---------------------\n");
    }
    else
    {
	printf("\n");
	printf("------------Transaction-Failed-------------\n");
	printf("Cause of Transaction Failure : Insufficient Funds.\n");
	printf("Recipient's Name             : %s\n", recipient);
	printf("Amount tried to Debit        : Rs. %.2f\n", amount);
	printf("Status of Debit              : Unsuccessful\n");
	printf("Account Balance              : Rs. %.2f\n",
	       user->balance);
	printf("--------------------------------------------\n");
    }
}
