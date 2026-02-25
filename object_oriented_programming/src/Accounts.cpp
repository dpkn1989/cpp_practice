#include "Accounts.h"

int16_t Account::accountNumberGenerator = 1000;

Account::Account(std::string name, double balance)
    : m_name{name}, m_balance{balance}, m_accountNumber{++accountNumberGenerator}
{
    std::cout << "Account constructor called." << std::endl;
}

void Account::deposit(double amount)
{
    m_balance += amount;
}

void Account::withdraw(double amount)
{
    if (amount > m_balance)
    {
        std::cout << "Insufficient balance! Cannot withdraw more than " << m_balance << " rupees." << std::endl;
    }
    else
    {
        m_balance -= amount;
        std::cout << "Withdrawal of " << amount << " rupees successful." << std::endl;
    }
}

void Account::display() const
{
    std::cout << "Account Number: " << m_accountNumber << std::endl;
    std::cout << "Name: " << m_name << std::endl;
    std::cout << "Balance: " << m_balance << std::endl;
}

SavingsAccount::SavingsAccount(std::string name, double balance, double interestRate)
    : Account{name, balance}, m_interestRate{interestRate}
{
    std::cout << "SavingsAccount constructor called." << std::endl;
}

void SavingsAccount::applyInterest()
{
    double interest = (m_interestRate / 100) * m_balance;
    deposit(interest);
    std::cout << "Interest of " << interest << " rupees applied." << std::endl;
}

CheckingAccount::CheckingAccount(std::string name, double balance, double overdraftLimit)
    : Account{name, balance}, m_overdraftLimit{overdraftLimit}
{
    std::cout << "CheckingAccount constructor called." << std::endl;
}

void CheckingAccount::withdraw(double amount)
{
    if (amount > m_balance + m_overdraftLimit)
    {
        std::cout << "Withdrawal exceeds overdraft limit! Cannot withdraw more than " << m_balance + m_overdraftLimit << " rupees." << std::endl;
    }
    else
    {
        m_balance -= amount;
        std::cout << "Withdrawal of " << amount << " rupees successful." << std::endl;
    }
}

double CheckingAccount::getMinimumBalance() const
{
    return 100.0; // Minimum balance for checking account is 100 rupees
}

void Transaction(Account* account)
{
    std::cout << "Performing a transaction..." << std::endl;
    account->withdraw(200.0);

    SavingsAccount* savingsAcc = dynamic_cast<SavingsAccount*>(account);
    if(savingsAcc != nullptr)
    {
        savingsAcc->applyInterest();
    }

    /* if(dynamic_cast<CheckingAccount*>(account))
    {
        std::cout << "Minimum balance for checking account: " << account->getMinimumBalance() << " rupees." << std::endl;
    } */
    CheckingAccount* checkingAcc = dynamic_cast<CheckingAccount*>(account);
    if(checkingAcc != nullptr)
    {
        std::cout << "Minimum balance for checking account: " << checkingAcc->getMinimumBalance() << " rupees." << std::endl;
    }
    account->display();
}