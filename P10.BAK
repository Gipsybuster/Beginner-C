#include <stdio.h>
#include <conio.h>
#include <string.h>

struct Account
{
    char accountID[20];
    int pass;
    float balance;
};

void checkbalance(struct Account *user);
void withdraw(struct Account *user);
void debit(struct Account *user);
void saveAccounts(struct Account users[], int count);

void main()
{
    struct Account users[5];

    FILE *file;
    int choice;
    int i;
    int found = -1;
    int enteredPass;
    char enteredID[20];
    clrscr();

    /* Open account file */
    file = fopen("accounts.txt", "r");

    if (file == NULL)
    {
        printf("Could not open accounts.txt\n");
	getch();
	return;
    }

    /* Load accounts */
    for (i = 0; i < 5; i++)
    {
        fscanf(file, "%19s %d %f",
               users[i].accountID,
               &users[i].pass,
               &users[i].balance);
    }

    fclose(file);

    /* Login */
    printf("===============================\n");
    printf("        ENERGON BANK\n");
    printf("===============================\n");

    printf("Enter your Account ID: ");
    scanf("%19s", enteredID);

    /* Find account */
    for (i = 0; i < 5; i++)
    {
        if (strcmp(enteredID, users[i].accountID) == 0)
        {
            found = i;
            break;
        }
    }

    if (found == -1)
    {
        printf("\033[91mAccount not found.\033[0m\n");
	getch();
	return;
    }

    /* Verify PIN */
    printf("Enter your PIN: ");
    scanf("%d", &enteredPass);

    if (enteredPass != users[found].pass)
    {
        printf("\033[91mIncorrect Password.\033[0m\n");

    }

    printf("\033[92mLogin successful!\033[0m\n");

    /* Banking menu */
    do
    {
        printf("\n===============================\n");
        printf("        ENERGON BANK\n");
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
            checkbalance(&users[found]);
            break;

        case 2:
            withdraw(&users[found]);
            break;

        case 3:
            debit(&users[found]);
            break;

        case 4:
            printf("\033[92mThank You for using the ENERGON BANK.(●'◡'●)\033[0m\n");
            break;

        default:
            printf("Invalid Choice.\n");
            break;
        }

    } while (choice != 4);


    saveAccounts(users, 5);
    getch();
}


/* CHECK BALANCE */

void checkbalance(struct Account *user)
{
    printf("\033[92mYour account Balance is Rs.%.2f.\033[0m\n",
           user->balance);
}


/* WITHDRAW */

void withdraw(struct Account *user)
{
    float amount;
    int enteredPass;

    printf("Enter the amount for withdrawal: ");
    scanf("%f", &amount);

    do
    {
        printf("\nEnter your account's PIN to proceed: ");
        scanf("%d", &enteredPass);

        if (enteredPass == user->pass)
        {
            if (user->balance >= amount)
            {
                user->balance -= amount;

                printf("Amount withdrawn is %.2f.\n", amount);
                printf("Account Balance: %.2f.\n", user->balance);
            }
            else
            {
                printf("\033[91mInsufficient Funds. Cannot Withdraw.\033[0m\n");
                break;
            }
        }
        else
        {
            printf("\033[91mIncorrect Password. Try Again.\033[0m\n");
        }

    } while (enteredPass != user->pass);
}


/* DEBIT */

void debit(struct Account *user)
{
    char recipient[50];
    float amount;
    int success = 0;
    int enteredPass;

    printf("\nEnter the Recipient's Name: ");
    scanf("%49s", recipient);

    printf("\nEnter amount to be Debited: ");
    scanf("%f", &amount);

    do
    {
        printf("\nEnter your PIN to Proceed: ");
        scanf("%d", &enteredPass);

        if (enteredPass == user->pass)
        {
            if (user->balance >= amount)
            {
                user->balance -= amount;
                success = 1;

                printf("\nAmount Debited is %.2f.\n", amount);
            }
            else
            {
                printf("\033[91mInsufficient Funds. Cannot Debit.\033[0m\n");
                break;
            }
        }
        else
        {
            printf("\033[91mIncorrect Password. Try Again.\033[0m\n");
        }

    } while (enteredPass != user->pass);

    if (success == 1)
    {
        printf("\n\033[92m-----Transaction-----\n");
        printf("Recipient : %s\n", recipient);
        printf("Amount    : Rs.%.2f\n", amount);
        printf("Status    : Successful\n");
        printf("Balance   : Rs.%.2f\n", user->balance);
        printf("---------------------\033[0m\n");
    }
    else
    {
        printf("\n\033[91m------------Transaction-Failed-------------\n");
        printf("Recipient's Name      : %s\n", recipient);
        printf("Amount tried to Debit : Rs.%.2f\n", amount);
        printf("Status of Debit       : Unsuccessful\n");
        printf("Account Balance       : Rs.%.2f\n", user->balance);
        printf("--------------------------------------------\033[0m\n");
    }
}


/* SAVE ACCOUNTS */

void saveAccounts(struct Account users[], int count)
{
    FILE *file;
    int i;

    file = fopen("accounts.txt", "w");

    if (file == NULL)
    {
        printf("Could not save accounts.\n");
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