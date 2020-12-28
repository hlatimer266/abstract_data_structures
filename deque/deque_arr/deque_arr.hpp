#ifndef DEQUE_ARR_HPP
#define DEQUE_ARR_HPP

#include <iostream>

using namespace std;


class deque_arr{
	private:
		int *data;
		int size;
		int capacity;
		void _print_stack(int idx);
		void _double_capacity();
	public:
		deque_arr(int size_arr); 
		~deque_arr();
		void insert_front(int val);
		void insert_back(int val);
		void delete_front();
		void delete_back();
		int get_front(); // return head of list
		int get_back(); // return tail of list
		int get_count();
		int find_value_count(int val, int idx);
		void display_all(int idx); // display all nodes
};
#endif
