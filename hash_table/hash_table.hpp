#ifndef HASH_MAP_HPP
#define HASH_MAP_HPP

#include <string>

using namespace std;

struct hash_link {
	string key;
	int data;
	struct hash_link* next;
}

class hash_map{
	private:
	public:
		hash_map();
		~hash_map();
		

} 
