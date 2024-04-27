#include "sources.hpp"

std::string mode, representation, fileName;

int main(int argc, char* argv[])
{

    if (argc < 4)
    {
        std::cout << "Error: Insufficient command line arguments" << std::endl;
        return 1;
    }

    mode = argv[1];
    representation = argv[2];
    fileName = argv[3];

    fileManager(mode, representation, fileName);

    return 0;
}