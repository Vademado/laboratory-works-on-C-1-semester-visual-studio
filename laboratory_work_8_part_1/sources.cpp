#include "sources.hpp"

void AddingElementsToEnd(const unsigned int containerSize, const unsigned int numberIterations)
{
    double summaryTimeVector = 0., summaryTimeList = 0.;

    std::vector<int> vector;
    std::srand(time(0));
    for (size_t i = 0; i < containerSize; ++i)
    {
        vector.push_back(rand());
    }

    std::vector<int> vector1;
    for (size_t i = 0; i < numberIterations; ++i)
    {
        vector1.assign(vector.begin(), vector.end());
        auto start = std::chrono::steady_clock::now();
        vector1.push_back(rand());
        auto end = std::chrono::steady_clock::now();
        auto executionTimeMilliseconds = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

        summaryTimeVector += executionTimeMilliseconds.count();
    }
    std::cout << "Average execution time of the operation of adding an element to the end of the container std::vector in milliseconds: " << summaryTimeVector / numberIterations << std::endl;

    std::list<int> list;
    std::srand(time(0));
    for (size_t i = 0; i < containerSize; ++i)
    {
        list.push_back(rand());
    }

    std::list<int> list1;
    for (size_t i = 0; i < numberIterations; ++i)
    {
        list1.assign(list.begin(), list.end());
        auto start = std::chrono::steady_clock::now();
        list1.push_back(rand());
        auto end = std::chrono::steady_clock::now();
        auto executionTimeMilliseconds = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

        summaryTimeList += executionTimeMilliseconds.count();
    }

    std::cout << "Average execution time of the operation of adding an element to the end of the container std::list in milliseconds: " << summaryTimeList / numberIterations << std::endl
        << std::endl;
}

void SearchingElements(const unsigned int containerSize)
{
    double summaryTimeVector = 0., summaryTimeList = 0.;

    std::vector<int> vector;
    std::srand(time(0));
    for (size_t i = 0; i < containerSize; ++i)
    {
        vector.push_back(rand());
    }

    for (size_t i = 0; i < containerSize; ++i)
    {
        auto start = std::chrono::steady_clock::now();
        std::find(vector.begin(), vector.end(), vector[i]);
        auto end = std::chrono::steady_clock::now();
        auto executionTimeMilliseconds = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

        summaryTimeVector += executionTimeMilliseconds.count();
    }
    std::cout << "Average execution time of the element search operation in the std container::vector in milliseconds: " << summaryTimeVector / containerSize << std::endl;

    std::list<int> list;
    std::srand(time(0));
    for (size_t i = 0; i < containerSize; ++i)
    {
        list.push_back(rand());
    }

    for (size_t i = 0; i < containerSize; ++i)
    {
        auto start = std::chrono::steady_clock::now();
        std::find(list.begin(), list.end(), *std::next(list.begin(), i));
        auto end = std::chrono::steady_clock::now();
        auto executionTimeMilliseconds = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

        summaryTimeList += executionTimeMilliseconds.count();
    }
    std::cout << "Average execution time of the element search operation in the std container::list in milliseconds: " << summaryTimeList / containerSize << std::endl
        << std::endl;
}

void RemovingElementsFromBeginning(const unsigned int containerSize)
{
    double summaryTimeVector = 0., summaryTimeList = 0.;

    std::vector<int> vector;
    std::srand(time(0));
    for (size_t i = 0; i < containerSize; ++i)
    {
        vector.push_back(rand());
    }

    for (size_t i = 0; i < containerSize; ++i)
    {
        auto start = std::chrono::steady_clock::now();
        vector.erase(vector.begin());
        auto end = std::chrono::steady_clock::now();
        auto executionTimeMilliseconds = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

        summaryTimeVector += executionTimeMilliseconds.count();
    }
    std::cout << "Average execution time of the operation of removing an element from the beginning of the container std::vector in milliseconds: " << summaryTimeVector / containerSize << std::endl;

    std::list<int> list;
    std::srand(time(0));
    for (size_t i = 0; i < containerSize; ++i)
    {
        list.push_back(rand());
    }

    for (size_t i = 0; i < containerSize; ++i)
    {
        auto start = std::chrono::steady_clock::now();
        list.pop_front();
        auto end = std::chrono::steady_clock::now();
        auto executionTimeMilliseconds = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

        summaryTimeList += executionTimeMilliseconds.count();
    }
    std::cout << "Average execution time of the operation of removing an element from the beginning of the container std::list in milliseconds: " << summaryTimeList / containerSize << std::endl
        << std::endl;
}