/*
 * Address.h
 *
 *  Created on: 04-Jan-2022
 *      Author: kpriya
 */

#ifndef ADDRESS_H_
#define ADDRESS_H_
#include<string>

/**
 * Immutable class for representing the address of a student
 */
class Address
{
private:
	/**
	 * Private attribute for street data of an address
	 */
	std::string street;
	/**
	 * Private attribute for postal code data in an address
	 */
	unsigned short postalCode;
	/**
	 * Private attribute for name of city in an address
	 */
	std::string cityName;
	/**
	 * Private attribute for any additional line in address
	 */
	std::string additionalInfo;
public:
	/**
	 * Default constructor
	 */
	Address();
	/**
	 * Parameterised constructor that creates object of type Address
	 *  @param - all the private memebers of the class
	 */
	Address(std::string street,unsigned short postalCode,std::string cityName,std::string additionalInfo = " ");
	/**
	 * Destructor
	 */
	~Address();
	/**
	 * Method that provides street data to the caller
	 */
	const std::string& getStreet() const;
	/**
	 * Member funtion for providing the postalcode info in the address
	 */
	unsigned short getPostalCode() const;
	/**
	 * Member function for providing the CityName in the address to the caller
	 */
	const std::string& getCityName() const;
	/**
	 * Method for providing the value of additional info in address to the caller
	 */
	const std::string& getAdditionalInfo() const;
};

#endif /* ADDRESS_H_ */
