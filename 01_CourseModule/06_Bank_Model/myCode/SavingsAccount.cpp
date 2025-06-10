#include "SavingsAccount.h"

SavingsAccount::SavingsAccount(Customer *customer):Account{customer, Bank::AccountType::Savings}{
}

Poco::JSON::Object& SavingsAccount::setAccountType(Poco::JSON::Object &obj) const {

    obj.set("accountType", "Savings");
    return obj;
}
