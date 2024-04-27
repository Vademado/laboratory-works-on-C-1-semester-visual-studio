#pragma once
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

struct Employee
{
    std::string full_name;
    std::string date_employment;
    std::string post;
    unsigned int base_salary;
};

std::vector<Employee> readDataEmployees(const std::string&);

bool SortingByFullName(const Employee&, const Employee&);

bool SortingByDateEmployment(const Employee&, const Employee&);

bool SortingByBaseSalary(const Employee&, const Employee&);

void print(const std::vector<Employee>&);