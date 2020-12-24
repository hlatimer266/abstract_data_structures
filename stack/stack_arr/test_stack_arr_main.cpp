#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "stack_arr.hpp"

using namespace std;

int main() {
	stack_arr stack(5);

	stack.push(5);
	stack.push(8);
	stack.push(10);
	stack.push(99);
	cout << "pushed 5,8,10,99 onto the stack" << endl;
	stack.display_all();
	cout << "" << endl;

	cout << "pop top of the stack (should be 99)" << endl;
	stack.pop();
	stack.display_all();
	cout << "" << endl;

	cout << "push 75 onto stack (should be at the top of the stack" << endl;
	stack.push(75);
	stack.peek();
	cout << "" << endl;

	cout << "perform 3 pop operations on the stack" << endl;
	stack.pop();
	stack.pop();
	stack.pop();
	cout << "display all values left on the stack" << endl;
	stack.display_all();
	cout << "" << endl;

	cout << "trigger doublye of stack size by pushing 5 more values (7,13,14,15,16)" << endl;
	stack.push(7);
	stack.push(13);
	stack.push(14);
	stack.push(15);
	stack.push(16);
	cout << "display contents of stack" << endl;
	stack.display_all();


	return 0;
}