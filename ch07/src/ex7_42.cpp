#include <iostream>
#include <string>
#include "../include/ex7_42.h"

using std::cout; using std::endl;

std::istream &read(std::istream &is, Employee &worker)
{
    getline(is, worker.name);
    getline(is, worker.title);
    is >> worker.salary;
    return is;
}

std::ostream &print(std::ostream &os, Employee &worker)
{
    os << "Name: " << worker.name << "\n" 
       << "Title: " << worker.title << "\n"
       << "Salary: $" << worker.salary << "\n";
    return os;
}

int main()
{
    cout << "Default constructor:\n";
    Employee worker_default;
    print(cout, worker_default);

    cout << "Name constructor:\n";
    Employee worker_name("Worker Name");
    print(cout, worker_name);

    cout << "Salary constructor:\n";
    Employee worker_salary(100000);
    print(cout, worker_salary);

    cout << "Name and Title constructor:\n";
    Employee worker_name_title("Worker Name", "Job Title");
    print(cout, worker_name_title);

    cout << "Name and Salary constructor:\n";
    Employee worker_name_salary;
    print(cout, worker_name_salary);

    cout << "Full constructor:\n";
    Employee worker_full("Worker Name", "Job Title", 100000);
    print(cout, worker_full);

    cout << "istream constructor:\n";
    Employee worker_is(std::cin);
    print(cout, worker_is);

    return 0;
}
