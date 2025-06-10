#include "Customer.h"
#include "CDAccount.h"
#include "CurrentAccount.h"
#include "SavingsAccount.h"
#include <iostream>


using namespace std;

Customer::Customer(unsigned int number): number{number} {

}

unsigned int Customer::getNumber() const {
    return this->number;
}

std::string Customer::getId() const {

    int number = this->number; int digitCount = 1;
    while(number>10){
        digitCount ++;
        number = number / 10;
    }

    string customerID;
    int preceedingZerosNum = 10-digitCount;
    for(int i=0;i<preceedingZerosNum;i++){
        customerID = customerID + "0";
    }
    customerID = customerID + to_string(this->number);
    return customerID;


}

Customer* Customer::setPersonalData(std::string lastName, std::string firstName,
        Poco::Data::Date dateOfBirth){
    this->lastName = lastName;
    this->firstName = firstName;
    this->dateOfBirth = dateOfBirth;
    return this;

}

const Poco::Data::Date& Customer::getDateOfBirth() const {

    return this->dateOfBirth;
}

const std::string& Customer::getFirstName() const {

    return this->firstName;
}

const std::string& Customer::getLastName() const {

    return this->lastName;
}


Account* Customer::createAccount(Bank::AccountType type) {

    Account* pAcc = nullptr;  string tempId;

    if(type == Bank::AccountType::CD){
        //return( new CDAccount(this));
        unique_ptr<Account> acc(new CDAccount(this));
        tempId = acc->getId();
        this->accounts.emplace(tempId, move(acc));  // u cannot copy/pass unique_pointers. Need to use move()
    }
    else if(type == Bank::AccountType::Current){
        //return ( new CurrentAccount(this));
        unique_ptr<Account> acc(new CurrentAccount(this));
        tempId = acc->getId();
        this->accounts.emplace(tempId, move(acc));
    }
    else{
        //return ( new SavingsAccount(this));
        unique_ptr<Account> acc(new SavingsAccount(this));
        tempId = acc->getId();
        this->accounts.emplace(tempId, move(acc));
    }

    pAcc = this->accounts.at(tempId).get();

    return pAcc;

}

std::vector<Account*> Customer::allAccounts() const {

    vector<Account*> listOfAccounts;
    for (auto &item:this->accounts){
        listOfAccounts.push_back(item.second.get());
    }
    return listOfAccounts;
}

Account* Customer::lookupAccount(std::string id) const {

    Account* pAcc = nullptr;
    for(auto &item:this->accounts){
        if(item.first == id){
            pAcc=item.second.get();
        }
    }
    return pAcc;
}

void Customer::deleteAccount(std::string id) {

    bool idMatch=false, zeroBalance=false;

    for(auto &item:this->accounts){

        if(item.first == id) {
            idMatch = true;

            if(item.second->getBalance()==0){
                zeroBalance = true;
                item.second.reset();  // unique pointer is deleted
                this->accounts.erase(id);  //key is removed from map
                cout<<"    Account with id "<< id << " deleted"<<endl;
                break;
            }
            break;
        }
    }
    if(idMatch==false)
        throw invalid_argument("Invalid Account Id");
    if(zeroBalance == false)
        throw logic_error("Account Balance is not null");
}

std::ostream& operator <<(std::ostream &out, const Customer &customer) {
    //    * Example:
    //    * 0000000001: Angel, Alice (1.1.1991)
    out<<customer.getId()<<": "<<customer.getFirstName()<<", "<<customer.getLastName()
                            <<" ("<<customer.getDateOfBirth().day()<<"."<<customer.getDateOfBirth().month()
                            <<"."<<customer.getDateOfBirth().year()<<")";  // dont add<<endl here

    return out;
}
