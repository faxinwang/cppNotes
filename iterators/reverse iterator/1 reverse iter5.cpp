/*
	you can convert a rpos back to pos using base()
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
	//find position of element with value 5
	IntList::iterator pos;
	pos=find(list.begin(),list.end(),3);
	//print value of the element
	cout << "pos: "<<*pos<<endl;
	
	//convert iterator to reverse iterator
	IntList::reverse_iterator rpos(pos);
	cout<<"rpos: "<<*rpos<<endl;
	
	//convert iterator back to normal iterator
	IntList::iterator rrpos=rpos.base();
	cout<<"rrpos: "<<*rrpos<<endl;
	
	return 0;
}
