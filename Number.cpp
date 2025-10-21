#include "Number.h"
#include <iostream>
#include <string>
#include <vector>

void Number::CreateNumber()
{
    while (true)
    {
        std::cout << "Insert number: ";
        std::cin >> n;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Insert Valid Number.\n";
        }
        else
        {
            break;
        }
    }
}

void Number::SetResaultToN(const float result)
{
	n = result;
}

void Number::SetNextNode(Number* numb)
{
    nextNode = numb;
}

void Number::SetPreviosNode(Number* numb)
{
    previousNode = numb;
}


