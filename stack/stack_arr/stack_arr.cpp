#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "stack_arr.hpp"

using namespace std;

	stack_arr::stack_arr(int size_arr){
		data = new int[size_arr];
		capacity = size_arr;
		size = 0;
		for (int i=0; i<size_arr; i++){
			data[i] = 0;
		}
	}

	stack_arr::~stack_arr(){
		delete [] data;
	}

	void stack_arr::_double_capacity(){
		int *new_arr = new int[capacity*2];
		for (int i=0; i<size; i++) {
			new_arr[i] = data[i];
		}
		delete [] data;
		data = new_arr;
		capacity = capacity * 2;
	}

	void stack_arr::push(int val) {
		if (size == capacity){
			_double_capacity();
		}
		data[size] = val;
		size++;
	}

	void stack_arr::pop() {
		data[size] = 0;
		size--;
	}

	void stack_arr::peek() {
		if (&data[0] == NULL) {
			cout << "stack is empty" << endl;
		} else {
			cout << "Value at top of the stack = " << data[size-1] << endl;
		}
		
	}

	void stack_arr::_print_stack(int idx) {
		if (idx == -1) {
			return;
		} else {
			cout << data[idx] << " ";
			_print_stack(idx-1);
		}
	}

	void stack_arr::display_all() {

		if (size == 0) {
			cout << "stack is empty" << endl;
		} else {
			_print_stack(size-1);
		}
	}
