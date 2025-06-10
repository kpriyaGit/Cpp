
#include <iostream>
#include <sstream>
#include <set>
#include <Poco/JSON/Stringifier.h>

using namespace std;

#include "Bank.h"
#include "Customer.h"
#include "Account.h"
#include "CurrentAccount.h"
#include "SavingsAccount.h"
#include "CDAccount.h"

/**
 * Outputs the failedMessage on the console if condition is false.
 *
 * @param condition the condition
 * @param failedMessage the message
 */
void assertTrue(bool condition, string failedMessage) {
    if (!condition) {
        cout << failedMessage << endl;
    }
}

/**
 * Initializes a bank with customers with different account
 * types. Can be used as data for various tests.
 */
void setupBank(Bank& bank) {
    // The following code has been commented out to keep
    // the start project buildable. Remove the comments
    // when you have implemented the required methods.

    /********* reactivate later *********/
    Customer* c = bank.createCustomer()->setPersonalData
            ("Angel", "Alice", Poco::Data::Date(1991, 1, 1));
    c->createAccount(Bank::AccountType::Current)->transact(100);
    c->createAccount(Bank::AccountType::Savings)->transact(500);
    c->createAccount(Bank::AccountType::CD)->transact(1000);
    c->createAccount(Bank::AccountType::CD)->transact(2000);
    c->createAccount(Bank::AccountType::CD)->transact(3000);
    bank.createCustomer()->setPersonalData
            ("Billings", "Bob", Poco::Data::Date(1992, 2, 2));
    bank.createCustomer()->setPersonalData
            ("Chase", "Caesar", Poco::Data::Date(1993, 3, 3));
    /************************************/
}

void bankTests () {
    /**
     * Create a bank and initialize it with setupBank.
     */
    // Add your code here:
    Bank SBI;
    setupBank(SBI);

    /*
     * (1) Assert that the bank has three customers.
     */
    // Add your code here:
    vector<Customer*> listOfCustomers = SBI.allCustomers();
    assertTrue(listOfCustomers.size()==3," 1.Number of Customers incorrect");
    assertTrue(listOfCustomers.size()!=3," 1.Number of Customers correct");

    /*
     * (2) Assert that the customer with id 0000000002 can be looked up.
     */
    // Add your code here:
    assertTrue(SBI.lookupCustomer("0000000002")==nullptr," 2.Given customer ID 0000000002 is found");
    assertTrue(SBI.lookupCustomer("0000000002")!=nullptr," 2.Given customer ID is not found");

    /*
     * (3) Assert that there is no customer with id 0000000042.
     */
    // Add your code here:
    assertTrue(SBI.lookupCustomer("0000000042")!=nullptr," 3.Given customer ID 0000000042 is not found");

}

void customerTests () {
    /*
     * (1) Create a Customer with sample data. Assert that
     * invoking the overloaded left shift operator produces the
     * expected result. (Hint: use a stringstream.)
     */
    // Add your code here:

    string expected{"0000000001: Priya, Nair (3.3.1993)"};
    Bank bank;
    Customer* c = bank.createCustomer()->setPersonalData
            ("Nair", "Priya", Poco::Data::Date(1993, 3, 3));
    c->createAccount(Bank::Savings);
    //cout<<*c;
    stringstream ss;
    ss<<*c;
    assertTrue(!(expected.compare(ss.str())==0), "1. Expected Customer Details obtained");

}

