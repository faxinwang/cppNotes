/*
	the following example shows how to insert elements into a multiset and 
	use iterators to print them.
*/

#include<iostream>
#include<set>
using namespace std;

int main(){
	typedef multiset<int> IntMSet;
	IntMSet coll;
	
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
	IntMSet::const_iterator pos;
	for(pos=coll.begin();pos!=coll.end();++pos)
		cout << *pos <<' ';
	cout << endl;
	//the output would be :1 1 2 3 4 5 6
	
	return 0;
} 
