/*
 * Course.h
 *
 *  Created on: 04-Jan-2022
 *      Author: kpriya
 */

#ifndef COURSE_H_
#define COURSE_H_
#include <map>
#include <string>

/**
 * An abstract class that represents a course in the database
 * It acts as a base class for the weekly and block courses
 */
class Course
{
private:
	/**
	 * A static private attribute that stores the property major internally as a char and mapped to a string
	 */
	static std::map<unsigned char, std::string> majorById;

protected:
	/**
	 * Protected member course key that denoted the id of the course
	 */
	unsigned int courseKey;
	/**
	 * Protected attribute that denotes the course name
	 */
	std::string title;
	/**
	 * A character that represents the first letter of the name of the Major
	 */
	unsigned char major;
	int semester;
	/**
	 * Protected member for storing the credit points for the course
	 */
	float creditPoints;


public:
	/**
	 * Parameterized constructor that initializes the course
	 * @params : all the protected members of the course that are accessible to the derived classes as well
	 */
	Course(unsigned int courseKey,std::string title, std::string major,std::string sem, float creditPoints=-1);
	/**
	 *Pure virtual destructor
	 */
	virtual ~Course()=0;
	/**
	* Returns the semester in which the course takes or took place as an
	* abbreviated string in the format "WiSe2021", "SoSe2022", "WiSe2022" etc.
	*
	* @return the semester
	*/
	std::string getSemester() const;
	/**
	 * Member function for providing the major data of the course
	 */
	std::string getMajor() const;
	/**
	 * Pure virtual method for listing all the details of a course
	 * - Has no implementation in this class. Derived classes will have own implementations
	 */

	virtual void print() const = 0;
	/**
	 * Member function for providing the id of the course
	 */
	unsigned int getCourseKey() const;
	/**
	 * Member function for providing the name of the course
	 */
	const std::string& getTitle() const;
	/**
	 * Member function for providing the credit points of the course
	 */
	float getCreditPoints() const;
	/**
	 * Virtual Member function for writing all the details of a course onto an ostream object (to a file)
	 * Derived classes also to have same method implementation
	 */
	virtual void write(std::ostream& out) const;
};

#endif /* COURSE_H_ */
