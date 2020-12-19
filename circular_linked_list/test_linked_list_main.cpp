#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "circular_linked_list.hpp"


using namespace std;

int main() {

	circular_linked_list a_list;

	// insert nodes at the tail
	cout << "adding 1, 2, 2, 2, 7 to tail of the list\n" << endl;
	a_list.insert_tail(1);
	a_list.insert_tail(2);
	a_list.insert_tail(2);
	a_list.insert_tail(2);
	a_list.insert_tail(7);

	// get tail node to delete head node
	node* before_delete = a_list.get_tail();
	a_list.delete_node(before_delete);
	cout << "delete head from the list\n" << endl;
	
	// add nodes at the head of the list
	cout << "add 10, 22, 2 to head of the list\n" << endl;
	a_list.insert_head(10);
	a_list.insert_head(22);
	a_list.insert_head(2);

	// add new tail and new head nodes
	cout << "new tail (data=6)" << endl;
	a_list.insert(6, a_list.get_tail());
	cout << "new head (data=45)" << endl;
	a_list.insert(45, a_list.get_head());

	//find node before tail and delete tail
	cout << "find node before tail" << endl;
	node* before_tail = a_list.find_node(7, a_list.get_head());
	cout << "delete tail" << endl;
	a_list.delete_node(before_tail);

	// find occurances of a value
	int occur = a_list.find_value_count(2, a_list.get_head());
	cout << "number of times 2 is in linear linked list = " << occur << "\n" << endl;

	// get number of nodes in linked list
	int size = a_list.count(a_list.get_head());
	cout << "size of linear linked list = " << size << "\n"<< endl;
	
	// display all contents of list
	cout << "display all contents of list:" << endl;
	a_list.display_all(a_list.get_head());

	return 0;

}
