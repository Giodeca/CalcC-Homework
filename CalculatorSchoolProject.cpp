#include <iostream>
#include "OperationCalc.h"
#include "Number.h"

int main()
{
    OperationCalc* calculator = new OperationCalc();
  
	Number* numberFirstNode = new Number();
    char operatorType;
	float result;

    numberFirstNode->CreateNumber();
    calculator->SetHeadNode(numberFirstNode);
    calculator->InsertNewOperator();
   
    delete calculator;
    return 0;
}

