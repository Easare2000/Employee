#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Employee {
    protected:
        string name;
        double hourlyWage;
        int hoursWorked;

    public:
        Employee(string name, double hourlyWage, int hoursWorked);

        double calcPay() const;

        string getName() const;
};

class Manager : public Employee{
    private:
        double bonus;

    public:
        Manager(string name, double hourlyWage, int hoursWorked, double bonus);

        double calcPay() const;
};
#endif
