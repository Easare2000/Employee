//Enoch Asare
//This program collects hourly pay details of employees and calculate the average pay.
//10/15/2023

#include "Employee.h"

Employee::Employee(string theName, double theHourlyWage, int theHoursWorked)
{
    name = theName;
    hourlyWage = theHourlyWage;
    hoursWorked = theHoursWorked;
}

double Employee::calcPay() const
{
    return hourlyWage * hoursWorked;
}

string Employee::getName() const
{
    return name;
}

Manager::Manager(string theName, double theHourlyWage, int theHoursWorked, double theBonus)
: Employee(theName, theHourlyWage, theHoursWorked), bonus(theBonus) {}

double Manager::calcPay() const
{
    return Employee::calcPay()+bonus;
}

int main()
{
  int numManagers;

    cout << "Enter number of managers:";
    cin >> numManagers;

    vector<Manager*> managers;

    for(int i = 0; i < numManagers; ++i){
        string name;
        double hourlyWage, bonus;
        int hoursWorked;

        cout << "Enter manager " << i << " name:";
        cin >> name;
        cout  << "Enter manager " << i << " hourly wage:";
        cin >> hourlyWage;
        cout  << "Enter manager " << i << " hours worked:";
        cin >> hoursWorked;
        cout  << "Enter manager " << i << " bonus:";
        cin >> bonus;

        managers.push_back(new Manager(name,hourlyWage,hoursWorked,bonus));
    }

    double totalPay = 0;
    Manager* highestPaid = managers[0];
    for(int i = 0; i < numManagers; ++i){
        double currentPay = managers[i]->calcPay();
        totalPay += currentPay;

        if(currentPay > highestPaid->calcPay()){
            highestPaid = managers[i];
        }
    }

    cout << "Highest paid manager is "<< highestPaid->getName() << " who is paid " << highestPaid->calcPay() << endl;
    cout << "Average pay is "<< totalPay/numManagers << endl;

    for(int i = 0; i < numManagers; ++i){
        delete managers[i];
    }
    managers.clear();

    return 0;
}

