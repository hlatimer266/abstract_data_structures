#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "deque_arr.hpp"

using namespace std;

	// constructor
	deque_arr::deque_arr(int size_arr){
		data = new int[size_arr];
		capacity = size_arr;
		size = 0;
		for (int i=0; i<size_arr; i++){data[i] = 0;}
	}

	// destructor
	deque_arr::~deque_arr(){
			delete [] data;
	}

	void deque_arr::_double_capacity(){
		int *new_arr = new int[capacity*2];
		for (int i=0; i<size; i++) {new_arr[i] = data[i];}
		delete [] data;
		data = new_arr;
		capacity = capacity * 2;
	}


	// insert node and make new head of the list
	void deque_arr::insert_front(int val){
		if (size == capacity){
			_double_capacity();
		}
		for(int i=size-1; i != -1;i--) {
			data[i+1] = data[i];
		}
		data[0] = val;
		size++;
	}

	void deque_arr::insert_back(int val){
		if (size == capacity){
			_double_capacity();
		}
		data[size] = val;
		size++;

	}

	void deque_arr::delete_front(){
		for(int i=0; i<size; i++){
			data[i] = data[i+1];
		}
		size--;
	}

	void deque_arr::delete_back(){
		data[size-1]=0;
		size--;
	}
	
	// get head
	int deque_arr::get_front(){
		return data[0];
	}

	// get tail
	int deque_arr::get_back(){
		return data[size-1];
	}
	
	// recursively get size of list
	int deque_arr::get_count() {
		return size;
	}

	// find occurences of data value in list
 	int deque_arr::find_value_count(int val, int idx) {
		
		if(idx == size-1) {
			if (data[idx] == val) {
				return 1;
			}
			return 0;
		}
		else {
			if (data[idx] == val){
				return 1 + find_value_count(val, idx+1);
			}
			else {

				return 0 + find_value_count(val, idx+1);
			}
		}

	}

	// display all contents in the list
	void deque_arr::display_all(int idx) {

		if (idx == size-1){
			cout << data[idx] << endl;
		} 
		else {
			cout << data[idx] << endl;
			display_all(idx+1);
		}
	}



