#include<iostream>
#include<list>
#include<deque>
#include<algorithm>
#include"CountedPtr.hpp"
using namespace std;

void printCountedPtr(CountedPtr<int> elem){
	cout << *elem <<' ';
}

int main(){
	//array of integers(to share in different containers)
	static int values[]={3,5,-9,1,6,4};
	
	//two different collections
	typedef CountedPtr<int> IntPtr;
	deque<IntPtr> deque;
	list<IntPtr> list;
	
	//insert shared objects into the collections
	//same order in deque
	//reverse order in list
	for(int i=0;i<sizeof(values)/sizeof(values[0]);++i){
		IntPtr ptr(new int(values[i]));
		deque.push_back(ptr);
		list.push_front(ptr);
	}
	
	//print contents of both collections
	for_each(deque.begin(),deque.end(),
			printCountedPtr);
	cout<<endl;
	for_each(list.begin(),list.end(),
			printCountedPtr);
	cout << endl<<endl;
	
	//modify values at different places
	//square third value in deque
	//negate first value in list
	//set first value to 0 in deque
	*deque[2] *= *deque[2];
	(*deque[0]) *= -1;
	(**list.begin()) = 0;
	
	//print contents of both collecitons
	for_each(deque.begin(),deque.end(),
			printCountedPtr);
	cout<< endl;
	for_each(list.begin(),list.end(),
			printCountedPtr);
	cout<< endl<<endl;
	return 0;
}
