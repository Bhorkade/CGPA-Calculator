#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

struct Course {
    string name;
    char grade;
    double credit;
    double gradePoint;
};

double getGradePoint(char grade) {
    switch (toupper(grade)) {
        case 'A':
            return 10.0;
        case 'B':
            return 8.0;
        case 'C':
            return 6.0;
        case 'D':
            return 5.0;
        case 'E':
            return 4.0;
        case 'F':
            return 0.0;
        default:
            return -1.0;
    }
}

int main() {
    int numberOfCourses;

    cout << "====================================\n";
    cout << "        CGPA CALCULATOR\n";
    cout << "====================================\n";

    cout << "Enter number of courses: ";
    cin >> numberOfCourses;

    if (numberOfCourses <= 0) {
        cout << "Invalid number of courses.\n";
        return 0;
    }

    vector<Course> courses;

    double totalCredits = 0.0;
    double totalGradePoints = 0.0;

    for (int i = 0; i < numberOfCourses; i++) {
        Course course;

        cout << "\nCourse " << i + 1 << "\n";

        cout << "Enter course name: ";
        cin >> course.name;

        cout << "Enter credit hours: ";
        cin >> course.credit;

        if (course.credit <= 0) {
            cout << "Invalid credit hours.\n";
            return 0;
        }

        while (true) {
            cout << "Enter grade (A/B/C/D/E/F): ";
            cin >> course.grade;

            course.grade = toupper(course.grade);
            course.gradePoint = getGradePoint(course.grade);

            if (course.gradePoint != -1) {
                break;
            }

            cout << "Invalid grade. Please try again.\n";
        }

        courses.push_back(course);

        totalCredits += course.credit;
        totalGradePoints += course.gradePoint * course.credit;
    }

    double gpa = totalGradePoints / totalCredits;

    cout << "\n====================================\n";
    cout << "          RESULT\n";
    cout << "====================================\n";

    cout << left << setw(20) << "Course"
         << setw(10) << "Grade"
         << setw(12) << "Credits"
         << "Grade Point\n";

    cout << "------------------------------------\n";

    for (const Course& course : courses) {
        cout << left << setw(20) << course.name
             << setw(10) << course.grade
             << setw(12) << course.credit
             << course.gradePoint << "\n";
    }

    cout << "\nTotal Credits     : " << totalCredits << endl;
    cout << "Total Grade Points: " << totalGradePoints << endl;

    cout << fixed << setprecision(2);
    cout << "Semester GPA      : " << gpa << endl;
    cout << "Overall CGPA      : " << gpa << endl;

    cout << "\nThank you for using CGPA Calculator!\n";

    return 0;
}