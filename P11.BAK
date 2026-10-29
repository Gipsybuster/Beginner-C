#include <stdio.h>
#include <conio.h>
#include <string.h>

#define MAX_ACCOUNTS 100

struct Account
{
    char accountID[20];
    int pass;
    float balance;
};

void login(struct Account users[], int count);
void createAccount(struct Account users[], int *count);
void checkbalance(struct Account *user);
void withdraw(struct Account *user);
void debit(struct Account users[], int count, int loggedIn);
void saveAccounts(struct Account users[], int count);

void main()
{
    struct Account users[MAX_ACCOUNTS];

    FILE *file;

    int count = 0;
    int choice;
    int i;

    clrscr();

    /* =========================
       OPEN ACCOUNTS FILE
       ========================= */

    file = fopen("accounts.txt", "r");

    if (file != NULL)
    {
	while (count < MAX_ACCOUNTS)
	{
	    if (fscanf(file, "%19s %d %f",
		       users[count].accountID,
		       &users[count].pass,
		       &users[count].balance) != 3)
	    {
		break;
	    }

	    count++;
	}

	fclose(file);
    }

    /* =========================
       MAIN MENU
       ========================= */

    do
    {
	clrscr();

	printf("================================\n");
	printf("          ENERGON BANK\n");
	printf("================================\n");
	printf("1. Login\n");
	printf("2. Create Account\n");
	printf("3. Exit\n");
	printf("================================\n");

	printf("Enter your choice: ");
	scanf("%d", &choice);

	switch (choice)
	{
	    case 1:

		if (count == 0)
		{
		    printf("\nNo accounts found.\n");
		    printf("Please create an account first.\n");
		    getch();
		}
		else
		{
		    login(users, count);
		}

		break;


	    case 2:

		createAccount(users, &count);

		break;


	    case 3:

		/* Save accounts before exiting */

		saveAccounts(users, count);

		printf("\nThank you for using ENERGON BANK.\n");
		getch();

		break;


	    default:

		printf("\nInvalid choice.\n");
		getch();
	}

    } while (choice != 3);

}


/* =========================================
   LOGIN
   ========================================= */

void login(struct Account users[], int count)
{
    char enteredID[20];

    int enteredPass;
    int found = -1;

    int i;

    printf("\n================================\n");
    printf("             LOGIN\n");
    printf("================================\n");

    printf("Enter your Account ID: ");
    scanf("%19s", enteredID);

    /* Search for Account ID */

    for (i = 0; i < count; i++)
    {
	if (strcmp(enteredID, users[i].accountID) == 0)
	{
	    found = i;
	    break;
	}
    }

    if (found == -1)
    {
	printf("\nAccount not found.\n");
	getch();
	return;
    }

    printf("Enter your PIN: ");
    scanf("%d", &enteredPass);

    if (enteredPass != users[found].pass)
    {
	printf("\nIncorrect PIN.\n");
	getch();
	return;
    }

    printf("\nLogin successful!\n");

    getch();

    /* =========================
       BANKING MENU
       ========================= */

    do
    {
	clrscr();

	printf("================================\n");
	printf("          ENERGON BANK\n");
	printf("================================\n");

	printf("Account ID : %s\n", users[found].accountID);

	printf("================================\n");
	printf("1. Check Balance\n");
	printf("2. Withdraw Cash\n");
	printf("3. Debit / Transfer\n");
	printf("4. Logout\n");
	printf("================================\n");

	printf("Enter your choice: ");
	scanf("%d", &enteredPass);

	switch (enteredPass)
	{
	    case 1:

		checkbalance(&users[found]);

		getch();

		break;


	    case 2:

		withdraw(&users[found]);

		getch();

		break;


	    case 3:

		debit(users, count, found);

		getch();

		break;


	    case 4:

		printf("\nLogging out...\n");

		getch();

		break;


	    default:

		printf("\nInvalid choice.\n");

		getch();
	}

    } while (enteredPass != 4);


    saveAccounts(users, count);
}



