#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "hash_table.hpp"

int main() {
    // array that contains keys to be mapped 
	int a[] = {15, 11, 27, 8, 12}; 
	int n = sizeof(a)/sizeof(a[0]); 
  
    // insert the keys into the hash table 
	hash_table h(7);   // 7 is count of buckets in 
               // hash table 
	for (int i = 0; i < n; i++)  
		h.insert_item(a[i]);   
  
    // delete 12 from hash table 
	h.delete_item(12); 
  
	// display the Hash table 
	h.display_all(); 
	return 0;
}