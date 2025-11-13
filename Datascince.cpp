#ifndef Account_h
#define Account_h
#include <iostream>
using namespace std;

class Account {
protected:
    string ownerName;
    double balance;
public:
    Account(string n, double b) : ownerName(n), balance(b) {}
    
    double getBalance() {
        return balance;
    }

    virtual void display() {
        cout<<"Owner:" <<ownerName<<endl;
        cout<<"Balance:" <<balance<<endl;
    }

    virtual ~Account() {
        cout<<"Account closed for " <<ownerName<<endl;
    }
    
    Account operator+(Account& a) {
        double newBalance=balance+a.balance;
        return Account(ownerName, newBalance);
    }
    
    Account operator-(Account a) {
        double newBalance=balance-a.balance;
        return Account(ownerName, newBalance);
    }
    
    
    bool operator==(Account a) {
        return(balance==a.balance);
    }
    
    
    friend ostream& operator<< (ostream& out, Account a) {
        out<<"Owner: "<<a.ownerName<<"Balance: "<<a.balance<<endl;
        return out;
    }
    
    friend istream& operator>> (istream& in, Account a) {
        in >> a.ownerName >> a.balance;
               return in;
    }
    
    
};
