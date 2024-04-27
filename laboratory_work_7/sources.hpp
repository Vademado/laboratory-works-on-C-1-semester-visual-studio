#pragma once
#include <fstream>
#include <iostream>
#include <string>

struct Employee
{
    std::string full_name;
    std::string date_employment;
    std::string post;
    unsigned int base_salary;
};

struct Node
{
    Employee employee;
    Node* pPrev;
    Node* pNext;
};

struct List
{
    Node* pFirst = nullptr;
    Node* pEnd = nullptr;
};

void addBegin(List& list, Node* p);

void addEnd(List& list, Node* p);

void removeNode(List& list, unsigned short index);

Node* extractFront(List& list);

Node* extractBack(List& list);

void print(List& list);

void clearList(List& list);

void insertSort(List& list);

List readDataEmployees(const std::string& dataFilePath);