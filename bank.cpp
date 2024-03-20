#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Account
{
private:
    string accountNumber;
    double balance;

public:
    Account(string accNum, double initialBalance) : accountNumber(accNum), balance(initialBalance) {}

    void deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
            cout << "Deposit of $" << amount << " successful." << endl;
        }
        else
        {
            cout << "Invalid deposit amount." << endl;
        }
    }

    void withdraw(double amount)
    {
        if (amount > 0 && balance >= amount)
        {
            balance -= amount;
            cout << "Withdrawal of $" << amount << " successful." << endl;
        }
        else
        {
            cout << "Invalid withdrawal amount or insufficient funds." << endl;
        }
    }

    void changeBalance(double newBalance)
    {
        balance = newBalance;
        cout << "Balance changed to $" << newBalance << " successfully." << endl;
    }

    void displayBalance() const
    {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Current Balance: $" << balance << endl;
    }

    string getAccountNumber() const
    {
        return accountNumber;
    }
};

class Bank
{
private:
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

    Account* findAccount(const string& accNum)
    {
        for (auto& acc : accounts)
        {
            if (accNum == acc.getAccountNumber())
            {
                return &acc;
            }
        }
        return nullptr;
    }

    void changeAccountBalance()
    {
        string accNum;
        double newBalance;
        cout << "Enter account number: ";
        cin >> accNum;
        Account* acc = findAccount(accNum);
        if (acc != nullptr)
        {
            cout << "Enter new balance: ";
            cin >> newBalance;
            acc->changeBalance(newBalance);
        }
        else
        {
            cout << "Account not found." << endl;
        }
    }
};

int main()
{
    Bank bank;
    int choice;

    do
    {
        cout << "Menu:\n";
        cout << "1. Add Account\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Change Balance\n";
        cout << "5. Display All Accounts\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
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
            bank.changeAccountBalance();
            break;
        case 5:
            bank.displayAllAccounts();
            break;
        case 6:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}
