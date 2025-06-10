/*
 * SimpleUI.h
 *
 *  Created on: 04-Jan-2022
 *      Author: kpriya
 */

#ifndef SIMPLEUI_H_
#define SIMPLEUI_H_

#include "StudentDb.h"

/**
 * A class that acts as an interface between the user and studentDB class
 */
class SimpleUI
{
private:
	/**
	 * Private attribute for pointing to the database created in main.cpp
	 */
	StudentDb *sdb;
	/**
	 * Private Member function for getting input from the user and adding a course into the database
	 */
	void addNewCourse();
	/**
	 * Private Member function for getting input from the user and adding a new student into the database
	 */
	void addNewStudent();
	/**
	 * Private Member function for showing all the course information from the database
	 */
	void listallCourses();
	/**
	 * Private Member function for getting input from the user and adding an enrollment for a student
	 */
	void addEnrollemnt();
	/**
	 * Private Member function for showing a student's details based on matriculation number
	 */
	void printStudentInfo();
	/**
	 * Private Member function to find a particular student from a given part of name
	 */
	void searchForAStudent();
	/**
	 * Private Member function for getting input from the user and updating various data
	 */
	void updateStudentInfo();
	/**
	 * Private Member function for writing the contents of db into a file provided by user
	 */
	void writeToFile();
	/**
	 * Private Member function for adding contents into the DB from a file of type .csv provided by the user
	 */
	void readFromFile();

public:
	/**
	 * Parameterized constructor for creating the instance of SimpleUI class
	 * @param address of an object of type StudentDb
	 */
	SimpleUI(StudentDb& db);
	/**
	 * Method for running the database application with various options
	 */
	void run();
	/**
	 * Destructor
	 */
	~SimpleUI();
};

#endif /* SIMPLEUI_H_ */
