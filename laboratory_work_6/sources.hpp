#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

struct Student
{
    std::string full_name;
    unsigned short int study_group;
    unsigned int credit_card_number;
    unsigned short int grades[4];
};

void fileManager(const std::string, const std::string, const std::string);