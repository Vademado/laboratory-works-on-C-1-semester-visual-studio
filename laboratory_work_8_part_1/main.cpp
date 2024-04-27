#include "sources.hpp"

int main()
{
    int numberIterations = 1000, containerSize = 10000;

    AddingElementsToEnd(containerSize, numberIterations);
    SearchingElements(containerSize);
    RemovingElementsFromBeginning(containerSize);

    return 0;
}