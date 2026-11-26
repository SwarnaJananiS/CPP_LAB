
#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
private:
    string accountHolder;
    int balance;

public:
    BankAccount(string name, int amount)
    {
        accountHolder = name;
        balance = amount;
    }

    void deposit(int amount)
    {
        cout << "Depositing Rs. " << amount << "..." << endl;
        balance += amount;
    }

    void withdraw(int amount)
    {
        cout << "Withdrawing Rs. " << amount << "..." << endl;

        if (amount > balance)
        {
            throw runtime_error("Insufficient balance for withdrawal.");
        }

        balance -= amount;
    }

    void display()
    {
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Balance: Rs. " << balance << endl;
    }
};

int main()
{
    BankAccount account("Arun", 5000);

    cout << "Initial Account Details:" << endl;
    account.display();

    account.deposit(1000);

    account.withdraw(2000);

    try
    {
        account.withdraw(10000);
    }
    catch (runtime_error &e)
    {
        cout << "Error: " << e.what() << endl;
    }

    cout << "Final Account Details:" << endl;
    account.display();

    cout << "The strong exception guarantee means: "
         << "the object's state remains unchanged if an operation fails."
         << endl;

    return 0;
}
