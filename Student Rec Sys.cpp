#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Student class to store student details
class Student {
private:
    string id;
    string name;
    string course;
    int marks;

public:
    Student(string id, string name, string course, int marks) {
        this->id = id;
        this->name = name;
        this->course = course;
        this->marks = marks;
    }

    string getId() { return id; }
    string getName() { return name; }
    string getCourse() { return course; }
    int getMarks() { return marks; }

    void setName(string name) { this->name = name; }
    void setCourse(string course) { this->course = course; }
    void setMarks(int marks) { this->marks = marks; }

    void displayStudent() {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Course: " << course << endl;
        cout << "Marks: " << marks << endl;
    }
};

// StudentRecordSystem class to manage student records
class StudentRecordSystem {
private:
    vector<Student> students;

public:
    void run();
    void insertStudent();
    void searchStudent();
    void updateAcademicRecords();
    void modifyStudentRecord();
    void generateMarkSheet();
    void deleteStudentRecord();
};

void StudentRecordSystem::run() {
    while (true) {
        cout << "\n1. Insert new Student" << endl;
        cout << "2. Search any Student" << endl;
        cout << "3. Update academic records" << endl;
        cout << "4. Modify Student Record" << endl;
        cout << "5. Generate Mark sheet" << endl;
        cout << "6. Delete Student Record" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;
        cin.ignore(); // Clear input buffer

        switch (choice) {
            case 1: insertStudent(); break;
            case 2: searchStudent(); break;
            case 3: updateAcademicRecords(); break;
            case 4: modifyStudentRecord(); break;
            case 5: generateMarkSheet(); break;
            case 6: deleteStudentRecord(); break;
            case 7: cout << "Exiting..." << endl; return;
            default: cout << "Invalid choice. Please try again." << endl;
        }
    }
}

void StudentRecordSystem::insertStudent() {
    string id, name, course;
    int marks;
    cout << "Enter Student ID: ";
    getline(cin, id);
    cout << "Enter Student Name: ";
    getline(cin, name);
    cout << "Enter Student Course: ";
    getline(cin, course);
    cout << "Enter Student Marks: ";
    cin >> marks;
    cin.ignore(); // Clear input buffer

    students.push_back(Student(id, name, course, marks));
    cout << "Student added successfully." << endl;
}

void StudentRecordSystem::searchStudent() {
    string id;
    cout << "Enter Student ID to search: ";
    getline(cin, id);
    for (Student &student : students) {
        if (student.getId() == id) {
            student.displayStudent();
            return;
        }
    }
    cout << "Student not found." << endl;
}

void StudentRecordSystem::updateAcademicRecords() {
    string id;
    cout << "Enter Student ID to update records: ";
    getline(cin, id);
    for (Student &student : students) {
        if (student.getId() == id) {
            int marks;
            cout << "Enter new marks: ";
            cin >> marks;
            cin.ignore(); // Clear input buffer
            student.setMarks(marks);
            cout << "Academic records updated successfully." << endl;
            return;
        }
    }
    cout << "Student not found." << endl;
}

void StudentRecordSystem::modifyStudentRecord() {
    string id;
    cout << "Enter Student ID to modify: ";
    getline(cin, id);
    for (Student &student : students) {
        if (student.getId() == id) {
            string name, course;
            int marks;
            cout << "Enter new name: ";
            getline(cin, name);
            cout << "Enter new course: ";
            getline(cin, course);
            cout << "Enter new marks: ";
            cin >> marks;
            cin.ignore(); // Clear input buffer
            student.setName(name);
            student.setCourse(course);
            student.setMarks(marks);
            cout << "Student record modified successfully." << endl;
            return;
        }
    }
    cout << "Student not found." << endl;
}

void StudentRecordSystem::generateMarkSheet() {
    string id;
    cout << "Enter Student ID to generate mark sheet: ";
    getline(cin, id);
    for (Student &student : students) {
        if (student.getId() == id) {
            cout << "\n--- Mark Sheet ---" << endl;
            student.displayStudent();
            cout << "------------------" << endl;
            return;
        }
    }
    cout << "Student not found." << endl;
}

void StudentRecordSystem::deleteStudentRecord() {
    string id;
    cout << "Enter Student ID to delete: ";
    getline(cin, id);
    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->getId() == id) {
            students.erase(it);
            cout << "Student record deleted successfully." << endl;
            return;
        }
    }
    cout << "Student not found." << endl;
}

int main() {
    StudentRecordSystem srs;
    srs.run();
    return 0;
}
