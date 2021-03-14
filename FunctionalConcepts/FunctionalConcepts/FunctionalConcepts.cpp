// FunctionalConcepts.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <list>
#include <vector>
//#include "list.hpp"
#include "collct_functions.hpp"


int main(void)
{
    std::vector<int> int_list{ 1,2,3,4,5,6,7,8,9 };
    std::vector<int> int_result = map<int>(int_list, [](int item) { return item * 3;  });
    std::vector<int> filt_result = filter<int>(int_result, [](int item) { return item % 2 != 0; });
    std::vector<std::tuple<int, int>, std::allocator<int>> zip_result = zip<int, int>(int_list, int_result);


    std::cout << "int_result" << std::endl;
    for (int item : int_result)
    {
        std::cout << item << std::endl;
    }

    std::cout << "filt_result" << std::endl;
    for (int item : filt_result)
    {
        std::cout << item << std::endl;
    }

    std::cout << "zip_result" << std::endl;

    for (auto item : zip_result)
    {
        std::cout << std::get<0>(item) << ", " << std::get<1>(item) << std::endl;
    }

    return 0;
}

