#pragma once
#include <iostream>
#include <iomanip>
#include "degree.h"

using namespace std;

class Student {

	public: 
		const static int numberOfCourses = 3;
	private:
		string studentID;
		string firstName;
		string lastName;
		string email;
		int age;
		int daysInCourse[numberOfCourses];
		DegreeProgram degreeProgram;
	public:
		// Calling default constructor:
		Student();
		// Calling constructor using all of the input parameters:
		Student(string studentID, string firstName, string lastName, string email, int age, int daysInCourse[numberOfCourses], DegreeProgram degreeProgram);
		// Calling Destructor:
		~Student();

		// Inititializing Getters
		string getID();
		string getFullName();
		string getEmail();
		int getAge();
		int* getCourseDurations();
		DegreeProgram getDegreeProgram();

		// Initializing Setters
		void setID(string ID);
		void setfirstName(string firstName);
		void setlastName(string lastName);
		void setEmail(string email);
		void setAge(short age);
		void setCourseDurations(short courseDurations[]);
		void setDegreeProgram(DegreeProgram degree);

		// Print header to organize info about to be printed
		void printHeader();

		// print() to print specific student data
		void print();
};


