/*
	the following examples defines a vector for integer values,inserts six 
	elements and prints the elements of the vector
*/ 

#include<iostream>
#include<vector>
using namespace std;

int main(){
	vector<int> coll;
	
	//append elements with values 1 to 6
	for(int i=0;i<=6;++i){
		coll.push_back(i);
	}
	
	//print all elements followed by a space
	for(int i=0;i<=6;++i){
		cout << coll[i] << " ";
	}
	cout<<endl;
	
	return 0;
}