void accountTests () {
    /**
     * Create a bank and initialize it with setupBank.
     */
    // Add your code here:
    Bank SDB;
    setupBank(SDB);

    /*
     * (1) Lookup Customer 0000000001 (Alice), assert that she is found.
     */
    // Add your code here:
    Customer* c = SDB.lookupCustomer("0000000001");

    assertTrue(c->getFirstName()!="Alice", "1.Alice is the customer with ID 0000000001");
    assertTrue(c->getFirstName()=="Alice", "1.Customer ID 0000000001 does not belong to Alice");


    /*
     * (2) Assert that Alice has 5 accounts.
     */
    // Add your code here:
    vector<Account*> listOfAccounts = c->allAccounts();
    assertTrue(listOfAccounts.size()==5,"2.Number of Accounts of Alice is not 5");
    assertTrue(listOfAccounts.size()!=5,"2.Alice has 5 Accounts");


    /**
     * (3) Assert that the C++-types of Alice's accounts and the
     * types derived from the account id (see Account::accountType)
     * match.
     */
    for(const auto& account : alice->allAccounts()){
        std::string accountId = account->getId();
        Bank::AccountType derivedType = Account::accountType(accountId);

        if(derivedType == Bank::AccountType::Current){
            assertTrue(dynamic_cast<CurrentAccount*>(account)!=nullptr,"Not a current account");
        }
        else if(derivedType == Bank::AccountType::Savings){
            assertTrue(dynamic_cast<SavingsAccount*>(account)!=nullptr,"Not a SAVINGS account");
        }
        else if(derivedType == Bank::AccountType::CD){
            assertTrue(dynamic_cast<CDAccount*>(account)!=nullptr,"Not a CD account");
        }
        else {
            assertTrue(false, "Test failed: Unknown account type");
        }
    }

    /**
     * (4) Assert that Alice has 3 accounts of type CD
     * and that these accounts have the ids "3010000001",
     * "3020000001" and "3030000001". The check must not
     * rely on accounts being returned in a specific sequence.
     *
     * In order to check this, proceed as follows:
     *  * Obtain the ids
     *  * Filter out the CD accounts and count them
     *  * Out the ids in a set and assert that the set contains
     *    the expected ids.
     */
    // Add your code here:
    string accountType {"3"};
    set<string> expectedAccounts {"3010000001","3020000001","3030000001"};
    set<string> existingAccounts;
    for(auto &account:listOfAccounts){
        if(account->getId().substr(0, 1) == accountType){
            existingAccounts.emplace(account->getId());
        }
    }

    assertTrue(!(existingAccounts.size()==3) && !(existingAccounts == expectedAccounts) ,
            "4.Alice has 3 accounts of type CD with IDs as given in expectedAccounts set");


    /**
     * (5) Assert that an attempt to delete account 3040000001
     * throws an invalid_argument exception.
     */
    // Add your code here:
    string err1 = "Invalid Account Id";
    try{
        c->deleteAccount("3040000001");
    }
    catch (invalid_argument const& ex){
        assertTrue(ex.what()!= err1 , "5.Invalid Account Id argument caught");
    }


    /**
     * (6) Assert that an attempt to delete account 3020000001
     * throws a logic_error exception.
     */
    // Add your code here:
    string err2 = "Account Balance is not null";
    try{
        c->deleteAccount("3020000001");
    }
    catch (logic_error const& ex){
        //cout<<ex2.what();
        assertTrue(ex.what()!= err2 , "6.Logical Error exception caught");
    }

    /**
     * (7) Withdraw the deposit from account 3010000001,
     * delete the account and assert that Alice has only
     * 4 accounts left
     */
    // Add your code here:
    c->lookupAccount("3010000001")->transact(-1000);
    c->deleteAccount("3010000001");
    vector<Account*> listOfnewAccounts = c->allAccounts();
    assertTrue(listOfnewAccounts.size()==4, "7.Number of Accounts of Alice is not 4 now");
    assertTrue(listOfnewAccounts.size()!=4, "7.Alice has 4 Accounts now");


    /**
     * (8) Lookup Alice's account 1010000001, create
     * the JSON object representing its data and assert
     * that the account type is "Current" and the balance
     * is 100.
     */
    // Add your code here:

    Poco::JSON::Object::Ptr data = c->lookupAccount("1010000001")->toJson();
    string actTyp = data->get("accountType").toString();
    assertTrue(actTyp!="Current", "8.Account type is Current");
    assertTrue(actTyp=="Current", "8.Account type is not Current");

}

void allTests() {
    bankTests();
    customerTests();
    accountTests();
}
