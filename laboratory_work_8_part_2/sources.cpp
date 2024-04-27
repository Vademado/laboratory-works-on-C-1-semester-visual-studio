#include "sources.hpp"

std::vector<Employee> readDataEmployees(const std::string& dataFilePath)
{
    std::ifstream dataFile(dataFilePath);

    if (!dataFile)
    {
        std::cerr << "Failed to open file" << std::endl;
    }

    std::vector<Employee> vector;
    Employee empl;
    std::string base_salary;
    while (dataFile >> empl.full_name >> empl.date_employment >> empl.post >> base_salary)
    {
        empl.base_salary = (unsigned int)std::stoi(base_salary);

        vector.push_back(empl);
    }

    dataFile.close();

    return vector;
}

bool SortingByFullName(const Employee& empl1, const Employee& empl2)
{
    return empl1.full_name < empl2.full_name;
}

bool SortingByDateEmployment(const Employee& empl1, const Employee& empl2)
{
    std::vector<unsigned short int> dateEmploymentEmpl1;
    std::istringstream stream1(empl1.date_employment);
    std::string token;
    while (std::getline(stream1, token, '/'))
    {
        dateEmploymentEmpl1.insert(dateEmploymentEmpl1.begin(), std::stoi(token));
    }

    std::vector<unsigned short int> dateEmploymentEmpl2;
    std::istringstream stream2(empl2.date_employment);
    while (std::getline(stream2, token, '/'))
    {
        dateEmploymentEmpl2.insert(dateEmploymentEmpl2.begin(), std::stoi(token));
    }

    return std::lexicographical_compare(dateEmploymentEmpl1.begin(), dateEmploymentEmpl1.end(),
        dateEmploymentEmpl2.begin(), dateEmploymentEmpl2.end());
}

bool SortingByBaseSalary(const Employee& empl1, const Employee& empl2)
{
    return empl1.base_salary < empl2.base_salary;
}

void print(const std::vector<Employee>& employersVector)
{
    for (Employee employee : employersVector)
    {
        std::cout << "Employee's full name: " << employee.full_name << std::endl;
        std::cout << "Date of employment: " << employee.date_employment << std::endl;
        std::cout << "Post: " << employee.post << std::endl;
        std::cout << "Base salary: " << employee.base_salary << std::endl;
        std::cout << "#############################################" << std::endl;
    }
    std::cout << std::endl
        << std::endl;
}