#pragma once


class Number;	

class OperationCalc 
{
	float result;
	
public:
	Number* headNode;
	Number* tailNode;

	float Sum(const float a, const float b);
	float Subtract(const float a, const float b);
	float Divide(const float a, const float b);
	float Moltyplication(const float a, const float b);

	void SetResoult(const float a,const float b,float & n,const char c);

	bool CheckForValidSign(char& c);

	void ExecuteOperation(char& c,Number*& head,Number*& tail,float & n);

	void InsertNewOperator();
	void SetHeadNode(Number*& numb);

	float EvaluateExpression(Number* head);

	
};
