#ifndef _BANKACCOUNT_H
#define _BANKACCOUNT_H

#include <string>

class BankAccount
{
public:

    BankAccount(const std::string& name, int id);
    void deposit(double amount);
    void withdraw(double amount);
    double getBalance() const;

private:

    std::string m_name;
    int m_id;
    double m_balance;

};

#endif