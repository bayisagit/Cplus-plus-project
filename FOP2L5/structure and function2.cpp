#include <iostream>
#include <fstream>
using namespace std;
struct student {
    int ID;
    string Name;
    int Mark;
    char Grade;
};
void getdata(student students[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Enter ID, Name, and Mark for student " << i + 1 << ": ";
        cin >> students[i].ID >> students[i].Name >> students[i].Mark;
        students[i].Grade = (students[i].Mark >= 50) ? 'P' : 'F';
    }
}
void writeToFile(student students[], int n) {
    ofstream file("students");
    if (file.is_open()) {
        for (int i = 0; i < n; i++) {
            file << students[i].ID << " " << students[i].Name << " " << students[i].Mark << " " << students[i].Grade << endl;
        }
        file.close();
      cout << "Data written to students.txt successfully!" << endl;

    } else {
        cout << "Error opening file for writing!" << endl;
    }
}
void readFromFile() {
    ifstream file("students");
    if (file.is_open()) {
        cout << "ID\tName\tMark\tGrade" << endl;
        int ID, Mark;
        string Name;
        char Grade;
      while(file >> ID >> Name >> Mark >> Grade) {
            cout << ID << "\t" << Name << "\t" << Mark << "\t" << Grade << endl;
        }
        file.close();
    } else {
        cout << "Error opening file for reading!" << endl;
    }
}
void update(student students[], int n, int id, int newMark) {
    for (int i = 0; i < n; i++) {
        if (students[i].ID == id) {
            students[i].Mark = newMark;
            students[i].Grade = (students[i].Mark >= 50) ? 'P' : 'F';
            break;
        }
    }
}

int main() {

    int n;
    cout << "Enter the number of students: ";
    cin >> n;
    int MAX_STUDENTS = n;
    student students[MAX_STUDENTS];

    getdata(students, n);
    writeToFile(students, n);

    cout << "\nData from students.txt:" << endl;
    readFromFile();

    int idToUpdate, newMark;
    cout << "\nEnter student ID to update: ";
    cin >> idToUpdate;
    cout << "Enter new mark: ";
    cin >> newMark;

    update(students, n, idToUpdate, newMark);
    writeToFile(students, n);

    cout << "\nUpdated data from students.txt:" << endl;
    readFromFile();

    return 0;
}