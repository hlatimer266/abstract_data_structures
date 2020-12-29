#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <list> 
#include <iterator>
#include "hash_table.hpp"

using namespace std;

hash_table::hash_table(int size_map){
	size = size_map;
	table = new list<int>[size];
}

hash_table::~hash_table() {
	delete [] table;
}

int hash_table::hash_key(int x){
	return (x % size);
}

void hash_table::insert_item(int x){
	int index = hash_key(x);
	table[index].push_back(x);
}

void hash_table::delete_item(int key){
	int index = hash_key(key);

	list <int> :: iterator i;
	for (i = table[index].begin();
		i != table[index].end(); i++){
		if (*i == key){
			break;
		}
	}

	if (i != table[index].end()){
		table[index].erase(i);
	}
}

void hash_table::display_all(){
	for( int i=0; i<size; i++){
		cout << i;
		for( auto x : table[i]){
			cout << " --> " << x;
		}
		cout << endl;
	}
}