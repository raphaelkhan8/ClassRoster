// main.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <string>
#include "roster.h";

using namespace std;

int main()
{
    // A.  Modify the “studentData Table” to include your personal information as the last item.
    const string studentData[] =
    { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Khan,Raphael,raphaelkhan8@gmail.com,28,10,17,21,SOFTWARE",
    };

    const int numberOfStudents = 5;

    // F1. Print the course title, the programming language used, your WGU student ID, and your name.
    cout << "Course Title: SCRIPTING AND PROGRAMMING - APPLICATIONS - C867\n"
        "Programming Language: C++\n"
        "StudentID: 001546693\n"
        "Name: Raphael Khan\n" << std::endl;

    // F2. Create instance of Roster class using default constructor:
    Roster classRoster;

    // F3. Add each student to classRoster using this instance's parse method:
    for (int i = 0; i < numberOfStudents; i++) {
        classRoster.parse(studentData[i]);
    }

    // F4a: Call printAll method to print all the students:
    cout << "Displaying all students: " << std::endl;
    classRoster.printAll();

    // F4b: Call printInvalidEmails method to print all invalid emails:
    cout << "Displaying all invalid emails: " << std::endl;
    classRoster.printInvalidEmails();
    cout << std::endl;

    // F4c: Loop through classRosterArray and print the average days in course for each student:
    for (int i = 0; i < numberOfStudents; i++) {
        cout << "Dispalying average days in course for: " + classRoster.classRosterArray[i]->getFullName() << std::endl;
        classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getID());
    }

    // F4d: Call printByDegreeProgram to show students by degree program:
    for (int i = 0; i < 3; i++) {
        // loop through degreeProgramStrings to get enum int coressponding to student's degree program
        cout << "Displaying students by degree program: " << degreeProgramStrings[i] << std::endl;
        // call this instances's printDegreeProgram (cast passed-in int to DegreeProgram) to show student by degreeProgram
        classRoster.printByDegreeProgram((DegreeProgram)i);
    }

    // F4e: Call remove method to remove studentID "A3"/print all students and then call remove again to see error message
    cout << "Removing student A3: " << std::endl;
    classRoster.remove("A3");

    cout << "Removing student A3 (again): " << std::endl;
    classRoster.remove("A3");

    // Pause window until user presses button to close it
    system("pause");
    return 0;
}