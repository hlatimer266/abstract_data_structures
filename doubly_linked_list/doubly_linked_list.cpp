#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "doubly_linked_list.hpp"

using namespace std;

	// constructor
	doubly_linked_list::doubly_linked_list()
	{
		// initialize empty linked list
		head = NULL;
		tail = NULL;
	}

	// destructor
	doubly_linked_list::~doubly_linked_list(){
			node *tmp;
			while(head != tail){
				tmp = head;
				head = head->next;
				delete(tmp);
			}
			delete head;
		}
	
	// get head
	node* doubly_linked_list::get_head(){
		return head;
	}

	// get tail
	node* doubly_linked_list::get_tail(){
		return tail;
	}
	
	// recursively get size of list
	int doubly_linked_list::count(node* head) {
		if(head == tail) {
			return 1;
		}
		else{
			return 1 + count(head->next); 
		}
	}

	// insert node and make new head of the list
	void doubly_linked_list::insert_head(int val){
	
		node *tmp = new node;
		tmp->data = val;
		tmp->next = NULL;
		tmp->prev = NULL;

		if(head == NULL){
			head = tmp; 
			tail = tmp;
		}
		else {
			head->prev = tmp; // connect old head to new head
			tmp->next = head; // new node points to old head of list 
			head = tmp; // new node is now head of list
		}

	}

	// insert node and make new tail of the list
	void doubly_linked_list::insert_tail(int val){
		// initalize new node to be inserted
		node *tmp = new node;
		tmp->data = val;
		tmp->next = NULL;
		tmp->prev = NULL;

		if(head == NULL){
			head = tmp; 
			tail = tmp;
		}
		else {
			tail->next = tmp; // connect node at end of list
			tmp->prev = tail; // point node prev to old tale
			tail = tmp; // make tmp the new tail
		}

	}
	
	// insert node AFTER given node
	void doubly_linked_list::insert(int val, node *after) {
	
		if(after == head) {
			return insert_head(val);
		}
		else if (after == tail) {
			return insert_tail(val);
		}
		
		// allocate memory on the heap for new node
		node *tmp = new node;
		tmp->data = val;
		tmp->next = NULL;
		tmp->prev = NULL;

		if(head == NULL){
			// if this is the first node inserted, its the head and tail
			// of the list
			head = tmp; 
			tail = tmp;
		}
		else {
			
			tmp->next = after->next; // point new node to old nodes neighbor
			tmp->prev = after; // point new node prev to after node
			tmp = after->next->prev; // point after nodes old neighbor to new node
			after->next = tmp; // point old node to point to new node
		}

	}

	// find node by data value
	node* doubly_linked_list::find_node(int val, node* n) {

		// base condition: if
		if (n->data == val){
			return n;
		}
		else if (n == NULL) {
			cout << "value not found" << endl;
			return NULL; //TODO fix this garbage
		}
		else {
			return find_node(val, n->next);
		}

	}

	// find occurences of data value in list
 	int doubly_linked_list::find_value_count(int val, node* n) {
		
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
	void doubly_linked_list::display_all(node* n) {

		if (n == tail){
			cout << n->data << endl;
		} 
		else {
			cout << n->data << ", ";
			display_all(n->next);
		}
	}

	// display all contents in the list
	void doubly_linked_list::display_all_reverse(node* n) {

		if (n == head){
			cout << n->data << endl;
		} 
		else {
			cout << n->data << ", ";
			display_all_reverse(n->prev);
		}
	}


	// deletes the node AFTER n
	void doubly_linked_list::delete_node(node *n){
		node *tmp;
		if (n == head) {
			tmp = n->next;
			head = tmp;
			tmp->prev = n->prev;
		}
		else if (n == tail) {
			tmp = n->prev;
			tmp->next = n->next;
			tail = tmp;
		}
		else {
			tmp = n->prev;
			tmp->next = n->next;
			n->next->prev = tmp;
		}

		delete n;
	}

