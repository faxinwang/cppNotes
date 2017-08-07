/*
	algorithms use auxiliary functions in several variants--some optional,some
	mandatory.In particual.you can use them to specify a search criterion,or to 
	define a manipulation while transferring elements from one collection to 
	another.Here is another example:
*/

#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include"../udga/Print_coll.hpp"
using namespace std;

int square(int n){
	return n*n;
}

int main(){
	set<int> set1;
	vector<int> vector1;
	
	//insert elements from 1 to 9 into set1
	for(int i=1;i<=9;++i){
		set1.insert(i);
	}
	Print_coll(set1,"initialized in set1:");
	
	//transform each elements from set1 to vector1
	//square transform value
	transform(set1.begin(),set1.end(),	//source range
			back_inserter(vector1),		//destination
			square);					//operation
	Print_coll(vector1,"squared into vecter1:");
	
	return 0;
}
