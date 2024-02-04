#include <iostream>
#include <fstream>
#include <string>
#include "courses.h"
#include "students.h"

using namespace std;

int main() {
    cout << "***************Menu*****************" << endl;
    cout << "Press 1 for the enrollment of student in a course" << endl;
    cout << "Press 2 for drop a specified course." << endl;
    cout << "Press 3 for Display Students Enrolled Courses." << endl;
    cout << "Press 4 for Update Section of Student for enrolled Course." << endl;
    cout << "Press 5 for Display Total number of Students enrolled in a particular course." << endl;
    cout << "Press 6 for Display course not enrolled by any student." << endl;
    cout << "Press 7 for Display the Student with the minimum number of registered courses." << endl;

    Course courses[5];
    Student students[50];
    int total = 0;
    string id, selectCourse, section;
    int select;
    int min = total;
    string minStudents;
    char repeat;

    do {
        cout << "Enter your option : ";
        cin >> select;

        if (select == 1) {
            ifstream fin("courses.txt");
            int x = 0;
            while (fin >> courses[x].code >> courses[x].chour) {
                getline(fin, courses[x].title);
                x++;
            }

            cout << "Input id =  ";
            cin >> id;
            cout << "Select a course = " << endl;

            for (int i = 0; i < 5; i++) {
                cout << courses[i].code << " " << courses[i].chour << " " << courses[i].title << endl;
            }

            cout << endl << "Enter= ";
            cin >> selectCourse;
            int s = 0;
            bool set = false;

            for (int i = 0; i < 5; i++) {
                if (selectCourse == courses[i].code) {
                    cout << "You are enrolled." << endl;
                    set = true;
                    s = i;
                    break;
                }
            }

            if (!set) {
                cout << "The code is incorrect." << endl;
            }

            cout << "Enter Section Name = ";
            cin >> section;

            students[total].id = id;
            students[total].course = selectCourse;
            students[total].section = section;
            students[total].creditHours = to_string(courses[s].chour);
            total++;

            for (int i = 0; i < total; i++) {
                if (students[i].section != section && students[i].id != id) {
                    cout << "Enrollment in different sections not allowed!" << endl;
                    break;
                } else {
                    cout << "You are enrolled!" << endl;
                    break;
                }
            }
        }

        if (select == 2) {
            cout << "Enter Id = ";
            cin >> id;
            cout << "Enter course to drop = ";
            cin >> selectCourse;

            for (int i = 0; i < total; i++) {
                if (students[i].id == id && students[i].course == selectCourse) {
                    for (int j = i; j < total - 1; j++) {
                        students[j].id = students[j + 1].id;
                        students[j].course = students[j + 1].course;
                        students[j].section = students[j + 1].section;
                        students[j].creditHours = students[j + 1].creditHours;
                    }
                    total--;
                    break;
                }
            }
        }

        if (select == 3) {
            cout << "Enrolled Students are = " << endl;
            for (int i = 0; i < total; i++) {
                cout << students[i].id << "  " << students[i].course << endl;
            }
        }

        if (select == 4) {
            cout << "Enter id = ";
            cin >> id;
            cout << "Enter course = ";
            cin >> selectCourse;
            cout << "Enter section = ";
            cin >> section;

            for (int i = 0; i < total; i++) {
                if (students[i].id == id && students[i].course == selectCourse) {
                    students[i].section = section;
                    break;
                } else {
                    cout << "Course not enrolled." << endl;
                }
            }
        }

        if (select == 5) {
            int count = 0;
            cout << "Enter code = ";
            cin >> selectCourse;
            for (int i = 0; i < total; i++) {
                if (students[i].course == selectCourse) {
                    count++;
                }
            }
            cout << "Total students in course = " << count << endl;
        }

        if (select == 6) {
            for (int i = 0; i < 5; i++) {
                bool enrolled = false;
                for (int j = 0; j < total; j++) {
                    if (students[j].course == courses[i].code) {
                        enrolled = true;
                        break;
                    }
                }
                if (!enrolled) {
                    cout << courses[i].code << endl;
                }
            }
        }

        if (select == 7) {
            for (int i = 0; i < total; i++) {
                int current = 0;
                string curStudent = students[i].id;
                for (int j = 0; j < total; j++) {
                    if (students[i].id == curStudent) {
                        current++;
                    }
                }
                if (current < min) {
                    min = current;
                    minStudents = curStudent;
                }
            }
            cout << "Minimum courses are of = " << minStudents << " with " << min << " course" << endl;
        }

        cout << "Press Y to continue = ";
        cin >> repeat;

    } while (repeat == 'Y');

    return 0;
}
