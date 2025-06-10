#include "CDAccount.h"

CDAccount::CDAccount(Customer *customer):Account{customer, Bank::AccountType::CD} {
}

Poco::JSON::Object& CDAccount::setAccountType(Poco::JSON::Object &obj) const {

    obj.set("accountType", "CD");
    return obj;
}

