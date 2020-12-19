#ifndef BST_HPP
#define BST_HPP

#include <iostream>

using namespace std;

struct node {
	int data;
	struct node* left;
	struct node* right;
};

class Bst{
	private:
		node *root;
		int count;		
	public:
		Bst(); // constructor
		~Bst(); // destructor
		node* get_root(); // return head of list
		int get_count(); // return count/size of bst
		void insert(int val); // insert node
		bool contains(int val, node* node);
		void delete_leaf(int val); // delete leaf from bst
		void display_all(node* n); // display all nodes
};
#endif

