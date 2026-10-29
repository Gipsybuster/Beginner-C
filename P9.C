#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct Account
{
    char accountID[20];
    char name[50];
    int pass;
    float balance;
};

int loadAccounts(struct Account user[]);

void saveAccounts(struct Account user[], int count);

void createAccount(struct Account user[], int *count);

int login(struct Account user[], int count);

void checkbalance(struct Account *user);

void withdraw(struct Account *user);

void debit(struct Account *user);

void main()
{
    struct Account user[5];

    int count;
    int choice;
    int loggedIn;
    int menuChoice;

    clrscr();

    count = loadAccounts(user);
    do
    {
	printf("\n=================================\n");
	printf("          ENERGON BANK\n");
	printf("=================================\n");

	printf("1. Create Account\n");
	printf("2. Login\n");
	printf("3. Exit\n");

	printf("=================================\n");

	printf("Enter your choice: ");
	scanf("%d", &choice);


	switch(choice)
	{
	    case 1:

		createAccount(user, &count);

		break;

	    case 2:

		printf("\n=================================\n");
		printf("          ACCOUNT LOGIN\n");
		printf("=================================\n");


		loggedIn = login(user, count);


		if(loggedIn != -1)
		{


		    do
		    {
			printf("\n===============================\n");
			printf("        ENERGON BANK\n");
			printf("===============================\n");

			printf("Welcome, %s!\n", user[loggedIn].name);

			printf("===============================\n");

			printf("1. Check Balance\n");
			printf("2. Withdraw Cash\n");
			printf("3. Debit\n");
			printf("4. Logout\n");

			printf("===============================\n");

			printf("Enter your choice: ");
			scanf("%d", &menuChoice);


			switch(menuChoice)
		    {

			    case 1:

				checkbalance(
				    &user[loggedIn]
				);

				break;

			    case 2:

				withdraw(&user[loggedIn]);
				saveAccounts(user,count);

				break;

			    case 3:

				debit(&user[loggedIn]);
				saveAccounts(user, count);
				break;


				case 4:

				printf("\nLogged out successfully.\n");
				break;


			    default:

				printf( "\nInvalid choice.");
			}

		    } while(menuChoice != 4);
		}

		break;

		case 3:

		printf(
		    "\nThank you for using ENERGON BANK.\n"
		);

		break;


	    default:

		printf(
		    "\nInvalid choice. Please try again.\n"
		);
	}

    } while(choice != 3);


    getch();

}


int loadAccounts(struct Account user[])
{
    FILE *fp;

    int count = 0;



    fp = fopen("BankInfor.TXT", "r");


    if(fp == NULL)
    {
	printf("\nINFO.TXT file not found!\n");
	getch();
	return;
    }


    /*
       Read the accounts from the file.
    */

    while(count < 5 && fscanf(fp, " %19[^,],%49[^,],%d,%f", user[count].accountID, user[count].name, &user[count].pass, &user[count].balance) == 4)
    {
	count++;
    }


    fclose(fp);


    return count;
}



void saveAccounts(struct Account user[],
		  int count)
{
    FILE *fp;

    int i;

    fp = fopen("BankInfor.TXT", "w");


    if(fp == NULL)
    {
	printf("\nError opening INFO.TXT!\n");

	return;
    }

    for(i = 0; i < count; i++)
    {
	fprintf(fp,"%s,%s,%d,%.2f\n",user[i].accountID,user[i].name,user[i].pass,user[i].balance);
    }


    fclose(fp);
}


void createAccount(struct Account user[], int *count)
{
    printf("\n=================================\n");
    printf("         CREATE ACCOUNT\n");
    printf("=================================\n");


    printf("Enter Account ID: ");

    scanf("%19s", user[*count].accountID);


    printf("Enter your name: ");

    scanf(" %49[^\n]", user[*count].name);


    printf("Set your PIN: ");

    scanf("%d", &user[*count].pass);


    printf("Enter initial deposit: ");

    scanf("%f", &user[*count].balance);



    (*count)++;




    saveAccounts(user, *count);


    printf("\n=================================\n");
    printf("       ACCOUNT CREATED!\n");
    printf("=================================\n");

    printf("Account ID : %s\n",
	   user[*count - 1].accountID);

    printf("Name       : %s\n",
	   user[*count - 1].name);

    printf("Balance    : Rs. %.2f\n",
	   user[*count - 1].balance);

    printf("=================================\n");
}


int login(struct Account user[], int count)
{
    char enteredID[20];

    int enteredPin;

    int i;


    printf("\nEnter your Account ID: ");

    scanf("%19s", enteredID);


    printf("Enter your PIN: ");

    scanf("%d",
	  &enteredPin);




    for(i = 0; i < count; i++)
    {
        if(strcmp(user[i].accountID,
                  enteredID) == 0)
        {



	    if(user[i].pass == enteredPin)
	    {
		printf("\n=================================\n");
		printf("       LOGIN SUCCESSFUL!\n");
		printf("=================================\n");

		printf("Welcome, %s!\n",
		       user[i].name);




		return i;
	    }




	    printf("\nIncorrect PIN.\n");

	    return -1;
	}
    }




    printf("\nAccount ID not found.\n");

    return -1;
}




void checkbalance(struct Account *user)
{
    printf("\n===============================\n");
    printf("         ACCOUNT DETAILS\n");
    printf("===============================\n");

    printf("Account ID : %s\n",
	   user->accountID);

    printf("Account Holder : %s\n",
	   user->name);

    printf("Balance    : Rs. %.2f\n",
	   user->balance);

    printf("===============================\n");
}



void withdraw(struct Account *user)
{
    float amount;


    printf("\nEnter the amount for withdrawal: ");

    scanf("%f",
	  &amount);


    if(amount <= 0)
    {
	printf("\nInvalid amount.\n");

	return;
    }


    if(user->balance >= amount)
    {
	user->balance =
	    user->balance - amount;


	printf("\nAmount Withdrawn : Rs. %.2f\n",
	       amount);

	printf("Account Balance  : Rs. %.2f\n",
	       user->balance);
    }
    else
    {
	printf(
	    "\nInsufficient Funds. Cannot Withdraw.\n"
	);
    }
}


void debit(struct Account *user)
{
    char recipient[50];

    float amount;


    printf("\nEnter the Recipient's Name: ");

    scanf(" %49[^\n]",
	  recipient);


    printf("Enter amount to be Debited: ");

    scanf("%f",
	  &amount);


    if(amount <= 0)
    {
	printf("\nInvalid amount.\n");

	return;
    }


    if(user->balance >= amount)
    {
	user->balance =
	    user->balance - amount;


	printf("\n");
	printf("-----Transaction-----\n");

	printf("Recipient : %s\n",
	       recipient);

	printf("Amount    : Rs. %.2f\n",
	       amount);

	printf("Status    : Successful\n");

	printf("Balance   : Rs. %.2f\n",
	       user->balance);

	printf("---------------------\n");
    }
    else
    {
	printf("\n");
	printf(
	    "--------Transaction Failed--------\n"
	);

	printf(
	    "Cause : Insufficient Funds\n"
	);

	printf(
	    "Recipient : %s\n",
	    recipient
	);

	printf(
	    "Amount    : Rs. %.2f\n",
	    amount
	);

	printf(
	    "Status    : Unsuccessful\n"
	);

	printf(
	    "Balance   : Rs. %.2f\n",
	    user->balance
	);

	printf(
	    "----------------------------------\n"
	);
    }
}