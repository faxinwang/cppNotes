/*
	the following example shows how to use lower_bond(),upper_bond(),equal_range()
*/

#include<iostream>
#include<set>
#include"../../udga/Print_coll.hpp"
using namespace std;

int main(){
	set<int> c;
	
	c.insert(1);
	c.insert(2);
	c.insert(4);
	c.insert(5);
	c.insert(6);
	Print_coll(c,"c: ");
	
	cout << "lower_bound(3): " << *c.lower_bound(3) <<endl;
	cout << "upper_bound(3): " << *c.upper_bound(3) <<endl;
	cout << "equal_range(3): " << *c.equal_range(3).first << " "
							   << *c.equal_range(3).second <<endl;
							   
	cout << endl;
	cout << "lower_bound(5): " << *c.lower_bound(5) << endl;
	cout << "upper_bound(5): " << *c.upper_bound(5) << endl;
	cout << "equal_range(5): " << *c.equal_range(5).first << " "
							   << *c.equal_range(5).second << endl;
	
	return 0;
}
