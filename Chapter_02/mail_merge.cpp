// Write a program that outputs an acceptance letter for Makerere University. It should prompt a user to enter their first name, last name, study program, academic year.
// The program should have autodates

// Example:

// Date: 27th August 2026

// To: John Okello,

// Dear John,

// CONGRATULATIONS! I am pleased to inform you that the Makerere University 
// Admissions Board has approved your application for admission to the 
// 2027/2028 academic year.

// You have been offered a place for the following course:
// PROGRAM: Bachelor of Science in Computer and Communication Engineering

// As a student of Makerere University, you will be part of a historic 
// institution dedicated to academic excellence and innovation. Please ensure 
// that you report to the Academic Registrar's office with your original 
// academic documents for verification during the orientation week.

// We look forward to welcoming you to the Makerere University.

// Yours sincerely,


// John Doe
// Registra
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

// Returns the correct ordinal suffix for a day number (1st, 2nd, 3rd, 4th...)
string ordinalSuffix(int day) {
    if (day >= 11 && day <= 13) return "th";
    switch (day % 10) {
        case 1: return "st";
        case 2: return "nd";
        case 3: return "rd";
        default: return "th";
    }
}

// Builds today's date automatically as "27th August 2026"
string getAutoDate() {
    time_t now = time(0);
    tm *ltm = localtime(&now);

    string months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    int day = ltm->tm_mday;
    int year = 1900 + ltm->tm_year;
    string month = months[ltm->tm_mon];

    return to_string(day) + ordinalSuffix(day) + " " + month + " " + to_string(year);
}

// Determines the academic year admission applies to (next intake year pair)
string getAcademicYear() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int year = 1900 + ltm->tm_year;
    int startYear = year + 1;
    int endYear = startYear + 1;
    return to_string(startYear) + "/" + to_string(endYear);
}

int main() {
    string firstName, lastName, program;

    cout << "Enter your first name: ";
    getline(cin, firstName);

    cout << "Enter your last name: ";
    getline(cin, lastName);

    cout << "Enter the program/course you were admitted to: ";
    getline(cin, program);

    string date = getAutoDate();
    string academicYear = getAcademicYear();

    cout << "\n----------------------------------------------------\n\n";
    cout << "Date: " << date << "\n\n";
    cout << "To: " << firstName << " " << lastName << ",\n\n";
    cout << "Dear " << firstName << ",\n\n";
    cout << "CONGRATULATIONS! I am pleased to inform you that the Makerere University\n";
    cout << "Admissions Board has approved your application for admission to the\n";
    cout << academicYear << " academic year.\n\n";
    cout << "You have been offered a place for the following course:\n";
    cout << "PROGRAM: " << program << "\n\n";
    cout << "As a student of Makerere University, you will be part of a historic\n";
    cout << "institution dedicated to academic excellence and innovation. Please ensure\n";
    cout << "that you report to the Academic Registrar's office with your original\n";
    cout << "academic documents for verification during the orientation week.\n\n";
    cout << "We look forward to welcoming you to Makerere University.\n\n";
    cout << "Yours sincerely,\n\n";
    cout << "John Doe\n";
    cout << "Registrar\n";
    cout << "\n----------------------------------------------------\n";

    return 0;
}