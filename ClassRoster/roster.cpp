#include "roster.h";

// E3a-E3f: implementation of Roster methods

// parse each row (data is delimited by commas) and create the Student object
void Roster::parse(string row) {
	
	// extract student ID:
	int commaIndex = row.find(",");
	string studentID = row.substr(0, commaIndex);

	// variable for the index right after first comma
	int afterCommaIndex = commaIndex + 1;
	// re-assign commaIndex to the next comma's index
	commaIndex = row.find(',', afterCommaIndex);
	// extract first name
	string firstName = row.substr(afterCommaIndex, commaIndex - afterCommaIndex);
	
	// continue same pattern to extract the rest of the data:
	afterCommaIndex = commaIndex + 1;
	commaIndex = row.find(',', afterCommaIndex);
	// extract last name
	string lastName = row.substr(afterCommaIndex, commaIndex - afterCommaIndex);
	
	afterCommaIndex = commaIndex + 1;
	commaIndex = row.find(',', afterCommaIndex);
	// extract email address
	string emailAddress = row.substr(afterCommaIndex, commaIndex - afterCommaIndex);

	afterCommaIndex = commaIndex + 1;
	commaIndex = row.find(',', afterCommaIndex);
	// convert string age to int and extract
	int age = stoi(row.substr(afterCommaIndex, commaIndex - afterCommaIndex));

	afterCommaIndex = commaIndex + 1;
	commaIndex = row.find(',', afterCommaIndex);
	// convert string daysInCourse1 to int and extract
	int daysInCourse1 = stoi(row.substr(afterCommaIndex, commaIndex - afterCommaIndex));

	afterCommaIndex = commaIndex + 1;
	commaIndex = row.find(',', afterCommaIndex);
	// convert string daysInCourse2 to int and extract
	int daysInCourse2 = stoi(row.substr(afterCommaIndex, commaIndex - afterCommaIndex));

	afterCommaIndex = commaIndex + 1;
	commaIndex = row.find(',', afterCommaIndex);
	// convert string daysInCourse3 to int and extract
	int daysInCourse3 = stoi(row.substr(afterCommaIndex, commaIndex - afterCommaIndex));

	afterCommaIndex = commaIndex + 1;
	commaIndex = row.find(',', afterCommaIndex);
	// convert string degree to corresponding DegreeProgram
	DegreeProgram degreeProgram = SOFTWARE;
	string degree = row.substr(afterCommaIndex, commaIndex - afterCommaIndex);
	if (degree.substr(0, 2) == "SE") DegreeProgram degreeProgram = SECURITY;
	else if (degree.substr(0, 2) == "NE") DegreeProgram degreeProgram = NETWORK;

	// E2b: create the Student object and add it to classRosterArray by using add method
	add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
}

// E3a: implement add method (sets instance variables and updates the roster)
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age,
	int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
	// convert daysInCourse variables to array of ints:
	int daysInCourseArr[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	// create a new Student object by calling constructor and add it to classRosterArray
	classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourseArr, degreeProgram);
}

// E3b: implement remove method (removes the student object with the passed in studentID)
void Roster::remove(string studentID) {
	// default varable to false (id is not found)
	bool idFound = false;
	for (int i = 0; i < numberOfStudents; i++) {
		// if id is found, set idFound to true and make the corresponding Student object disappear:
		if (classRosterArray[i]->getID() == studentID) {
			idFound = true;
			// make sure Student object isn't the last one in the array
			if (i < numberOfStudents - 1) {
				// swap the Student object's current index with the last one
				Student* temp = classRosterArray[i];
				classRosterArray[i] = classRosterArray[numberOfStudents - 1];
				classRosterArray[numberOfStudents - 1] = temp;
			}
			// Decrement last index which makes the object invisible
			Roster::lastIndex--;
		}
	}
}
