#include "CurrentAccount.h"

CurrentAccount::CurrentAccount(Customer *customer):Account{customer, Bank::AccountType::Current}{

}

Poco::JSON::Object& CurrentAccount::setAccountType(
        Poco::JSON::Object &obj) const {

    obj.set("accountType", "Current");
    return obj;
}
