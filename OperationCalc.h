#pragma once


class Number;	

class OperationCalc 
{
	float result;
	
public:
	Number* headNode;
	Number* tailNode;

	float Sum(const int a, const int b);
	float Subtract(const int a, const int b);
	float Divide(const int a, const int b);
	float Moltyplication(const int a, const int b);

	void SetResoult(const float a,const float b,float & n,const char c);

	bool CheckForValidSign(char& c);

	void ExecuteOperation(char& c,Number*& head,Number*& tail,float & n);

	void InsertNewOperator();
	void SetHeadNode(Number*& numb);

	float EvaluateExpression(Number* head);

	
};
