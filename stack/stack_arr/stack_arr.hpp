#ifndef STACK_ARR
#define STACK_ARR

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class stack_arr {
private:
	int *data;
	int size;
	int capacity;
public:
	stack_arr(int size);
	~stack_arr();
	void push(int val);
	void pop();
	void peek();
	void display_all();
};

#endif