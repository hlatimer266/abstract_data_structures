#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "array_of_ll.hpp"
using namespace std;

int main() {

	cout << "initalize array of linked list to size=2" << endl;
	array_of_ll array_ll = array_of_ll(2);

	cout << "add 1 and 2 to head. linked_list at index 0 = ";
	array_ll.arr_of_ll[0].add_head(1);
	array_ll.arr_of_ll[0].add_head(2);
	array_ll.arr_of_ll[0].display_all();

	cout << "add 5 to head and 10 to tail. linked_list at index 1 = ";
	array_ll.arr_of_ll[1].add_head(5);
	array_ll.arr_of_ll[1].add_tail(10);
	array_ll.arr_of_ll[1].display_all();
	cout << "" << endl;

	cout << "increase array of linked list to size=3" << endl;
	array_ll.increase_size(1);

	array_ll.arr_of_ll[2].add_head(3467);
	array_ll.arr_of_ll[2].add_tail(7);

	cout << "linked_list at index 0 = ";
	array_ll.arr_of_ll[0].display_all();
	cout << "linked_list at index 1 = ";
	array_ll.arr_of_ll[1].display_all();
	cout << "linked_list at index 2 = ";
	array_ll.arr_of_ll[2].display_all();

	cout << "" << endl;
	cout << "empty linked list at index=2 and try and call display_all" << endl;
	array_ll.arr_of_ll[2].reset_ll();
	array_ll.arr_of_ll[2].display_all();

	cout << "show all contents of array" << endl;
	array_ll.display_all();
	
	return 0;

}
