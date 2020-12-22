#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "stack_arr.hpp"

using namespace std;

	stack_arr::stack_arr(int size){
		data = new int[size];
		capacity = size;
		size = 0;
		for (int i=0; i<size; i++){data[i] = NULL;}
	}

	stack_arr::~stack_arr(){
		int *tmp;
		for(int i; i<size; i++){
			tmp = data[i];
			delete(tmp);
		}
		delete(data);
	}

	void stack_arr::push(int val) {
		data[size] = val;
		size++;
	}

	void stack_arr::pop() {
		for(int i; i<size-1; i++){
			data[i] = data[i+1];
		}
		size--;
	}

	void stack_arr::peek() {
		if (data[0] == NULL) {
			cout << "stack is empty" << endl;
		} else {
			cout << "Value at top of the stack = " << data[0] << endl;
		}
		
	}

	void _print_stack(int idx) {
		if (idx == size-1) {
			return;
		} else {
			cout << data[idx] << " ";
			_print_stack(idx+1);
		}
	}

	void stack_arr::display_all() {

		if (size == 0) {
			cout << "stack is empty" << endl;
		} else {
			_print_stack(0);
		}
	}
