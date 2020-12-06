#include "roster.h";
#include "student.h";

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
	// default varable to false (assume id is not found)
	bool idFound = false;
	for (int i = 0; i < Roster::lastIndex; i++) {
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
	// print success message and the rest of the Students after student object is "removed"
	if (idFound) {
		cout << studentID << " was removed from the roster." << std::endl << std::endl;
		this->printAll();
	}
	// else (if studentID was not found), print an error message
	else {
		cout << studentID << " was not found." << std::endl << std::endl;
	}
}

// E3c: implement printAll method (prints a complete tab-separated list of student data for all students)
void Roster::printAll() {
	// print the Header
	classRosterArray[0]->printHeader();
	// loop through roster array and use Student's print method to print each student's info
	for (int i = 0; i < Roster::lastIndex; i++) {
		classRosterArray[i]->print();
	}
}

// E3d: implement printAverageDaysInCourse method (prints student's average number of days in all three courses)
void Roster::printAverageDaysInCourse(string studentID) {
	bool idFound = false;
	for (int i = 0; i < Roster::lastIndex; i++) {
		// if id is found, set idFound to true and make the corresponding Student object disappear:
		if (classRosterArray[i]->getID() == studentID) {
			idFound = true;
			cout << studentID << " (Average Days Per Course): ";
			cout << (classRosterArray[i]->getCourseDurations()[0] +
				classRosterArray[i]->getCourseDurations()[1] +
				classRosterArray[i]->getCourseDurations()[2])
				/ 3 << std::endl;
		}
	}
	if (!idFound) cout << "Student ID not found :(" << std::endl;
}

// E3e: implement printInvalidEmails method (verifies student emails and prints all invalid emails)
// All emails should include an at ('@') sign and period '.' and should not include any spaces.
void Roster::printInvalidEmails() {
	// assume there are no invalid emails
	bool invalidEmails = false;
	// loop through classRosterArray and get emails
	for (int i = 0; i < Roster::lastIndex; i++) {
		string email = (classRosterArray[i]->getEmail());
		// if a space is found OR the email doesn't contain "@" OR the email doesn't contain "."
		if (std::getline(std::cin, email) || email.find('@') == string::npos || email.find('.') == string::npos) {
			// set invaledEmails to true and print the invalid email and their corresponding name
			invalidEmails = true;
			cout << email << ": " << classRosterArray[i]->getFullName() << std::endl;
		}
	}
	// print message if no invalid emails are found
	if (!invalidEmails) cout << "No invalid emails found :D" << std::endl;
}

// E3f: implemt printByDegreeProgram method (prints out student info for a degree program specified by degree program
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	//print header
	classRosterArray[0]->printHeader();
	// loop through classRosterArray and look for student's whose degreeProgram matches passed in value
	for (int i = 0; i < Roster::lastIndex; i++) {
		// if degreeProgram's match, print the student's info
		if (Roster::classRosterArray[i]->getDegreeProgram() == degreeProgram) {
			classRosterArray[i]->print();
		}
	}
	cout << std::endl;
}