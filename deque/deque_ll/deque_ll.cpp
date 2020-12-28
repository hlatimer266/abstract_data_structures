#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "deque_ll.hpp"

using namespace std;

	// constructor
	deque_ll::deque_ll(){
		// initialize empty linked list
		head = NULL;
		tail = NULL;
	}

	// destructor
	deque_ll::~deque_ll(){
			node *tmp;
			while(head != tail){
				tmp = head;
				head = head->next;
				delete(tmp);
			}
			delete head;
	}

	// insert node and make new head of the list
	void deque_ll::insert_head(int val){
	
		node *tmp = new node;
		tmp->data = val;
		tmp->next = NULL;

		if(head == NULL){
			head = tmp;
			tail = tmp;
			tail->next = head;
		}
		else {
			tmp->next = head; // new node points to old head of list 
			head = tmp; // new node is now head of list
			tail->next = head; // point tail to new head of list
		}

	}

	// insert node and make new tail of the list
	void deque_ll::insert_tail(int val){
		// initalize new node to be inserted
		node *tmp = new node;
		tmp->data = val;
		tmp->next = NULL;

		if(head == NULL){
			head = tmp;
			tail = tmp;
			tail->next = head; 
		}
		else {
			tmp->next = tail->next; // point new node to head of list
			tail->next = tmp; // point old tail to new tail
			tail = tmp; // set global tail to new tail node
		}

	}

	void deque_ll::delete_head(){
		node *tmp;
		tmp = head;
		head = tmp->next;
		tail->next = head;
		delete(tmp);
	}

	void deque_ll::delete_tail(){
		node *itr, *tmp;
		itr = head;
		while(itr->next != tail){
			itr = itr->next;
		}
		tmp = itr->next;
		tail = itr;
		tail->next = head;
		delete(tmp);
	}
	
	// get head
	node* deque_ll::get_head(){
		return head;
	}

	// get tail
	node* deque_ll::get_tail(){
		return tail;
	}
	
	// recursively get size of list
	int deque_ll::get_count(node* head) {
		if(head == tail) {
			return 1;
		}
		else{
			return 1 + get_count(head->next); 
		}
	}

	// find occurences of data value in list
 	int deque_ll::find_value_count(int val, node* n) {
		
		if(n == tail) {
			if (n->data == val) {
				return 1;
			}
			return 0;
		}
		else {
			if (n->data == val){
				return 1 + find_value_count(val, n->next);
			}
			else {

				return 0 + find_value_count(val, n->next);
			}
		}

	}

	// display all contents in the list
	void deque_ll::display_all(node* n) {

		if (n == tail){
			cout << n->data << endl;
		} 
		else {
			cout << n->data << endl;
			display_all(n->next);
		}
	}



