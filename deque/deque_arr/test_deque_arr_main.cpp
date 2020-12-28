#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "deque_arr.hpp"


using namespace std;

int main() {

	deque_arr a_list(5);

	cout << "adding 1, 2, 2, 2, 7 to back of the list\n" << endl;
	a_list.insert_back(1);
	a_list.insert_back(2);
	a_list.insert_back(2);
	a_list.insert_back(2);
	a_list.insert_back(7);
	a_list.display_all(0);

	a_list.delete_back();
	cout << "delete last value from the list\n" << endl;


	cout << "add 10, 22, 2 to front of the list\n" << endl;
	a_list.insert_front(10);
	a_list.insert_front(22);
	a_list.insert_front(2);

	cout << "new back (data=6)" << endl;
	a_list.insert_back(6);
	cout << "new front (data=45)" << endl;
	a_list.insert_front(45);

	cout << "display current list" << endl;
	a_list.display_all(0);

	cout << "delete back" << endl;
	a_list.delete_back();

	int occur = a_list.find_value_count(2, 0);
	cout << "number of times 2 is in linear linked list = " << occur << "\n" << endl;

	int size = a_list.get_count();
	cout << "size of linear linked list = " << size << "\n"<< endl;
	
	cout << "display all contents of list:" << endl;
	a_list.display_all(0);

	return 0;

}
