#ifndef STACK_LL
#define STACK_LL

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct node
{
	int data;
	struct node *next;
};

class stack_ll {
private:
	node *head;
public:
	stack_ll();
	~stack_ll();
	void push(int val);
	void pop();
	void peek();
	void display_all();
};

#endif