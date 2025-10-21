#include "OperationCalc.h"
#include <iostream>
#include <string>
#include <vector>
#include "Number.h"


float OperationCalc::Sum(const float a, const float b)
{
	return a+b;
}

float OperationCalc::Subtract(const float a, const float b)
{
	return a-b;
}

float OperationCalc::Divide(const float a, const float b)
{
	return a/b;
}

float OperationCalc::Moltyplication(const float a, const float b)
{
	return a*b;
}

void OperationCalc::SetResoult(const float a,const float b, float& n, const char c)
{
	switch (c)
	{
	case '+':
		n = Sum(a, b);
		break;
	case '-':
		n = Subtract(a, b);
		break;
	case '*':
		n = Moltyplication(a, b);
		break;
	case '/':
		n = Divide(a, b);
		break;
	default:
		break;
	}
	
}

bool OperationCalc::CheckForValidSign(char& c)
{

	switch (c)
	{
	case '+':
		return true;
		break;
	case '-':
		return true;
		break;
	case '*':
		return true;
		break;
	case '/':
		return true;
		break;
	case '=':
		return true;
	default:
		return false;
	}
	
	
}

void OperationCalc::ExecuteOperation(char& c, Number*& head, Number*& tail, float& n)
{
	SetResoult(head->n, tail->n, n, c);
	tail->SetResaultToN(n);
	headNode = tail;
}



void OperationCalc::InsertNewOperator()
{
	char newOperator;
	while (true)
	{
		std::cout << "Insert operator (+, -, *, /,=): ";
		std::cin >> newOperator;

		if (!CheckForValidSign(newOperator))
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Insert Valid operator (+, -, *, /,=):";
			continue;
		}


		if (newOperator == '=') {
			float finalResult = EvaluateExpression(headNode);
			std::cout << "Final Output" << finalResult << std::endl;
			break;
		}

		Number* secondNumberNode = new Number();
		secondNumberNode->CreateNumber();
		tailNode = secondNumberNode;
		headNode->nextNode = secondNumberNode;
		headNode->signOperation = newOperator;
		secondNumberNode->previousNode = headNode;	

		
		ExecuteOperation(newOperator, headNode, tailNode, result);
	}
}
	
	

void OperationCalc::SetHeadNode(Number*& numb)
{
	headNode = numb;
}

float OperationCalc::EvaluateExpression(Number* head)
{
	Number* current = head;
	while (current && current->nextNode)
	{
		char op = current->signOperation;
		if (op == '*' || op == '/')
		{
			float res = 0;
			SetResoult(current->n, current->nextNode->n, res, op);
			current->n = res;
			current->signOperation = current->nextNode->signOperation;
			current->nextNode = current->nextNode->nextNode;
			if (current->nextNode)
				current->nextNode->previousNode = current;
		}
		else
		{
			current = current->nextNode;
		}
	}

	current = head;
	while (current && current->nextNode)
	{
		float res = 0;
		SetResoult(current->n, current->nextNode->n, res, current->signOperation);
		current->n = res;
		current->signOperation = current->nextNode->signOperation;
		current->nextNode = current->nextNode->nextNode;
		if (current->nextNode)
			current->nextNode->previousNode = current;
	}

	return current ? current->n : 0;
}


