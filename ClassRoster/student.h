#pragma once
#include <iostream>
#include <iomanip>
#include "degree.h"

using namespace std;

// D1.  Create the class Student with associated variables:
class Student {

	public: 
		// variable for size of array (must be constant):
		const static int numberOfCourses = 3;
	// 2c. private variables can only be accessed/modified externally through getters and setters:
	private:
		string studentID;
		string firstName;
		string lastName;
		string email;
		short age;
		short courseDurationInDays[numberOfCourses];
		DegreeProgram degreeProgram;
	public:
		// Default constructor:
		Student();
		// 2d. Constructor using all of the input parameters provided in the table:
		Student(string studentID, string firstName, string lastName, string email, short age, short courseDurationInDays[numberOfCourses], DegreeProgram degreeProgram);
		// Destructor:
		~Student();

		// 2a. Getters - an accessor for each instance variable from part D1:
		string getID();
		string getFullName();
		string getEmail();
		short getAge();
		short* getCourseDurations();
		DegreeProgram getDegreeProgram();

		// 2b. Setters - a mutator for each instance variable from part D1:
		void setID(string ID);
		void setfirstName(string firstName);
		void setlastName(string lastName);
		void setEmail(string email);
		void setAge(short age);
		void setCourseDurations(short courseDurations[]);
		void setDegreeProgram(DegreeProgram degree);

		// 2e. print() to print specific student data
		void print();
};


