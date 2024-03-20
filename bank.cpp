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

    double getBalance() const
    {
        return balance;
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

    void transferFunds()
    {
        string fromAccount, toAccount;
        double amount;
        cout << "Enter source account number: ";
        cin >> fromAccount;
        cout << "Enter destination account number: ";
        cin >> toAccount;
        cout << "Enter amount to transfer: ";
        cin >> amount;

        Account* sourceAcc = findAccount(fromAccount);
        Account* destAcc = findAccount(toAccount);

        if (sourceAcc != nullptr && destAcc != nullptr) {
            if (sourceAcc->getBalance() >= amount) 
			{
                sourceAcc->withdraw(amount);
                destAcc->deposit(amount);
                cout << "Transfer successful." << endl;
            }
            else 
			{
                cout << "Insufficient funds in the source account." << endl;
            }
        }
        else 
		{
            cout << "One or both accounts not found." << endl;
        }
    }

    void closeAccount()
    {
        string accNum;
        cout << "Enter account number to close: ";
        cin >> accNum;

        for (auto it = accounts.begin(); it != accounts.end(); ++it) 
		{
            if (it->getAccountNumber() == accNum) {
                accounts.erase(it);
                cout << "Account closed successfully." << endl;
                return;
            }
        }
        cout << "Account not found." << endl;
    }

    void displayAccountInformation()
    {
        string accNum;
        cout << "Enter account number: ";
        cin >> accNum;

        Account* acc = findAccount(accNum);
        if (acc != nullptr) {
            acc->displayBalance();
            cout << endl;
        }
        else {
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
        cout << "5. Transfer Funds\n";
        cout << "6. Close Account\n";
        cout << "7. Account Information\n";
        cout << "8. Display All Accounts\n";
        cout << "9. Exit\n";
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
            Account* acc = bank.findAccount(accNum);
            if (acc != nullptr)
                acc->deposit(amount);
            else
                cout << "Account not found." << endl;
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
            Account* acc = bank.findAccount(accNum);
            if (acc != nullptr)
                acc->withdraw(amount);
            else
                cout << "Account not found." << endl;
            break;
        }
        case 4:
            bank.changeAccountBalance();
            break;
        case 5:
            bank.transferFunds();
            break;
        case 6:
            bank.closeAccount();
            break;
        case 7:
            bank.displayAccountInformation();
            break;
        case 8:
            bank.displayAllAccounts();
            break;
        case 9:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 9);

    return 0;
}
