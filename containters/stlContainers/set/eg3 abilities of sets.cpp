/*
	the following example demonstrates some abilities of sets
*/

#include<iostream>
#include<set> 
#include"../../udga/Print_coll.h"
using namespace std;
typedef set<int,greater<int> > IntSet;

int main(){
	// coll:set
	//elemType:int
	//critertion:descending
	IntSet set1;
	
	//insert elements in random order
	set1.insert(4);
	set1.insert(3);
	set1.insert(5);
	set1.insert(1);
	set1.insert(6);
	set1.insert(2);
	set1.insert(5);//insert twice
	
	//print set1
	Print_coll(set1,"set1: ");
	
	//insert 4 again and process reture value
	pair<IntSet::iterator,bool> status = set1.insert(4);
	if(status.second){
		cout << "4 inserted in set1 as element "<< distance(set1.begin(),status.first) + 1
			 << endl;
	}else{
		cout << "4 is already exists in set1." << endl;
	}
	
	//assign elements to another set with ascending order
	set<int> set2(set1.begin(),set1.end());
	
	//print set2
	Print_coll(set2,"set2: ");
	
	//remove all elements up to element with value 3
	set2.erase(set2.begin(),set2.find(3));
	Print_coll(set2,"after erase(set2.begin(),set2.find(3)): ");
	
	//remove the elements with value 5
	int num = set2.erase(5);
	cout << num << " element(s) removed!" << endl;
	
	//print set2
	Print_coll(set2,"set2: ");
	
	return 0;
}
