
#include <stdio.h>
#include <conio.h>
#include <string.h>

#define MAX_ACCOUNTS 5

struct Account
{
    char accountID[20];
    int pass;
    float balance;
};

void checkbalance(struct Account *user);
void withdraw(struct Account *user);
void debit(struct Account users[], int count, int loggedIn);
void saveAccounts(struct Account users[], int count);

void main()
{
    struct Account users[MAX_ACCOUNTS];

    FILE *file;

    int choice;
    int i;
    int found = -1;
    int enteredPass;
    char enteredID[20];

    clrscr();

    /* Open accounts file */

    file = fopen("accounts.txt", "r");

    if (file == NULL)
    {
        printf("Could not open accounts.txt\n");
        printf("Make sure accounts.txt is in the same folder.\n");
        getch();
        return;
    }

    /* Load accounts */

    for (i = 0; i < MAX_ACCOUNTS; i++)
    {
        if (fscanf(file, "%19s %d %f",
                   users[i].accountID,
                   &users[i].pass,
                   &users[i].balance) != 3)
        {
            printf("Error reading accounts.txt\n");
            fclose(file);
            getch();
            return;
        }
    }

    fclose(file);

    /* LOGIN */

    printf("================================\n");
    printf("          ENERGON BANK\n");
    printf("================================\n");

    printf("Enter your Account ID: ");
    scanf("%19s", enteredID);

    /* Find account */

    for (i = 0; i < MAX_ACCOUNTS; i++)
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

    /* Check PIN */

    printf("Enter your PIN: ");
    scanf("%d", &enteredPass);

    if (enteredPass != users[found].pass)
    {
        printf("\nIncorrect Password.\n");
        getch();
        return;
    }

    printf("\nLogin successful!\n");

    /* BANKING MENU */

    do
    {
        printf("\n================================\n");
        printf("          ENERGON BANK\n");
        printf("================================\n");
        printf("1. Check Balance\n");
        printf("2. Withdraw Cash\n");
        printf("3. Debit / Transfer\n");
        printf("4. Exit\n");
        printf("================================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                checkbalance(&users[found]);
                break;

            case 2:
                withdraw(&users[found]);
                break;

            case 3:
                debit(users, MAX_ACCOUNTS, found);
                break;

            case 4:
                printf("\nThank You for using ENERGON BANK.\n");
                break;

            default:
                printf("\nInvalid Choice.\n");
        }

    } while (choice != 4);

    /* Save all account balances */

    saveAccounts(users, MAX_ACCOUNTS);

    getch();
}


/* =================================
   CHECK BALANCE
   ================================= */

void checkbalance(struct Account *user)
{
    printf("\n--------------------------------\n");
    printf("Account ID : %s\n", user->accountID);
    printf("Balance    : Rs. %.2f\n", user->balance);
    printf("--------------------------------\n");
}


/* =================================
   WITHDRAW
   ================================= */

void withdraw(struct Account *user)
{
    float amount;
    int enteredPass;

    printf("\nEnter amount to withdraw: ");
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
        printf("\nIncorrect Password.\n");
        return;
    }

    user->balance = user->balance - amount;

    printf("\nWithdrawal Successful.\n");
    printf("Amount Withdrawn : Rs. %.2f\n", amount);
    printf("New Balance      : Rs. %.2f\n",
           user->balance);
}


/* =================================
   DEBIT / TRANSFER
   ================================= */

void debit(struct Account users[], int count, int loggedIn)
{
    char recipientID[20];

    float amount;

    int recipientIndex = -1;
    int enteredPass;

    int i;

    /* Ask for recipient */

    printf("\nEnter Recipient Account ID: ");
    scanf("%19s", recipientID);

    /* Search for recipient */

    for (i = 0; i < count; i++)
    {
        if (strcmp(recipientID, users[i].accountID) == 0)
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

    /* Cannot transfer to yourself */

    if (recipientIndex == loggedIn)
    {
        printf("\nYou cannot transfer money to yourself.\n");
        return;
    }

    /* Enter amount */

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

    /* PIN verification */

    printf("Enter your PIN: ");
    scanf("%d", &enteredPass);

    if (enteredPass != users[loggedIn].pass)
    {
        printf("\nIncorrect Password.\n");
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
    printf("        TRANSACTION\n");
    printf("================================\n");

    printf("From Account : %s\n",
           users[loggedIn].accountID);

    printf("To Account   : %s\n",
           users[recipientIndex].accountID);

    printf("Amount       : Rs. %.2f\n", amount);

    printf("Status       : Successful\n");

    printf("Your Balance : Rs. %.2f\n",
           users[loggedIn].balance);

    printf("================================\n");
}


/* =================================
   SAVE ACCOUNTS
   ================================= */

void saveAccounts(struct Account users[], int count)
{
    FILE *file;

    int i;

    file = fopen("accounts.txt", "w");

    if (file == NULL)
    {
        printf("\nCould not save accounts.\n");
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
