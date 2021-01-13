#pragma once
#include "student.h";

class Roster {
	private:
		int lastIndex = -1;
		const static int numberOfStudents = 5;
	public:
		// Array of pointers to hold the data provided in the studentData table:
		Student* classRosterArray[numberOfStudents];

	public:
		void parse(string row);

		void add(string studentID, string firstName, string lastName, string emailAddress, int age,
			int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);

		void remove(string studentID);

		void printAll();

		void printAverageDaysInCourse(string studentID);

		void printInvalidEmails();

		void printByDegreeProgram(DegreeProgram degreeProgram);

		// Destructor
		~Roster();
};
