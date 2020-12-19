#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "array_of_ll.hpp"

using namespace std;
	
	// constructor 
	array_of_ll::array_of_ll(int size){
		arr_of_ll = new linked_list[size];
		size_array = size; // set member class variable size		

		for (int i=0; i<size; i++) {
			arr_of_ll[i] = linked_list();
		}			
	}

	// desctructor
	array_of_ll::~array_of_ll(){delete [] arr_of_ll;}

	// getter for size
	int array_of_ll::get_size(){return size_array;}

	// increase size of array of linked list
	void array_of_ll::increase_size(int size) {
		
		linked_list *new_arr = new linked_list[size_array+size];

		for (int i=0; i<size_array; i++) {
			node* curr_node = arr_of_ll[i].get_head();
			while (curr_node != NULL) {
				new_arr[i].add_tail(curr_node->data);
				curr_node = curr_node->next;
			}
		}

		delete [] arr_of_ll;
		arr_of_ll = new_arr;
		
		size_array += size;
	}

	void array_of_ll::display_all() {
		for(int i=0; i<size_array; i++){
			arr_of_ll[i].display_all();
		}
	}
