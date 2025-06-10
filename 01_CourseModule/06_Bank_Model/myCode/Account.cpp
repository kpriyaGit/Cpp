#include "Customer.h"
#include "Account.h"
using namespace std;

Account::Account(Customer *customer, Bank::AccountType type) {

    int seqcount=1; string firstdigit, seconddigit, thirddigit, remainingdigits;

    if(type == Bank::AccountType::CD )
        firstdigit = "3";
    else if(type == Bank::AccountType::Current )
        firstdigit = "1";
    else
        firstdigit = "2";

    //if(customer->allAccounts().empty()==false){ //already accounts existing for the customer
        for(auto &account:customer->allAccounts()){

            if(account->getId().substr(0, 1) == firstdigit){
                //int tempSeq = stoi(account->getId().substr(1, 2));
                if(seqcount==stoi(account->getId().substr(1, 2))){  //increment the new seqcount
                    seqcount++;
                }
            }
        }
    //}

//    if(seqcount<10){
//        seconddigit = "0";
//        thirddigit = to_string(seqcount);
//    }
//    else{
        seconddigit = to_string(seqcount / 10);
        thirddigit = to_string(seqcount % 10);
    //}

    //get remaining digits from customer id
    remainingdigits = customer->getId().substr(3);

    // concatenate all the digits
    this->id = firstdigit + seconddigit + thirddigit + remainingdigits;

}

Bank::AccountType Account::accountType(std::string accountId) {

    if(accountId[0] ==1)
        return Bank::AccountType::Current;
    else if(accountId[0] ==2)
        return Bank::AccountType::Savings;
    else if(accountId[0] ==3)
        return Bank::AccountType::CD;
    else
        throw invalid_argument(" Invalid Id");
}

Account::~Account() {
}

std::string Account::getId() const {

    return this->id;
}

float Account::getBalance() const {
    return this->balance;
}

void Account::transact(float amount) {
    this->balance+=amount;
}

Poco::JSON::Object::Ptr Account::toJson() const {

    Poco::JSON::Object::Ptr pAccount = new Poco::JSON::Object;
    Poco::JSON::Object accType;
    string type = this->setAccountType(accType).get("accountType").toString();
    //Account->set("accountType", this->setAccountType(accType));
    pAccount->set("accountType", type);
    pAccount->set("balance", this->getBalance());
    return pAccount;
}
