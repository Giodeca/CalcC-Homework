#pragma once


class Number {

public:
	float n;
	Number* nextNode;
	Number* previousNode;
	char signOperation;
	char signPrevious;
	float previousResult;

	void CreateNumber();
	void SetResaultToN(const float result);
	void SetNextNode(Number* numb);
	void SetPreviosNode(Number* numb);
};