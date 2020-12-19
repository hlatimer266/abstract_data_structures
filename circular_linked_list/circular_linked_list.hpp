#ifndef CIRCULAR_LINKED_LIST_HPP
#define CIRCULAR_LINKED_LIST_HPP

#include <iostream>

using namespace std;

struct node {
	int data;
	struct node* next;
};

class circular_linked_list{
	private:
		node *head, *tail;		
	public:
		circular_linked_list(); // constructor
		~circular_linked_list(); // destructor
		void insert(int val, node* after); // insert node
		void insert_head(int val); // insert new head value
		void insert_tail(int val); // insert new tail value
		int count(node* head); // size of list
		node* find_node(int val, node* n); // find node by value
		int find_value_count(int val, node* n); // find number of occurance of value
		void delete_node(node* to_delete); // delete node
		void display_all(node* n); // display all nodes
		node* get_head(); // return head of list
		node* get_tail(); // return tail of list
};
#endif
