#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

struct Student {
    string name;
    int course;
    char group;
    int grades[20];
    int count;
};

bool createStudent(Student &s) {
    cout << "enter name: ";
    cin >> s.name;

    cout << "enter course: ";
    cin >> s.course;

    cout << "enter group: ";
    cin >> s.group;

    cout << "enter grades (up to 20, -1 to stop): ";

    s.count = 0;

    for (int i = 0; i < 20; i++) {
        int grade;
        cin >> grade;

        if (grade == -1)
            break;

        s.grades[s.count] = grade;
        s.count++;
    }

    return s.count > 0;
}

bool saveStudent(ofstream &outFile, const Student &s) {
    outFile << s.name << " " << s.course << " " << s.group << " ";

    for (int i = 0; i < s.count; i++) {
        if (i > 0)
            outFile << ",";

        outFile << s.grades[i];
    }

    outFile << endl;
    return true;
}

double averageGrade(const Student &s) {
    double sum = 0;

    for (int i = 0; i < s.count; i++) {
        sum += s.grades[i];
    }

    return s.count > 0 ? sum / s.count : 0;
}

void printStudent(const Student &s) {
    cout << "Name: " << s.name
         << ", Course " << s.course
         << ", Group " << s.group
         << ", Average grade " << averageGrade(s)
         << endl;
}

void printWorstStudent(ifstream &inFile) {
    Student s;
    Student worstStudent;

    double worstAverage = 101;
    bool found = false;

    string line;

    while (getline(inFile, line)) {
        stringstream ss(line);

        if (!(ss >> s.name >> s.course >> s.group))
            continue;

        s.count = 0;

        string gradesText;
        getline(ss, gradesText);

        stringstream gradesStream(gradesText);
        string grade;

        while (getline(gradesStream, grade, ',') && s.count < 20) {
            stringstream value(grade);

            if (value >> s.grades[s.count])
                s.count++;
        }

        if (s.count == 0)
            continue;

        double avg = averageGrade(s);

        if (!found || avg < worstAverage) {
            worstStudent = s;
            worstAverage = avg;
            found = true;
        }
    }

    if (found) {
        printStudent(worstStudent);
    }
    else {
        cout << "No students found" << endl;
    }
}

int main() {
    ofstream outFile("output5.txt");

    if (!outFile) {
        cerr << "Error opening output file" << endl;
        return -1;
    }

    int numStudents;

    cout << "enter number of students: ";
    cin >> numStudents;

    if (numStudents <= 0) {
        cout << "Invalid number of students" << endl;
        return 1;
    }

    Student s;

    for (int i = 0; i < numStudents; i++) {
        if (createStudent(s)) {
            saveStudent(outFile, s);
        }
    }

    outFile.close();

    ifstream inFile("output5.txt");

    if (!inFile) {
        cerr << "Error opening file for reading" << endl;
        return -1;
    }

    printWorstStudent(inFile);

    inFile.close();
    return 0;
}