void createAccount(struct Account users[], int *count)
{
    char name[50];
    char dob[20];

    int age;
    int pin;

    int newNumber;
    int i;

    clrscr();

    printf("================================\n");
    printf("        CREATE ACCOUNT\n");
    printf("================================\n");

    if (*count >= MAX_ACCOUNTS)
    {
	printf("\nCannot create more accounts.\n");
	getch();
	return;
    }



    printf("Enter your Name: ");
    scanf("%49s", name);

    printf("Enter your Age: ");
    scanf("%d", &age);

    printf("Enter your DOB (DD/MM/YYYY): ");
    scanf("%19s", dob);



    printf("Create a 4-digit PIN: ");
    scanf("%d", &pin);

    /* Generate Account ID */

    newNumber = 1001 + *count;

    sprintf(users[*count].accountID,
	    "ACC%d",
	    newNumber);

    users[*count].pass = pin;

    /* Initial balance */

    printf("Enter Initial Deposit: ");
    scanf("%f", &users[*count].balance);


    (*count)++;

    /* Save immediately */

    saveAccounts(users, *count);

    printf("\n================================\n");
    printf("      ACCOUNT CREATED!\n");
    printf("================================\n");

    printf("Name       : %s\n", name);
    printf("Age        : %d\n", age);
    printf("DOB        : %s\n", dob);

    printf("\nYour Account ID is: %s\n",
	   users[*count - 1].accountID);

    printf("Please remember your Account ID.\n");

    printf("================================\n");

    getch();
}



void checkbalance(struct Account *user)
{
    printf("\n================================\n");
    printf("         ACCOUNT BALANCE\n");
    printf("================================\n");

    printf("Account ID : %s\n",
	   user->accountID);

    printf("Balance    : Rs. %.2f\n",
	   user->balance);

    printf("================================\n");
}



void withdraw(struct Account *user)
{
    float amount;

    int enteredPass;

    printf("\n================================\n");
    printf("          WITHDRAW CASH\n");
    printf("================================\n");

    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);

    if (amount <= 0)
    {
	printf("\nInvalid amount.\n");
	return;
    }

    if (amount > user->balance)
    {
	printf("\nInsufficient Funds.\n");
	return;
    }

    printf("Enter your PIN: ");
    scanf("%d", &enteredPass);

    if (enteredPass != user->pass)
    {
	printf("\nIncorrect PIN.\n");
	return;
    }

    user->balance = user->balance - amount;

    printf("\nWithdrawal Successful!\n");

    printf("Amount Withdrawn : Rs. %.2f\n",
	   amount);

    printf("New Balance      : Rs. %.2f\n",
	   user->balance);
}



void debit(struct Account users[], int count, int loggedIn)
{
    char recipientID[20];

    float amount;

    int recipientIndex = -1;
    int enteredPass;

    int i;

    printf("\n================================\n");
    printf("        DEBIT / TRANSFER\n");
    printf("================================\n");

    /* Recipient Account ID */

    printf("Enter Recipient Account ID: ");
    scanf("%19s", recipientID);

    /* Search for recipient */

    for (i = 0; i < count; i++)
    {
	if (strcmp(recipientID,
		   users[i].accountID) == 0)
	{
	    recipientIndex = i;
	    break;
	}
    }

    /* Recipient not found */

    if (recipientIndex == -1)
    {
	printf("\nRecipient Account not found.\n");
	return;
    }

    /* Prevent transfer to yourself */

    if (recipientIndex == loggedIn)
    {
	printf("\nYou cannot transfer money to yourself.\n");
	return;
    }

    /* Amount */

    printf("Enter amount to transfer: ");
    scanf("%f", &amount);

    if (amount <= 0)
    {
	printf("\nInvalid amount.\n");
	return;
    }

    /* Check balance */

    if (amount > users[loggedIn].balance)
    {
	printf("\nInsufficient Funds.\n");
	return;
    }

    /* PIN */

    printf("Enter your PIN: ");
    scanf("%d", &enteredPass);

    if (enteredPass != users[loggedIn].pass)
    {
	printf("\nIncorrect PIN.\n");
	return;
    }

    /* Remove money from sender */

    users[loggedIn].balance =
	users[loggedIn].balance - amount;

    /* Add money to recipient */

    users[recipientIndex].balance =
	users[recipientIndex].balance + amount;

    /* Transaction details */

    printf("\n================================\n");
    printf("       TRANSACTION SUCCESS\n");
    printf("================================\n");

    printf("From Account : %s\n",
	   users[loggedIn].accountID);

    printf("To Account   : %s\n",
	   users[recipientIndex].accountID);

    printf("Amount       : Rs. %.2f\n",
	   amount);

    printf("Status       : Successful\n");

    printf("Your Balance : Rs. %.2f\n",
	   users[loggedIn].balance);

    printf("================================\n");
}



void saveAccounts(struct Account users[], int count)
{
    FILE *file;

    int i;

    file = fopen("accounts.txt", "w");

    if (file == NULL)
    {
	printf("\nCould not save accounts.txt\n");
	return;
    }

    for (i = 0; i < count; i++)
    {
	fprintf(file, "%s %d %.2f\n",
		users[i].accountID,
		users[i].pass,
		users[i].balance);
    }

    fclose(file);
}
