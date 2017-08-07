/*
	For multiset,the same program looks a bit differently and produces
	different result
*/

#include<iostream>
#include<set>
#include"../../udga/Print_coll.hpp"
using namespace std;
typedef multiset<int,greater<int> > IntMset;


int main(){
	//coll:mset
	//elemType:int
	//order:descend
	IntMset mset1;
	
	//insert elements in random order
	mset1.insert(4);
	mset1.insert(3);
	mset1.insert(5);
	mset1.insert(1);
	mset1.insert(6);
	mset1.insert(2);
	mset1.insert(5);
	
	//print mset1
	Print_coll(mset1,"mset1: ");
	
	//insert 4 again and process return value
	IntMset::iterator pos = mset1.insert(4);
	cout << "4 inserted as element "<< distance(mset1.begin(),pos) + 1
		 << endl;
	//assign elements to another multiset with ascending order
	multiset<int> mset2(mset1.begin(),mset1.end());
	
	//print mset2
	Print_coll(mset2,"mset2: ");
	
	//remove all elements up to element with value 3
	mset2.erase(mset2.begin(),mset2.find(3));
	Print_coll(mset2,"after erase(mset2.begin(),mset2.find(3)): ");
	
	//remove elements with value 5
	cout << mset2.erase(5) << " element(s) removed" << endl;
	Print_coll(mset2,"mset2 after erase(5): ");
	
	
	return 0;
}
