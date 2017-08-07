/*
	the following example shows how to increase the size of containers
*/

#include<iostream>
#include<vector>
#include<list>
#include<deque>
#include<algorithm>
using namespace std;


int main(){
	list<int> list1;
	vector<int> vector1;
	
	//insert elements from 1 to 9
	for(int i=1;i<=9;++i){
		list1.push_back(i);
	}
	//resize destination to have enough room for the overwriting algorithm
	vector1.resize(list1.size());
	
	//copy elements from frist into second collection
	//everwriting existing elements in destination
	copy(list1.begin(),list1.end(),	//source
		vector1.begin());			//destination
	//create third collection with enough room
	//initial size is passed as parameter
	deque<int> deque1(list1.size());
	
	copy(list1.begin(),list1.end(),//source
		deque1.begin());		//destination
	
	//print vector1
	cout<<"vector1: ";
	for(int i=0;i<vector1.size();++i)
		cout<<vector1[i]<<' ';
	cout<<endl;
	
	//print deque1
	cout<<"deque1: ";
	for(int i=0;i<deque1.size();++i)
		cout<<deque1[i]<<' ';
	cout<<endl;
	
	return 0;
}
