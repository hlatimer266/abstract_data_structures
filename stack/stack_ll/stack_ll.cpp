#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "stack_ll.hpp"

using namespace std;

	stack_ll::stack_ll(){
		head = NULL;
	}

	stack_ll::~stack_ll(){
		node *tmp;
		while (head != NULL){
			tmp = head;
			head = head->next;
			delete(tmp);
		}
		delete(head);
	}

	void stack_ll::push(int val) {
		node *tmp = new node;
		tmp->data = val;
		tmp->next = NULL;
		if (head == NULL) {
			head = tmp;
		} else {
			tmp->next = head;
			head = tmp;
		}
	}

	void stack_ll::pop() {
		node *tmp;
		if (head == NULL){
			cout << "stack is empty" << endl; 
		} else {
			tmp = head;
			head = tmp->next;
			delete(tmp);
		}
	}

	void stack_ll::peek() {
		if (head == NULL) {
			cout << "stack is empty" << endl;
		} else {
			cout << "Value at top of the stack = " << head->data << endl;
		}
		
	}

	void _print_stack(node* n) {
		if (n == NULL) {
			return;
		} else {
			cout << n->data << " ";
			_print_stack(n->next);
		}
	}

	void stack_ll::display_all() {

		if (head == NULL) {
			cout << "stack is empty" << endl;
		} else {
			_print_stack(head);
		}
	}
