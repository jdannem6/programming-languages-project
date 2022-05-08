# Account.py
# Written by Justin Dannemiller
# CS 33101: Structure of Programming Languages
# 6 May 2022

# This program defines and uses a simple class Customer which emulates
# a customer of a bank. Specifically, each customer has a name and a
# set of checking accounts. The operations performed within this
# file, in comparison to those within Account.c, illustrate some of the
# differences between C and Python


# Define the Customer Class
class Customer:
    name = "Placeholder"
    # Stores all the accounts managed by the customer
    # Accounts are represented only by their balance
    accounts = []
    
    # Initialization function
    def __init__(self, name):
        # Initialize the customer's name
        self.name = name
    # Adds new account with given balance to customer's record
    def add_account(self, balance):
        self.accounts = self.accounts + [balance]

    # Get the balance of a given account
    def get_balance(self, account_index):
        # Determine number of accounts
        number_accounts = len(self.accounts)
        # Give error if given account_index is out of range
        if (account_index > number_accounts - 1):
            print("Account index out of range!")
            return
        # Otherwise, print the balance of that account
        else:
            return self.accounts[account_index]
    
    # Update the balance on a given account
    # Balance is updated by adding transaction_amount which is negative
    # if balance is being deducted, positive otherwise
    def update_balance(self, account_index, transaction_amount):
        # Give error if given account_index is out of range
        # Determine number of accounts
        number_accounts = len(self.accounts)
        if (account_index > number_accounts - 1):
            print("Account index out of range!")
            return
        # Otherwise, update the requested account's balance
        else:
            self.accounts[account_index] += transaction_amount
    

if __name__ == "__main__":
    # Create new customer
    Josie = Customer("Josie Wells")
    # Add a few accounts to the customer's record
    for i in range(0, 4):
        Josie.add_account((i+1)*13500.00)
    
    # Print the balances of all Josie's accounts
    for i in range(0,4):
        #print(Josie.get_balance(i))
        print("Hi " + Josie.name + 
        " The current balance of that account is $%.2f" % Josie.get_balance(i))

    # Customer bought a new car with account 2. Remove the price of the car 
    # from that account's balance
    Josie.update_balance(1, -22000)

    # Print balance after this transaction
    print("\nAfter purchasing the car, the remaining balance on that account is \
    $" + str(Josie.get_balance(1)))


