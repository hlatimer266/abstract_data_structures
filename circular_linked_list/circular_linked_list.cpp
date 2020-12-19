#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "circular_linked_list.hpp"

using namespace std;

	// constructor
	circular_linked_list::circular_linked_list()
	{
		// initialize empty linked list
		head = NULL;
		tail = NULL;
	}

	// destructor
	circular_linked_list::~circular_linked_list(){
			node *tmp;
			while(head != tail){
				tmp = head;
				head = head->next;
				delete(tmp);
			}
			delete head;
		}
	
	// get head
	node* circular_linked_list::get_head(){
		return head;
	}

	// get tail
	node* circular_linked_list::get_tail(){
		return tail;
	}
	
	// recursively get size of list
	int circular_linked_list::count(node* head) {
		if(head == tail) {
			return 1;
		}
		else{
			return 1 + count(head->next); 
		}
	}

	// insert node and make new head of the list
	void circular_linked_list::insert_head(int val){
	
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
	void circular_linked_list::insert_tail(int val){
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
	
	// insert node AFTER given node
	void circular_linked_list::insert(int val, node *after) {
	
		if(after == head) {
			return insert_head(val);
		}
		else if (after == tail) {
			return insert_tail(val);
		}

		node *tmp = new node;
		tmp->data = val;
		tmp->next = NULL;

		if(head == NULL){
			head = tmp;
			tail = tmp;
			tail->next = head;
		}
		else {
			tmp->next = after->next; // point new node to old nodes neighbor
			after->next = tmp; // point old node to point to new node
		}

	}

	// find node by data value
	node* circular_linked_list::find_node(int val, node* n) {

		if (n->data == val){
			return n;
		}
		else {
			return find_node(val, n->next);
		}

	}

	// find occurences of data value in list
 	int circular_linked_list::find_value_count(int val, node* n) {
		
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
	void circular_linked_list::display_all(node* n) {

		if (n == tail){
			cout << n->data << endl;
		} 
		else {
			cout << n->data << endl;
			display_all(n->next);
		}
	}

	// deletes the node AFTER to_delete
	void circular_linked_list::delete_node(node *to_delete){
		node *tmp;
		tmp = to_delete->next; // point to node to delete
		if (to_delete->next == head){
			to_delete->next = tmp->next; // move tails pointer to next node after head 
			head = tmp->next; // set head to node after old head of list
		}
		else if (to_delete->next == tail){
			to_delete->next = tmp->next; // point node before tail to head
			tail = to_delete; // set node before old tail as new tail
		}
		delete tmp; // delete node
		
	}
