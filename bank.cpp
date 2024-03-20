#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Account 
{
    string accountNumber;
    double balance;

public:
    Account(string accNum, double initialBalance) : accountNumber(accNum), balance(initialBalance) {}

    void deposit(double amount)
	 {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit of $" << amount << " successful." << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    void withdraw(double amount) 
	{
        if (amount > 0 && balance >= amount) 
		{
            balance -= amount;
            cout << "Withdrawal of $" << amount << " successful." << endl;
        } else
		 {
            cout << "Invalid withdrawal amount or insufficient funds." << endl;
        }
    }

    void displayBalance() const 
	{
        cout << "Account Number: " << accountNumber << endl;
        cout << "Current Balance: $" << balance << endl;
    }
};

class Bank
{
    vector<Account> accounts;

public:
    void addAccount(const Account& acc)
	 {
        accounts.push_back(acc);
        cout << "Account added successfully." << endl;
    }

    void displayAllAccounts() const 
	{
        cout << "----- All Accounts -----" << endl;
        for (const auto& acc : accounts) 
		{
            acc.displayBalance();
            cout << endl;
        }
    }
};

int main() 
{
    Bank bank;
    int choice;

    do {
        cout << "Menu:\n";
        cout << "1. Add Account\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Display All Accounts\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
		{
            case 1: {
                string accNum;
                double initialBalance;
                cout << "Enter account number: ";
                cin >> accNum;
                cout << "Enter initial balance: ";
                cin >> initialBalance;
                bank.addAccount(Account(accNum, initialBalance));
                break;
            }
            case 2:
			 {
                string accNum;
                double amount;
                cout << "Enter account number: ";
                cin >> accNum;
                cout << "Enter deposit amount: ";
                cin >> amount;
                break;
            }
            case 3:
			{
                string accNum;
                double amount;
                cout << "Enter account number: ";
                cin >> accNum;
                cout << "Enter withdrawal amount: ";
                cin >> amount;
                break;
            }
            case 4:
                bank.displayAllAccounts();
                break;
            case 5:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
