#include "student.h";

// Default constructor:
Student::Student(){
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->email = "";
	this->age = 0;
	for (int i = 0; i < numberOfCourses; i++) this->courseDurationInDays[i] = 0;
	this->degreeProgram = DegreeProgram::SOFTWARE;
}

// 2d. Constructor using all of the input parameters provided in the table:
Student::Student(string studentID, string firstName, string lastName, string email, short age, short courseDurations[], DegreeProgram degreeProgram) {
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->email = email;
	this->age = age;
	for (int i = 0; i < numberOfCourses; i++) this->courseDurationInDays[i] = courseDurations[i];
	this->degreeProgram = degreeProgram;
}

// Destructor:
Student::~Student() {}

// 2a. Defining Getters:
string Student::getID() { return this->studentID; }
string Student::getFullName() { return this->firstName + " " +  this->lastName; }
string Student::getEmail() { return this->email; }
short Student::getAge() { return this->age; }
short* Student::getCourseDurations() { return this->courseDurationInDays; }
DegreeProgram Student::getDegreeProgram() { return this->degreeProgram; }

// 2b. Defining Setters:
void Student::setID(string ID) { this->studentID = ID;  }
void Student::setfirstName(string firstName) { this->firstName = firstName;  }
void Student::setlastName(string lastName) { this->lastName = lastName; }
void Student::setEmail(string email) { this->email = email; }
void Student::setAge(short age) { this->age = age; }
void Student::setCourseDurations(short courseDurations[]) {
	for (int i = 0; i < numberOfCourses; i++) this->courseDurationInDays[i] = courseDurations[i];
}
void Student::setDegreeProgram(DegreeProgram degree) { this->degreeProgram = degree; }

// 2e. Defining print function
void Student::print() {
	cout << this->getID() << '\t';
	cout << this->getFullName() << '\t';
	cout << this->getEmail() << '\t';
	cout << this->getAge() << '\t';
	for (int i = 0; i < numberOfCourses - 1; i++) cout << this->getCourseDurations()[i] << ',';
	cout << this->getCourseDurations()[numberOfCourses - 1] << '\t';
	cout << degreeProgramStrings[this->getDegreeProgram()] << '\t';
}
