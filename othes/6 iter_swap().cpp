/*
	swaping iterator values using iter_swap()
	note:this program normally does not work if you use a vector as a container.
	this is because ++begin() and --end() yield temporary pointer
*/

#include<iostream>
#include<list>
#include<algorithm>
#include"../udga/Print_coll.hpp"
using namespace std;

int main(){
	typedef list<int> IntList;
	IntList list;
	//insert elements from 1 to 9
	for(int i=1;i<=9;++i){
		list.push_back(i);
	}
	Print_coll(list);
	
	//swap first and second value
	iter_swap(list.begin(),++list.begin());
	Print_coll(list);
	
	//swap first and last value
	iter_swap(list.begin(),--list.end());
	Print_coll(list);
	
	
	return 0;
}
