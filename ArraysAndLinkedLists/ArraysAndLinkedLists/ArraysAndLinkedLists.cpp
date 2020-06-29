// ArraysAndLinkedLists.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "LinkedList.h"


int main()
{
    LinkedList ll;

    ll.AddPerson(new Person("Bill", "Michigan", 59));
    ll.AddPerson(new Person("Jim", "New York", 32));
    ll.AddPerson(new Person("Cathy", "California", 25));


    Person* arr = new Person[3];
    arr[0].name = "Bill";
    arr[0].state = "california";
    arr[0].age = 22;

    arr[1].name = "Dave";
    arr[1].state = "california";
    arr[1].age = 22;

    arr[2].name = "Kevin";
    arr[2].state = "california";
    arr[2].age = 22;


    for (int i = 0; i < 3; i++)
    {
        std::cout << arr[i].name << std::endl;
    }


    std::cout << ll << std::endl;

}
