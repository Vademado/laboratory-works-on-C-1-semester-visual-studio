#include "sources.hpp"

void part_1()
{
    float carburetor, ignition_system, pistons;
    float economy = 0;
    std::cout << "Enter the % fuel economy of the new carburetor: ";
    std::cin >> carburetor;
    economy += (1 - economy) * (carburetor / 100);
    std::cout << "Enter the % fuel economy of the new ignition system: ";
    std::cin >> ignition_system;
    economy += (1 - economy) * (ignition_system / 100);
    std::cout << "Enter the % fuel economy of the new piston ring:";
    std::cin >> pistons;
    economy += (1 - economy) * (pistons / 100);
    std::cout << "Total savings:" << economy * 100 << "%" << std::endl;
}

void part_2()
{
    float a, b, c, r, s;
    std::cout << "Enter the sides of the brick (a, b, c):";
    std::cin >> a >> b >> c;
    std::cout << "Window dimensions (r, s):";
    std::cin >> r >> s;
    if (((a <= r && b <= s) || (a <= s && b <= r)) &&
        ((a <= r && c <= s) || (a <= s && c <= r)) &&
        ((c <= r && b <= s) || (c <= s && b <= r)))
    {
        std::cout << "It will pass" << std::endl;
    }
    else
    {
        std::cout << "It will not pass" << std::endl;
    }
}