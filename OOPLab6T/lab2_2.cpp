#include <iostream>
#include <string>

class Worker {
protected:
    std::string name;
    int department;
public:
    Worker(std::string name, int department) : name(name), department(department) {}
    virtual double calculateSalary() = 0;
};

class HourlyEmployee : public Worker {
private:
    double hourlyRate;
    int hoursWorked;
public:
    HourlyEmployee(std::string name, int department, double hourlyRate, int hoursWorked) : Worker(name, department), hourlyRate(hourlyRate), hoursWorked(hoursWorked) {}
    double calculateSalary() override {
        return hourlyRate * hoursWorked;
    }
};

class SalariedEmployee : public Worker {
private:
    double salary;
public:
    SalariedEmployee(std::string name, int department, double salary) : Worker(name, department), salary(salary) {}
    double calculateSalary() override {
        return salary;
    }
};

class InterestEmployee : public Worker {
private:
    double interestRate;
    double sales;
public:
    InterestEmployee(std::string name, int department, double interestRate, double sales) : Worker(name, department), interestRate(interestRate), sales(sales) {}
    double calculateSalary() override {
        return interestRate * sales;
    }
};

int main() {
    HourlyEmployee hourlyEmp("John", 1, 10.0, 40);
    SalariedEmployee salariedEmp("Mary", 2, 3000.0);
    InterestEmployee interestEmp("Bob", 3, 0.05, 100000.0);

    Worker* workers[] = { &hourlyEmp, &salariedEmp, &interestEmp };

    for (auto worker : workers) {
        std::cout << "Salary of " << worker->name << ": " << worker->calculateSalary() << std::endl;
    }

    return 0;
}

