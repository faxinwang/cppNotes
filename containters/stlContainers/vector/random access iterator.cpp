/*
	the following example demonstrates the special abilities of random access 
	iterator.This example won't work with lists,sets and maps because all
	operations that are marked with NOTE: are provieded only for random access
	iterator.
*/
#include<vector>
#include<iostream>
using namespace std;

int main(){
	typedef vector<int> IntVector;
	IntVector vector;
	//insert element from -3 to 9
	for(int i=-3;i<=9;++i){
		vector.push_back(i);
	}
	
	cout<<"number/distance:"<<vector.end()-vector.begin()<<endl;
	//print all elements
	//note:uses operator< instead of  operator!=
	IntVector::iterator pos;
	for(pos=vector.begin();pos < vector.end();++pos){
		cout << *pos <<' ';
	}
	cout<<endl;
	//print all elements
	//note:uses operator[] instead of operator*
	for(int i=0;i<vector.size();++i){
		cout << vector.begin()[i]<<' ';
	}
	cout<<endl;
	
	//print every second element
	//note:the condition here is pos!=end()-1
	for(pos=vector.begin();pos < vector.end()-1;pos+=2){
		cout << *pos<<' ';
	}
	cout << endl;
	
	
	return 0;
}
