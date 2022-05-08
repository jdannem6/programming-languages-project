// Account.c
// Written by Justin Dannemiller
// CS 33101: Structure of Programming Languages
// 6 May 2022

// This program defines and uses a simple struct Customer which emulates
// a Customer record at a bank. This struct stores the customer's name and
// all accounts that they managed. The operations performed within this
// file, in comparison to those within Account.py, illustrate some of the
// differences between Python and C

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Customer {
    char name[50]; // A name may only be 50 letters long
    double* accounts; // Pointer to all account balances managed by the customer
    int number_accounts; // Number of accounts
};

// Functions used to modify Customer account (no encapsulation, not good)
// Add an account with the given balance to Josie's customer record
struct Customer addAccount(struct Customer customer, double balance) {
    // Create pointer for new accounts array with room for additional account
    double* tempAccounts = (double*)malloc((customer.number_accounts + 1)*sizeof(double));
    // copy all account balances from previous array
    for (int i = 0; i < customer.number_accounts; ++i) {
        *(tempAccounts + i) = *(customer.accounts + i);
    }
    // Insert new account balance in new account
    *(tempAccounts + customer.number_accounts) = balance;

    // deallocate previous array
    free(customer.accounts);
    ++customer.number_accounts;
    // Set customer's account records to new array
    customer.accounts = tempAccounts;
    tempAccounts = NULL;
    return customer;
}

// Return the balance of the given account
double getBalance(struct Customer customer, int accountIndex) {
    // Give error if the given account_index is out of range
    if (accountIndex > customer.number_accounts - 1) {
        printf("Account index out of range");
        exit(-1); // exit on error
    }
    // Otherwise index the given account and return its balance
    else {
        double balance = *(customer.accounts + accountIndex);
        return balance;
    }
}

// Updates the balance in the customer's given account
// Adds the transaction amount to their balance
struct Customer updateBalance(struct Customer customer, int accountIndex, double transactionAmount) {
    // Give error if the given account_index is out of range
    if (accountIndex > customer.number_accounts - 1) {
        printf("Account index out of range");
        exit(-1); // exit on error
    }
    // Otherwise update the indexed account's balance
    else {
        *(customer.accounts + accountIndex) += transactionAmount;
        return customer;
    }
}
int main() {
    // Create a new customer record for Josie
    struct Customer Josie = { .name = "Josie Wells", .accounts = NULL, .number_accounts = 0 };

    // Add a few accounts to the customer's record
    for (int i = 0; i < 4; ++i) {
        Josie = addAccount(Josie, (i + 1) * 13500.00);
    }

    // Print the balances of all Josie's accounts
    for (int i = 0; i < 4; ++i) {
        printf("Hi %s", Josie.name);
        printf(", the current balance on that account is $%.2f", getBalance(Josie, i));
        printf("\n");
    }
    
    // Customer bought a new car with account 2. Update account 2's balance 
    // to reflect this transaction
    Josie = updateBalance(Josie, 1, -22000.00);

    // Print the balance after this transaction
    printf("\nAfter purchasing the car, the remaining balance is $%6.2f", getBalance(Josie, 1));
    printf("\n");
}

