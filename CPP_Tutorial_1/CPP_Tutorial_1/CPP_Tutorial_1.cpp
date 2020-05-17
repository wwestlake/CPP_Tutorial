// CPP_Tutorial_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int add(int a, int b)
{
    return a + b;
}

int addRef(const int& a, const int& b)
{
    return a + b;
}

void addRef2(const int& a, const int& b, int& result)
{
    result = a + b;
}

void addPtr(int * a, int * b, int * result)
{
    (*result) = (*a) + (*b);
}

void addArray(int len, int* vals, int& retval)
{
    int result = 0;
    for (int i = 0; i < len; i++)
    {
        result += *(vals + i);
        std::cout << "Address " << (vals + i) << std::endl;
    }
    retval = result;
}


int test1()
{
    int* vals = new int[3]{ 3,4,5 };
    int result;

    addArray(3, vals, result);

    std::cout << "Results: ";
    for (int i = 0; i < 3; i++)
    {
        if (i < 2) {
            std::cout << vals[i] << " + ";
        }
        else {
            std::cout << vals[i] << " = " << result << std::endl;
        }
    }

    delete[] vals;
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
