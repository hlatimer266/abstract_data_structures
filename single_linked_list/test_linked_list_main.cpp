#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "linked_list.cpp"


using namespace std;

int main() {

	linked_list a_list;

	// insert nodes at the tail
	cout << "adding 1, 2, 2, 2, 7 to tail of the list\n" << endl;
	a_list.add_tail(1);
	a_list.add_tail(2);
	a_list.add_tail(2);
	a_list.add_tail(2);
	a_list.add_tail(7);

	// get node before the node to delete
	node* before_delete = a_list.find_node(2, a_list.get_head());
	a_list.delete_node(before_delete->next);
	cout << "delete 2 from list\n" << endl;	
	// add nodes at the head of the list
	cout << "add 10, 22 to head of the list\n" << endl;
	a_list.add_head(10);
	a_list.add_head(22);

	// find occurances of a value
	int occur = a_list.find_value_count(2, a_list.get_head());
	cout << "number of times 2 is in linear linked list = " << occur << "\n" << endl;

	// get number of nodes in linked list
	int size = a_list.count(a_list.get_head());

	cout << "size of linear linked list = " << size << "\n"<< endl;
	
	// display all contents of list
	cout << "display all contents of list:" << endl;
	a_list.display_all();

	return 0;

}
