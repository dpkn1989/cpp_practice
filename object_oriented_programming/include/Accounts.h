#ifndef ACCOUNTS_H
#define ACCOUNTS_H

#include <iostream>

class Account{
    private:
        std::string m_name;
        int16_t m_accountNumber;
        static int16_t accountNumberGenerator;
    protected:
        double m_balance;
    public:
        Account(std::string name, double balance);
        void deposit(double amount);
        virtual void withdraw(double amount);
        void display() const;
};

class SavingsAccount : public Account {
    private:
        double m_interestRate;
    public:
        SavingsAccount(std::string name, double balance, double interestRate);
        void applyInterest();
};

class CheckingAccount : public Account {
    private:
        double m_overdraftLimit;
    public:
        CheckingAccount(std::string name, double balance, double overdraftLimit);
        void withdraw(double amount) override;
        double getMinimumBalance() const;
};

void Transaction(Account* account);

#endif // ACCOUNTS_H