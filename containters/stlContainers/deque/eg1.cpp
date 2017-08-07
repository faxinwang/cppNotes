/*
	the following example declares a deque for float-point values,inserts elemens 
	from 1.1 to 6.6 at the front of the container ,and prints all elements of the 
	deque
*/

#include<iostream>
#include<deque>
using namespace std;


int main(){
	deque<float> coll;
	
	//insert elements from 1.1 to 6.6 each at the front
	for(int i=1;i<=6;++i){
		coll.push_front(i*1.1);
	}
	
	//print all elements followed by a space
	for(int i=0;i<coll.size();++i){
		cout << coll[i] << ' ';
	}
	cout << endl;
	
	return 0;
}
