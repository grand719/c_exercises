#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXBANKACCOUNTS 15

struct account
{
    int id;
    char *name;
    double balance;
};

struct account bankAccounts[MAXBANKACCOUNTS];
int lastIndex = 0;

struct account *createBankAccount(struct account *bA, int maxAccount, char *name, double balance, int *lastAccountInd);
struct account *findAccount(struct account *bankAccounts, char *name, int maxAccountsNum);

void printAccount(struct account *bA);
void changeAccountBalance(struct account *bankAccounts, double value, char *accountName, int maxAccountsNum);

void printUserOptions()
{
    printf("\n0. Exit\n");
    printf("1. Create account,\n");
    printf("2. Withdraw from account\n");
    printf("3. Print account information\n");
}

void withdrawFromAccount()
{
    char *valueToWithdraw = NULL;
    char *userName = NULL;
    size_t bufsize = 32;
    size_t characters;
    valueToWithdraw = (char *)malloc(bufsize * sizeof(char));
    userName = (char *)malloc(bufsize * sizeof(char));

    printf("Provide user name: ");
    characters = getline(&userName, &bufsize, stdin);
    if (characters == -1)
    {
        printf("Error reading input.\n");
        free(valueToWithdraw);
        free(userName);
        return;
    }
    if (characters > 0 && userName[characters - 1] == '\n')
    {
        userName[characters - 1] = '\0';
    }

    printf("Provide amount to withdraw: ");
    characters = getline(&valueToWithdraw, &bufsize, stdin);
    if (characters == -1)
    {
        printf("Error reading input.\n");
        free(valueToWithdraw);
        free(userName);
        return;
    }
    if (characters > 0 && valueToWithdraw[characters - 1] == '\n')
    {
        valueToWithdraw[characters - 1] = '\0';
    }
    changeAccountBalance(bankAccounts, atof(valueToWithdraw), userName, MAXBANKACCOUNTS);
    free(valueToWithdraw);
    free(userName);
}

void addUserAccount()
{
    char *userName;
    char *accountBalance;
    size_t bufsize = 32;
    size_t characters;

    userName = (char *)malloc(bufsize * sizeof(char));
    accountBalance = (char *)malloc(bufsize * sizeof(char));
    printf("Provide user name: ");
    characters = getline(&userName, &bufsize, stdin);
    if (characters == -1)
    {
        printf("Error reading input.\n");
        free(userName);
        free(accountBalance);
        return;
    }
    if (characters > 0 && userName[characters - 1] == '\n')
    {
        userName[characters - 1] = '\0';
    }
    printf("Provide account balance: ");
    characters = getline(&accountBalance, &bufsize, stdin);
    if (characters == -1)
    {
        printf("Error reading input.\n");
        free(userName);
        free(accountBalance);
        return;
    }
    if (characters > 0 && accountBalance[characters - 1] == '\n')
    {
        accountBalance[characters - 1] = '\0';
    }

    createBankAccount(bankAccounts, MAXBANKACCOUNTS, userName, atof(accountBalance), &lastIndex);
    free(accountBalance);
}

void getUserInputForAccountDetails()
{
    char *buffer;
    size_t bufsize = 32;
    size_t characters;

    buffer = (char *)malloc(bufsize * sizeof(char));
    size_t n = 0;
    printf("Provide user name:");
    ssize_t accountSize = getline(&buffer, &bufsize, stdin);

    if (accountSize == -1)
    {
        printf("Error reading input.\n");
        free(buffer);
        return;
    }
    if (accountSize > 0 && buffer[accountSize - 1] == '\n')
    {
        buffer[accountSize - 1] = '\0';
    }

    struct account *account_ptr = findAccount(bankAccounts, buffer, MAXBANKACCOUNTS);

    if (account_ptr != NULL)
    {
        printAccount(account_ptr);
    }
    else
    {
        printf("Could not find account.\n");
    }

    free(buffer);
}

void getUserOptions()
{

    char *buffer;
    size_t bufsize = 32;
    size_t characters;

    buffer = (char *)malloc(bufsize * sizeof(char));

    ssize_t accountSize;

    int c;
    int isOptionSelected = 0;

    while (accountSize != -1)
    {
        printUserOptions();
        accountSize = getline(&buffer, &bufsize, stdin);
        if (isOptionSelected > 0)
            break;
        switch (buffer[0])
        {
        case '0':
            isOptionSelected++;
            break;
        case '1':
            addUserAccount();
            break;
        case '2':
            withdrawFromAccount();
            break;
        case '3':
            getUserInputForAccountDetails();
            break;
        default:
            break;
        }
    }
    free(buffer);
}

int main(int argc, char const *argv[])
{
    struct account *account_ptr = &bankAccounts[0];
    createBankAccount(bankAccounts, MAXBANKACCOUNTS, "Kuba", 3000, &lastIndex);
    createBankAccount(bankAccounts, MAXBANKACCOUNTS, "Lukasz", 100000, &lastIndex);

    getUserOptions();

    return 0;
}

struct account *createBankAccount(struct account *bA, int maxAccount, char *name, double balance, int *lastAccountInd)
{
    struct account *bankAccount = bA;
    char *name_ptr = (char *)malloc(sizeof(char) * 50);

    while ((bankAccount->name != NULL) && (bankAccount - bA) < maxAccount)
    {
        bankAccount++;
    }

    if (bankAccount - bA >= maxAccount)
    {
        printf("Array full. Cannot add more accounts.\n");
        return NULL;
    }

    strcpy(name_ptr, name);
    struct account newAccount;
    newAccount.id = *lastAccountInd;
    newAccount.name = name_ptr;
    newAccount.balance = balance;

    *bankAccount = newAccount;
    (*lastAccountInd)++;
    return bankAccount;
}

struct account *findAccount(struct account *bankAccounts, char *name, int maxAccountsNum)
{
    struct account *bankAccountsp = bankAccounts;
    struct account *foundAccount = NULL;
    int c;
    while ((bankAccountsp - bankAccounts) < maxAccountsNum && foundAccount == NULL)
    {
        if (bankAccountsp->name != NULL)
        {
            c = strcmp(bankAccountsp->name, name);

            if (c == 0)
            {
                return bankAccountsp;
            }
        }
        bankAccountsp++;
    }

    return NULL;
}

void changeAccountBalance(struct account *bankAccounts, double value, char *accountName, int maxAccountsNum)
{
    struct account *bankAccount = findAccount(bankAccounts, accountName, maxAccountsNum);
    double newAccountBalance;
    if (bankAccount != NULL)
    {
        newAccountBalance = bankAccount->balance + value;

        if (newAccountBalance < 0)
        {
            printf("Could not withdraw form bank account: NOT ENOUGH MONEY\n");
        }
        else
        {
            bankAccount->balance = newAccountBalance;
            printf("Success new account balance: %.2f \n", bankAccount->balance);
            printAccount(bankAccount);
        }
    }
    else
        printf("Could not find account with name: %s\n", accountName);
}

void printAccount(struct account *bA)
{
    if (bA->name != NULL)
    {
        printf("id: %d | name: %s | balance: %.2f\n", bA->id, bA->name, bA->balance);
    }
}
