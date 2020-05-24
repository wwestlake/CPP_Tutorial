
#include <iostream>
#include "CPP_Tutirial_1.h"


int main()
{
    for (int i = 0; i < 3; i++)
    {
        std::cout << i << std::endl;
    }

    std::list<std::string> mylist = { "bill", "westlake", "programming" };

    strlist otherList = { "this", "is", "a", "list", "of","strings" };

    for (auto str : mylist)
    {
        std::cout << str << std::endl;
    }

    for (auto str : otherList)
    {
        std::cout << str << std::endl;
    }

    std::cout << "Starting" << std::endl;

    int a = add(1, 2);

    std::cout << a << std::endl;

    test1();

    return 0;
}

