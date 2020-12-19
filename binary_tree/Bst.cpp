#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Bst.hpp"

using namespace std;

	Bst::Bst(){
		root = NULL;
	}

	void _delete_bst(struct node* leaf) {
		if (leaf != NULL){
			_delete_bst(leaf->left);
			_delete_bst(leaf->right);
			delete(leaf);
		}
	} 

	Bst::~Bst(){
		if (root != NULL){
			_delete_bst(root);
		}
		count = 0;
	}

	node* Bst::get_root(){
		return root;
	}

	int Bst::get_count(){
		return count;
	} 

	bool compare(int val_one, int val_two) {
		return val_one <= val_two;
	}

	node* _traverse_tree_for_insert(node* curr, int val){
		if (curr == NULL) {
			node* new_node = new node;
			new_node->left = NULL;
			new_node->right = NULL;
			new_node->data = val;
			return new_node;
		} else {
			if (compare(curr->data, val)) {
				curr->right = _traverse_tree_for_insert(curr->right,val);
			} else {
				curr->left = _traverse_tree_for_insert(curr->left,val);
			}
			return curr;
		}
		
	}

	void Bst::insert(int val){
		root = _traverse_tree_for_insert(root, val);
		count++;
	}

	bool Bst::contains(int val, node* node){
		if (node == NULL){
			return false;
		} else if (node->data == val) {
			return true;
		} else if (node->data < val) {
			contains(val, node->right);
		} else if (node->data > val) {
			contains(val, node->left);
		}
	}

	bool _compare(int val_1, int val_2) {
		if (val_1 < val_2) {
			return -1;
		} else if (val_1 > val_2) {
			return 1;
		} else {
			return 0;
		}
	}

	int _leftMost(node* node) {

		if (node->left != NULL) {
			return _leftMost(node->left);
		}	
		
		return node->data;
	}

	node* _removeLeftMost(node* node) {
		if (node->left == NULL && node->right == NULL){
			delete(node);
			return NULL;
		} else if (node->left != NULL){
			node->left = _removeLeftMost(node->left);
		} else if (node->right != NULL){
			node->right = _removeLeftMost(node->right);
		}
		
		return node;
	}

	node* _impl_delete_leaf(int val, node* node) {
		if (_compare(val, node->data) == 0) {
        		if (node->right == NULL)
            			return node->left;
        		else {
            			node->data = _leftMost(node->right);
            			node->right = _removeLeftMost(node->right);
        		}
    		}
    		else if (_compare(val, node->data) < 0) {
        		node->left = _impl_delete_leaf(val, node->left);
		}
    		else {
        		node->right = _impl_delete_leaf(val, node->right);
		}

    		return node;
	}

	void Bst::delete_leaf(int val) {
		root = _impl_delete_leaf(val, root);
		count--;
		return;
	}

	void Bst::display_all(node* node) {
		if(node == NULL) return;
		display_all(node->left);
		cout << "("<< node->data << ")"<< endl;
		display_all(node->right);
	}
