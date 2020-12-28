#ifndef DEQUE_LL_HPP
#define DEQUE_LL_HPP

#include <iostream>

using namespace std;

struct node {
	int data;
	struct node* next;
};

class deque_ll{
	private:
		node *head, *tail;
	public:
		deque_ll(); 
		~deque_ll();
		void insert_head(int val);
		void insert_tail(int val);
		void delete_head();
		void delete_tail();
		node* get_head(); // return head of list
		node* get_tail(); // return tail of list
		int get_count(node* head);
		int find_value_count(int val, node* n);
		void display_all(node* n); // display all nodes
};
#endif
