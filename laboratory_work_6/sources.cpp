#include "sources.hpp"

void printStudent(const Student& student)
{
    std::cout << "Full name: " << student.full_name << std::endl;
    std::cout << "Study group: " << student.study_group << std::endl;
    std::cout << "Credit card number: " << student.credit_card_number << std::endl;
    std::cout << "Assessment for exams: ";
    for (size_t i = 0; i < 4; ++i)
    {
        std::cout << student.grades[i] << ' ';
    }
    std::cout << '\n'
        << "#############################################" << std::endl;
}

void fileManager(const std::string mode, const std::string representation, const std::string fileName)
{
    if (mode == "-r")
    {
        std::ifstream readFile;
        if (representation == "bin")
        {
            readFile.open(fileName, std::ios::binary);
        }
        else
        {
            readFile.open(fileName);
        }

        if (!readFile)
        {
            std::cerr << "Failed to open file" << std::endl;
            return;
        }

        Student student;
        if (representation == "bin")
        {
            char currentByte;
            while (readFile.get(currentByte))
            {
                student.full_name = "";
                char endString = '\0';
                while (currentByte != endString)
                {
                    student.full_name += currentByte;
                    readFile.get(currentByte);
                }

                readFile.read((char*)&student.study_group, sizeof(unsigned short int));
                readFile.read((char*)&student.credit_card_number, sizeof(unsigned int));
                for (size_t i = 0; i < 4; ++i)
                {
                    readFile.read((char*)&student.grades[i], sizeof(unsigned short int));
                }

                printStudent(student);
            }
        }
        else
        {
            std::string study_group, credit_card_number, mark1, mark2, mark3, mark4;
            while (readFile >> student.full_name >> study_group >> credit_card_number >> mark1 >> mark2 >> mark3 >> mark4)
            {
                student.study_group = (unsigned short int)std::stoi(study_group);
                student.credit_card_number = (unsigned int)std::stoi(credit_card_number);
                student.grades[0] = (unsigned short int)std::stoi(mark1);
                student.grades[1] = (unsigned short int)std::stoi(mark2);
                student.grades[2] = (unsigned short int)std::stoi(mark3);
                student.grades[3] = (unsigned short int)std::stoi(mark4);

                printStudent(student);
            }
        }

        readFile.close();
    }
    else if (mode == "-w")
    {
        std::ofstream writeFile;
        if (representation == "bin")
        {
            writeFile.open(fileName, std::ios::binary | std::ios::app);
        }
        else
        {
            writeFile.open(fileName, std::ios::app);
        }

        if (!writeFile)
        {
            std::cerr << "Failed to open file" << std::endl;
            return;
        }

        unsigned int n;
        std::cout << "Enter count of students: ";
        std::cin >> n;
        for (size_t i = 0; i < n; ++i)
        {
            std::string full_name;
            std::cout << "Enter the student's name: ";
            std::cin >> full_name;

            unsigned short study_group;
            std::cout << "Enter the study group: ";
            std::cin >> study_group;

            unsigned int credit_card_number;
            std::cout << "Enter credit card number: ";
            std::cin >> credit_card_number;

            unsigned short int mark1, mark2, mark3, mark4;
            std::cout << "Enter 4 assessments for exams: ";
            std::cin >> mark1 >> mark2 >> mark3 >> mark4;
            unsigned short int grades[] = { mark1, mark2, mark3, mark4 };

            if (representation == "bin")
            {
                writeFile.write(full_name.c_str(), full_name.size() + 1);
                writeFile.write((char*)&study_group, sizeof(unsigned short int));
                writeFile.write((char*)&credit_card_number, sizeof(unsigned int));
                for (size_t i = 0; i < 4; ++i)
                {
                    writeFile.write((char*)&grades[i], sizeof(unsigned short int));
                }
            }
            else
            {
                writeFile << full_name << " " << study_group << " " << credit_card_number << " " << mark1 << " " << mark2 << " " << mark3 << " " << mark4 << std::endl;
            }

            std::cout << "#############################################" << std::endl;
        }

        writeFile.close();
    }
    else
    {
        std::ofstream clearFile;
        if (representation == "bin")
        {
            clearFile.open(fileName, std::ios::binary | std::ios::trunc);
        }
        else
        {
            clearFile.open(fileName, std::ios::trunc);
        }
        clearFile.close();
    }
}