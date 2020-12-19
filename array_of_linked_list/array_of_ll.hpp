#ifndef ARRAY_OF_LL
#define ARRAY_OF_LL

#include <iostream>
#include "linked_list.cpp"

using namespace std;

class array_of_ll {
	private:
		int size_array;
	public:
		linked_list *arr_of_ll; // pointer to array of linked_list
		array_of_ll(int size); // Contructor
		~array_of_ll(); // Destructor
		int get_size(); // Getter for size_array
		void increase_size(int size); // Increase size of array
		void display_all(); // Print all contents of each linked list
};
#endif
