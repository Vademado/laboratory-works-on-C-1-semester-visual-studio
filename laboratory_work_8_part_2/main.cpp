#include "sources.hpp"

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cerr << "Invalid number of arguments";
        return 1;
    }

    std::string dataFilePath = argv[1];
    std::vector<Employee> employersVector = readDataEmployees(dataFilePath);

    std::cout << "Employers-vector before sorting by date of employment:" << std::endl
        << std::endl;
    print(employersVector);

    std::sort(employersVector.begin(), employersVector.end(), SortingByDateEmployment);

    std::cout << "Employers-vector after sorting by date of employment:" << std::endl
        << std::endl;
    print(employersVector);

    return 0;
}