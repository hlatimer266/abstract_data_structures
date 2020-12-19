#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct node
{
	int data;
	struct node *next;
};

class linked_list {
	private:
		 node *head, *tail;
	public:
		linked_list() //constructor
		{
			// initialize empty linked list
			head = NULL;
			tail = NULL;
		}

		~linked_list(){
			node *tmp;
			while(head != NULL){
				tmp = head;
				head = head->next;
				delete(tmp);
			}
			delete head;
		}
	
	node* get_head(){

		return head;
	}


	int count(node* head) {
		if(head == NULL) {
			return 0;
		}
		else{
			return 1 + count(head->next); 
		}
	}

	void add_head(int n){
	
		node *tmp = new node;
		tmp->data = n;
		tmp->next = NULL;

		if(head == NULL){
			head = tmp;
			tail = tmp;
		}
		else {
			tmp->next = head;
			head = tmp;
		}

	}


	void add_tail(int n){
		// instantiate new node, set data value and connect to tail
		node *tmp = new node;
		tmp->data = n;
		tmp->next = NULL;

		// if no node inserted yet, set first node to be the head and tail
		if(head == NULL){
			head = tmp;
			tail = tmp;
		}
		// new node inserted at the end of the list and becomes new tail
		else {
			tail->next = tmp; // point tail from null to tmp
			tail = tail->next; // make tmp the new tail
		}

	}
	
	void insert_node(int n, node *after) {
		node *tmp = new node;
		tmp->data = n;
		tmp->next = NULL;

		if(head == NULL){
			head = tmp;
			tail = tmp;
		}
		else {
			tmp->next = after->next;
			after->next = tmp;
		}

	}

	node* find_node(int val, node* start) {

		if (start->data == val){
			return start;
		}
		else {
			return find_node(val, start->next);
		}

	}

	int find_value_count(int val, node* n) {
		
		if(n == NULL) {
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

	void display_all() {
		node *tmp; //delcare tmp node to hold each node value from list
		tmp = head; //set tmp to head of list

		while (tmp != NULL) {
			cout << tmp->data << endl; //return data stored at node
			tmp = tmp->next; //go to next node in the list
		}
	}

	void delete_node(node *before_del){
		
		node *tmp;
		tmp = before_del->next;
		before_del->next = tmp->next;
		
		delete tmp;
		
	}
};
