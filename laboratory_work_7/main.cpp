#include "sources.hpp"

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cerr << "Invalid number of arguments";
        return 1;
    }

    std::string dataFilePath = argv[1];

    List employeesList = readDataEmployees(dataFilePath);

    std::cout << "Before sorting:" << std::endl;
    print(employeesList);

    insertSort(employeesList);

    std::cout << "After sorting:" << std::endl;
    print(employeesList);

    clearList(employeesList);

    return 0;
}