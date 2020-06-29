#ifndef __LinkedList_H
#define __LinkedList_H

/*
Copyright 2020 William W. Westlake

Permission is hereby granted, free of charge, to any person obtaining a copy of this software 
and associated documentation files (the "Software"), to deal in the Software without restriction, 
including without limitation the rights to use, copy, modify, merge, publish, distribute, 
sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is 
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial 
portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include <ostream>
#include <string>

typedef struct Person {
public:
    std::string name;
    std::string state;
    int age;

    Person(std::string name, std::string state, int age) : name(name), state(state), age(age) {}

    Person() : name(""), state(""), age(0) {}

} person;


class LinkedList
{
private:

    class Node {
    public:
        Person* person;
        Node* next;
    };

    Node* root;
    Node* tail;


public:
    LinkedList();

    void AddPerson(Person* person)
    {
        Node* newNode = new Node();
        newNode->person = person;
        if (root == nullptr)
        {
            root = newNode;
            tail = root;
            return;
        }
        tail->next = newNode;
        tail = newNode;
    }

    friend std::ostream& operator<<(std::ostream& os, const LinkedList& ll)
    {
        Node* current = ll.root;

        while (current != nullptr)
        {
            os << current->person->name << " " << current->person->state << " " << current->person->age << std::endl;
            current = current->next;
        }

        return os;
    }

};


#endif //LinkedList_H