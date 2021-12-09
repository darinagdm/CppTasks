#include <iostream>
#include <string>
#define DEBUG 0
#define N 100
using namespace std;

class Human {
protected:
    string name;
public:
    Human(string name): name(name) {
        if (DEBUG) cout << "Create Human " + name << endl;
    }
    virtual ~Human() {
        if (DEBUG) cout << "Delete Human " + name << endl;
    }
    virtual void print() {
        cout << name;
    }
    void hello() {
        print();
        cout << endl;
    }
};

class Student: virtual public Human {
protected:
    int course;
    string univ;
public:
    Student(string name, int course = 1, string univ = "NUK"):
        Human(name), course(course), univ(univ) {
        if (DEBUG) cout << "Create Student " + name << endl;
    }
    virtual ~Student() {
        if (DEBUG) cout << "Delete Student " + name << endl;
    }
    virtual void print() {
        Human::print();
        cout << ' ' << univ << ' ' << course;
    }
};

class Teacher: virtual public Human {
protected:
    double salary;
    string univ;
public:
    Teacher(string name, double salary = 11.1, string univ = "NPU"):
        Human(name), salary(salary), univ(univ) {
        if (DEBUG) cout << "Create Teacher " + name << endl;
    }
    virtual ~Teacher() {
        if (DEBUG) cout << "Delete Teacher " + name << endl;
    }
    virtual void print() {
        Human::print();
        cout << ' ' << univ << ' ' << salary;
    }
};

class PGS: public Student, public Teacher {
public:
    PGS(string name, int course = 2, double salary = 7.77, string univ = "KPI"):
        Human(name), Student(name, course, univ), Teacher(name, salary, univ) {
        if (DEBUG) cout << "Create PGS " + Student::name << endl;
    }
    virtual ~PGS() {
        if (DEBUG) cout << "Delete PGS " + Student::name << endl;
    }
    virtual void print() {
        Student::print();
        cout << ' ' << salary;
        //cout << ' ' << &(Student::univ) << ' ' << &(Teacher::univ);
    }
};

int main() {
    int n = 4;
    Human* arr[N] = {
        new Human("H"),
        new Student("S"),
        new Teacher("T"),
        new PGS("P")
    };
    for (int i = 0; i < n; i++)
        arr[i]->hello();
    for (int i = 0; i < n; i++)
        delete arr[i];
    return 0;
}
