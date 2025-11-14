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
        Staff(string n, double s) : Employee(n, s), department() {}

        void displayInfo() override {
            cout << "Name: " << name << " (Staff), Salary: " << salary << endl;
        }
};

class Faculty : public Employee {
    private:
        string department;
    public:
        Faculty(string n, double s) : Employee(n, s), department() {}

        void displayInfo() override {
            cout << "Name: " << name << " (Faculty), Salary: " << salary << endl;
        }
};

int main() {
    int n;
    cin >> n;

    Employee** employees = new Employee*[n];

    for (int i = 0; i < n; i++) {
        string type, name;
        double salary;
        cin >> type >> name >> salary;

        if (type == "Staff") {
            employees[i] = new Staff(name, salary);
        } 
        else if (type == "Faculty") {
            employees[i] = new Faculty(name, salary);
        }
        else {
            employees[i] = nullptr;git
        }
    }

    for (int i = 0; i < n; i++) {
        if (employees[i])
            employees[i]->displayInfo();
    }

    Employee::showTotalEmployees();

    
    for (int i = 0; i < n; i++) {
        delete employees[i];
    }

    delete[] employees;

    return 0;
}
