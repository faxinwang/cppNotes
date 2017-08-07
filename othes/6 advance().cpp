/*
	the following example show the usage of advance()
*/
#include<iostream>
#include<list>
#include<algorithm>
using namespace std;

int main(){
	typedef list<int> IntList;
	IntList list;
	//insert elements from 1 to 9
	for(int i=1;i<=9;++i){
		list.push_back(i);
	}
	IntList::iterator pos=list.begin();
	//print actual elemens
	cout<<*pos<<endl;
	//step three elements forward
	advance(pos,3);
	//print actual element
	cout<<*pos<<endl;
	//step one element backword
	advance(pos,-1);
	//print actual element
	cout<<*pos<<endl;
	
	
	return 0;
}
