/*
	The following example in particular shows the use of the special number
	functions for list
*/
#include<iostream>
#include<list>
#include<iterator>
#include<algorithm>
using namespace std;

void printLists(const list<int>& l1,const list<int>& l2)
{
	cout<<"list1: ";
	copy(l1.begin(),l1.end(),ostream_iterator<int>(cout," "));
	cout<<endl<<"list2: ";
	copy(l2.begin(),l2.end(),ostream_iterator<int>(cout," "));
	cout<<endl<<endl;;
}

int main(){
	list<int> list1,list2;
	
	//fill both list with elements
	for(int i=0;i<6;++i){
		list1.push_back(i);
		list2.push_front(i);
	}
	printLists(list1,list2);
	
	//moves all elements of list1 to list2 before the pos of first element with value 3
	//find() returns an iterator to the first element with value 3
	list2.splice(find(list2.begin(),list2.end(),3),	//destination
				list1);								//source
	printLists(list1,list2);
	
	//move first element to the end
	list2.splice(list2.end(),	//destination
				 list2,			//source list
				 list2.begin());//source position
	printLists(list1,list2);
	
	//sort list2,assign to list1 and remove duplicates
	list2.sort();
	list1=list2;
	list2.unique();
	printLists(list1,list2);
	
	//merge both sorted list into list1
	list1.merge(list2);
	printLists(list1,list2);
	
	//reverse list2;
	list2=list1;
	list2.reverse();
	printLists(list1,list2);
	
	return 0;
} 
