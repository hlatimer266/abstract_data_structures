#include <iostream>
#include <stdlib.h>
#include "Bst.hpp"

int main(){
	Bst new_bst = Bst();
	int values_to_insert[8] = {8,6,5,15,11,16,10,14};
	for(int i=0; i<8; i++) {
		new_bst.insert(values_to_insert[i]);
	}
	
	bool found = new_bst.contains(10, new_bst.get_root());
	cout << "Is 10 in the bst? " << found << endl;
	bool not_found = new_bst.contains(99, new_bst.get_root());
	cout << "Is 99 in the bst? " << not_found << endl;

	new_bst.delete_leaf(15);
	new_bst.display_all(new_bst.get_root());
	return 0;
}
