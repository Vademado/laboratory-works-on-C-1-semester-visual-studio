#include "sources.hpp"

List readDataEmployees(const std::string& dataFilePath)
{
    std::ifstream dataFile(dataFilePath);

    if (!dataFile)
    {
        std::cerr << "Failed to open file" << std::endl;
    }

    List list;
    Employee empl;
    std::string base_salary;
    while (dataFile >> empl.full_name >> empl.date_employment >> empl.post >> base_salary)
    {
        empl.base_salary = (unsigned int)std::stoi(base_salary);
        Node* p = new Node;
        p->employee = empl;

        addEnd(list, p);
    }

    dataFile.close();

    return list;
}

void addBegin(List& list, Node* p)
{
    if (list.pFirst == nullptr)
    {
        list.pFirst = list.pEnd = p;
        list.pFirst->pPrev = list.pFirst->pNext = list.pEnd->pPrev = list.pEnd->pNext = p;
    }
    else
    {
        p->pNext = list.pFirst;
        p->pPrev = list.pEnd;
        list.pFirst->pPrev = list.pEnd->pNext = p;
        list.pFirst = p;
    }
}

void addEnd(List& list, Node* p)
{
    if (list.pEnd == nullptr)
    {
        list.pFirst = list.pEnd = p;
        list.pFirst->pPrev = list.pFirst->pNext = list.pEnd->pPrev = list.pEnd->pNext = p;
    }
    else
    {
        p->pPrev = list.pEnd;
        p->pNext = list.pFirst;
        list.pFirst->pPrev = list.pEnd->pNext = p;
        list.pEnd = p;
    }
}

void removeNode(List& list, unsigned short index)
{
    if (list.pFirst == nullptr)
    {
        std::cerr << "ERROR: List is empty" << std::endl;
        return;
    }
    Node* p = list.pFirst;
    if (p->pPrev == p)
    {
        list.pEnd = list.pFirst = nullptr;
    }
    else
    {
        for (size_t i = 0; i < index; ++i)
        {
            p = p->pNext;
        }
        p->pPrev->pNext = p->pNext;
        p->pNext->pPrev = p->pPrev;
        if (list.pFirst == p)
            list.pFirst = p->pNext;
        if (list.pEnd == p)
            list.pEnd = p->pPrev;
    }
    delete p;
}

Node* extractFront(List& list)
{
    if (list.pFirst == nullptr)
        return nullptr;
    Node* p = list.pFirst;
    list.pFirst = list.pFirst->pNext;
    if (p == list.pFirst)
        list.pFirst = list.pEnd = nullptr;
    else
    {
        list.pFirst->pPrev = list.pEnd;
        list.pEnd->pNext = list.pFirst;
    }
    return p;
}

Node* extractBack(List& list)
{
    if (list.pEnd == nullptr)
        return nullptr;
    Node* p = list.pEnd;
    list.pEnd = list.pEnd->pPrev;
    if (p == list.pEnd)
        list.pFirst = list.pEnd = nullptr;
    else
    {
        list.pFirst->pPrev = list.pEnd;
        list.pEnd->pNext = list.pFirst;
    }
    return p;
}

void print(List& list)
{
    Node* p = list.pFirst;
    do
    {
        std::cout << "Employee's full name: " << p->employee.full_name << std::endl;
        std::cout << "Date of employment: " << p->employee.date_employment << std::endl;
        std::cout << "Post: " << p->employee.post << std::endl;
        std::cout << "Base salary: " << p->employee.base_salary << std::endl;
        std::cout << "#############################################" << std::endl;

        p = p->pNext;
    } while (p != list.pFirst);
    std::cout << std::endl;
}

void clearList(List& list)
{
    while (list.pFirst != nullptr)
    {
        removeNode(list, 0);
    }
}

void insertSort(List& list)
{
    Node* p = list.pFirst->pNext;
    while (p != list.pFirst)
    {
        Node* currentP = p;
        while (currentP->employee.full_name < currentP->pPrev->employee.full_name && currentP != list.pFirst)
        {
            Node* tmp = currentP->pPrev;
            currentP->pPrev->pPrev->pNext = currentP;
            currentP->pPrev = currentP->pPrev->pPrev;
            tmp->pNext = currentP->pNext;
            tmp->pNext->pPrev = tmp;
            tmp->pPrev = currentP;
            currentP->pNext = tmp;
            if (list.pFirst == tmp)
                list.pFirst = currentP;
            if (list.pEnd == currentP)
                list.pEnd = tmp;
            tmp = currentP->pPrev;
        }
        p = p->pNext;
    }
}