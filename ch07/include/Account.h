#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>

class Account {
    friend std::ostream &print(std::ostream&, Account&);
public:
    // constructors
    Account() = default;
    explicit Account(const std::string &s, double d = 0.0): 
        owner(s), amount(d), daily_tbl() { }
    void calculate() { amount += amount * interestRate; }
    static double rate() { return interestRate; }
    static void rate(double);
    std::ostream &print(std::ostream&);
private:
    std::string owner;
    double amount;
    static double interestRate;
    static double initRate();
    static constexpr int period = 30;
    double daily_tbl[period];
};

inline void Account::rate(double newRate) { interestRate = newRate; }

inline std::ostream &print(std::ostream &os, Account &acc)
{
    os << acc.owner << " " << acc.amount << " " << acc.daily_tbl[0];
    return os;
}

inline std::ostream &Account::print(std::ostream &os = std::cout)
{
    os << owner << " " << amount << " " << daily_tbl[0];
    return os;
}

#endif
