#ifndef HASH_TABLE_HPP
#define HASH_TABLE_HPP
#include <list> 

using namespace std;

class hash_table{
	private:
		int size;
		list<int> *table;
	public:
		hash_table(int size_map);
		~hash_table();
		void insert_item(int x);
		void delete_item(int key);
		int hash_key(int x);
		void display_all();
}; 
#endif
