#include "Customer.h"
#include "Account.h"
#include "Bank.h"
#include <iostream>

using namespace std;

Customer* Bank::createCustomer() {

    //Customer* custom = new Customer(nextCustomerNumber);

    unique_ptr<Customer> uCu(new Customer(nextCustomerNumber));
    nextCustomerNumber++;
    string id = uCu->getId();

    this->customers[id]= move(uCu);
    Customer* pCu =  this->customers[id].get();

    return pCu;
    //return nullptr;
    //return custom;
}

Customer* Bank::lookupCustomer(std::string id) const {

    Customer* pCustomer = nullptr;
    for( auto &item: this->customers){
        if(id == item.first){
            pCustomer = item.second.get();
            break;
        }
    }
    return pCustomer;
}

std::vector<Customer*> Bank::allCustomers() const {

    vector<Customer*> listOfCustomers;
    for (auto &item:this->customers){
        listOfCustomers.push_back(item.second.get());
    }
    return listOfCustomers;
}
