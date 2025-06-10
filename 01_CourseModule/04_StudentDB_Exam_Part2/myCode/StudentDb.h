/*
 * StudentDb.h
 *
 *  Created on: 04-Jan-2022
 *      Author: kpriya
 */

#ifndef STUDENTDB_H_
#define STUDENTDB_H_
#include <map>
#include <memory>
#include "Student.h"
#include "Course.h"

/**
 * Class that represents the entire Database
 */
class StudentDb
{
private:
	/**
	 * Private member that stores all the student details in the database
	 */
	std::map <int, Student> students;
	/**
	 * Private member that stores all the courses in the database
	 */
	std::map <int, std::unique_ptr<const Course>> courses;
	/**
	 * Private method for reading from a file and updating the database
	 */
	void readCourses(std::istream &in, unsigned int &totalCourses);

public:
	/**
	 * Default Constructor
	 */
	StudentDb();
	/**
	 * Destructor
	 */
	~StudentDb();
	/**
	 * Method that provides all the courses
	 */
	const std::map<int, std::unique_ptr<const Course> >& getCourses() const;
	/**
	 * Method that provides all the students
	 */
	const std::map<int, Student>& getStudents()const;
	/**
	 * Method that provides a single student's details
	 * @param - matrikelNumber of the student
	 */
	Student& getStudentById(unsigned int matrikelNumber);
	/**
	 * Method that adds a course into the database
	 * @param - &coursename  - address of new course object
	 */
	void addCourses( unsigned int & num,std::unique_ptr<Course> &coursename);
	/**
	 * Method that adds a new student into the database
	 * @param - student -  new student object
	 */
	void addStudent(const Student student);
	void addStudent1(Student& student);
	/**
	 * Member function for writing all the contents of a DB onto an ostream object (to a file)
	 */
	void write(std::ostream& out);
	/**
	 * Member function for restoring database content from a file stream object
	 */
	void read(std::istream& in);
	/**
	 * Member function for parsing input time
	 * @param - &time: reference to input time which is in the form of string
	 * @param - &hr- reference to the output variable to which hours are to be parsed
	 * @param - &min- reference to the output variable to which minutes are to be parsed
	 */
	void setTime(std::string &time, unsigned int &hr, unsigned int &min);
	/**
	 * Member function for parsing input date
	 * @param - &date: reference to input time which is in the form of string
	 * @param - &yr- reference to the output variable to which year is to be parsed
	 * @param - &m- reference to the output variable to which month is to be parsed
	 * @param - &d- reference to the output variable to which date is to be parsed
	 */
	void setDate(std::string &date,unsigned int &yr,unsigned int &m,unsigned int &d);
	/**
	 * Member function to connect to a server and Obtain students data
	 */
	void copyDataFromServer();
	/**
	 * Member function to copy student data obtained from server into the Database
	 */
	bool serverToDB(std::vector<std::string> & completeData);

	virtual Poco::JSON::Object::Ptr toJson() const;

};

#endif /* STUDENTDB_H_ */
