#include <iostream>
#include <vector>


using namespace std;

typedef struct DoBStruct {
    int day;
    int month;
    int year;
} DoB;

typedef struct SubjectResultStruct {
    double marks;
    string name;
    SubjectResultStruct() {
        marks = 0.0;
        name = "";
    }
} SubjectResult;

typedef struct StudentStruct {
    string name;
    DoB dob;
    vector<SubjectResult> subjectResults;
    StudentStruct() {
        name = "";
        dob = {0,0,0};
        subjectResults = {};
    }
    string toString() {
        string subjects;
        for (auto i = subjectResults.begin(); i != subjectResults.end(); ++i) {
            subjects += i->name + ": " + to_string(i->marks);
            if (i+1 != subjectResults.end()) {
                subjects += ", ";
            }
        }
        string result = "Name: " + this->name + " | DoB: " + to_string(this->dob.day) + "/" + to_string(this->dob.month) +
         "/" + to_string(this->dob.year) + " | Results: " + subjects;
        return result;
    }
    double getAverageScore() {
        double result = 0;
        for (auto i = subjectResults.begin(); i != subjectResults.end(); ++i) {
            result +=i->marks;
        }
        return result/3;
    }
} Student;

typedef struct StudentListStruct {
    // Yeah i mean... vector is *technically* a dynamic array right...
    // And that means the constructor will be the function to initialize an empty array
    vector<Student> list;
    void push(Student pStudent) {
        list.push_back(pStudent);
    }
    //Print all students
    void print() {
        for (auto i = list.begin(); i != list.end(); ++i) {
            cout<< i->toString() << endl;
        }
    }
    //Get the highest average student
    int getHighestAverage() {
        int result = 0;
        int step = 0;
        for (auto i = list.begin(); i != list.end(); ++i) {
            if (i->getAverageScore() > list[result].getAverageScore()) {
                result = step;
            }
            step++;
        }
        return result;
    }
} StudentList;

Student createNewStudent(string pName, DoB pDob, vector<SubjectResult> pSubjectResult) {
    Student *student = new Student();
    student->name = pName;
    student->dob = pDob;
    student->subjectResults = pSubjectResult;
    return *student;
}

SubjectResult newSubject(string pName, double pMarks) {
    SubjectResult *subjectResult = new SubjectResult();
    subjectResult->name = pName;
    subjectResult->marks = pMarks;
    return *subjectResult;
}

int main() {
    StudentList *studentList = new StudentList();
    studentList->push(createNewStudent("Mike",DoB{16,8,2002},
    *(new vector<SubjectResult>({newSubject("Math",7.8),newSubject("Physics",4.0),newSubject("Computer Science",4.0)}))));
    studentList->push(createNewStudent("Anthony",DoB{16,8,2002},
    *(new vector<SubjectResult>({newSubject("Math",10.0),newSubject("Physics",10.0),newSubject("Computer Science",10.0)}))));
    studentList->push(createNewStudent("Adoft Hitler",DoB{20,4,1889},
    *(new vector<SubjectResult>({newSubject("Math",9.0),newSubject("Physics",3.0),newSubject("Computer Science",1.2)}))));
    studentList->push(createNewStudent("Luke",DoB{16,8,2002},
    *(new vector<SubjectResult>({newSubject("Math",3.0),newSubject("Physics",6.0),newSubject("Computer Science",10.0)}))));
    studentList->print();
    cout << "Highest Average Marks: " << endl;
    cout << studentList->list[studentList->getHighestAverage()].toString() << endl;
}