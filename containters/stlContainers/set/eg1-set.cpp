/*
	the following example shows how to insert elements into a set and 
	use iterators to print them.
*/

#include<iostream>
#include<set>
using namespace std;

int main(){
	typedef set<int> IntSet;
	IntSet coll;
	
	/* insert elements from 1 to 6 in arbitrary order
	*  value 1 gets inserted twice;	
	*/
	coll.insert(3);
	coll.insert(1);
	coll.insert(5);
	coll.insert(4);
	coll.insert(1);
	coll.insert(6);
	coll.insert(2);
	
	//print all elements
	IntSet::const_iterator pos;
	for(pos=coll.begin();pos!=coll.end();++pos)
		cout << *pos <<' ';
	cout << endl;
	
	return 0;
} 
