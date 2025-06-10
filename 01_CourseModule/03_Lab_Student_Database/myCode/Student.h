/*
 * Student.h
 *
 *  Created on: 04-Jan-2022
 *      Author: kpriya
 */

#ifndef STUDENT_H_
#define STUDENT_H_
#include <vector>
#include <string>
#include <Poco/DateTime.h>
#include <Poco/Data/Date.h>
#include <Poco/Data/Time.h>
#include "Enrollment.h"
#include "Address.h"

/**
 * A class that represents a student in the database
 */
class Student
{
private:
	/**
	 * static private attribute to denote the MatrikelNumber of the next student who will be added into the DB
	 */
	static unsigned int nextMatrikelNumber;
	/**
	 * Private member that acts as Id of a student
	 */
	unsigned int matrikelNumber;
	/**
	 * Private attribute for the first Name of a student
	 */
	std::string firstName;
	/**
	 * Private attribute for the Last Name of a student
	 */
	std::string lastName;
	/**
	 * Private attribute for storing the date of birth of a student
	 */
	Poco::Data::Date dateOfBirth;
	/**
	 * Private attribute for storing the address of a student
	 */
	Address address;
	/**
	 * Private attribute for storing all the enrollments of a student
	 */
	std::vector<Enrollment> enrollments;

public:
	/**
	 * Default constructor
	 */
	Student();
	/**
	 * Parameterized constructor for initializing the student object
	 * @param - all the private members of the class are initialized by the parameters
	 * */
	Student(std::string firstName,std::string lastName,Poco::Data::Date dateOfBirth, Address address);
	/**
	 * Destructor
	 */
	~Student();
	/**
	 *Member function for providing the Matriculation number of the student
	 */
	unsigned int getMatrikelNumber() const;
	/**
	 *Member function for providing the first Name of the student
	 */
	const std::string& getFirstName() const;
	/**
	 *Member function for providing the Last Name of the student
	 */
	const std::string& getLastName() const;
	/**
	 *Member function for providing the date of birth of the student
	 */
	const Poco::Data::Date& getDateOfBirth() const;
	/**
	 *Member function for providing the address of the student
	 */
	const Address& getAddress() const;
	/**
	 *Member function for providing all the enrollments of a student
	 */
	const std::vector<Enrollment>& getEnrollments() const;
	/**
	 *Member function for setting the first Name of the student
	 */
	void setFirstName(const std::string &firstName);
	/**
	 *Member function for setting the Last Name of the student
	 */
	void setLastName(const std::string &lastName);
	/**
	 *Member function for setting the date of birth of the student
	 */
	void setDateOfBirth(const Poco::Data::Date &dateOfBirth);
	/**
	 *Member function for setting the address of the student
	 */
	void setAddress(const Address &address);
	/**
	 *Member function for adding a single enrollment for the student
	 */
	bool addEnrollments(Enrollment &enrollment);
	/**
	 *Member function for replacing the entire vector of enrollments of a student
	 */
	void updateEnrollments(const std::vector<Enrollment> &enrollments);
	/**
	 * Method for writing on to an ostream like writing to a file of type .csv
	 */
	void write(std::ostream& out);
};

#endif /* STUDENT_H_ */
