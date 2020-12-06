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

	// create the Student object by using add method
	add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
}

