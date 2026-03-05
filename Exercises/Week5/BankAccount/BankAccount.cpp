#include "BankAccount.h"
#include <iostream>

BankAccount::BankAccount(const std::string &name, int id)
    : m_name(name)
    , m_id(id)
    , m_balance(0.0)
{
}

void BankAccount::deposit(double amount)
{
    if (amount <= 0.0)
    {
        std::cout << "invalid amount\n";
        return;
    }

    m_balance += amount;
}

void BankAccount::withdraw(double amount)
{
    if (amount <= 0.0)
    {
        std::cout << "invalid amount\n";
        return;
    }

    if (amount > m_balance)
    {
        std::cout << "insufficient funds\n";
        return;
    }

    m_balance -= amount;
}

double BankAccount::getBalance() const
{
    return m_balance;
}



