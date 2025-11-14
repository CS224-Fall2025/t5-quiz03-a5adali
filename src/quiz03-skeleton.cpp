#include <iostream>
#include <string>
using namespace std;

class Employee {
    protected:
        string name;
        double salary;

    public:
        static int employeeCount;

        //constructor for increment
        Employee(string n, double s) {
            name = n;
            salary = s;
            employeeCount++;
            }

        virtual void displayInfo() {
            cout << "Name : " << name << ", Salary : " << salary << endl;} //prints a=name and salary

        static void showTotalEmployees() {
            cout << "Total Employees : " << employeeCount << endl;}

        virtual ~Employee() {} //destructor
};

int Employee::employeeCount = 0;

class Staff : public Employee {
    private:
        string department;

    public:
        Staff(string n, double s, string dept): Employee(n, s), department(dept) {} //constructor
        void displayInfo() override {
            cout << "Name : " << name << " (Staff), Salary : " << salary << endl;
        }
};

class Faculty : public Employee {
    private:
        string department;
    public:
        Faculty(string n, double s, string dept) : Employee(n, s) {} //constructor
        void displayInfo() override {
            cout << "Name : " << name << " (Faculty), Salary: " << salary << endl;
        }
};

int main() {
    int n;
    cin >> n;

    Employee* employees[n];

    for (int i = 0; i < n-1; i++) {
        string type, name, dept;
        double salary;
        cin >> type >> name >> salary >> dept;
        if (type == "Staff") {
            employees[i] = new Staff(name, salary, dept);
        }
        else if (type == "Faculty") {
            employees[i] = new Faculty(name, salary, dept);
        }
    }

    for (int i = 0; i < n-1; i++) {
        employees[i]->displayInfo();
    }
    Employee::showTotalEmployees();

    for (int i = 0; i < n; i++) {
        delete employees[i];
    }

    return 0;
}