/*
	the following example of iterators are insert iterators,or inserters.
	inserters are used to let algorithms operate in insert mode rather than 
	in overwrite mode.Inparticular,they solve the problem of algorithms that
	write to a destination that does not have enough room:They let the destination
	grow accrodingly.
	Consider the following example£º
*/

#include<iostream> 
#include<vector>
#include<list>
#include<deque>
#include<set>
#include<algorithm>
#define HH puts("")
using namespace std;


int main(){
	list<int> list1;
	//insert elements from 1 to 9 into list1
	for(int i=1;i<=9;++i)
		list1.push_back(i);
		
	//copy elements of list1 to vector1 by appending them
	vector<int> vector1;
	copy(list1.begin(),list1.end(),//source
		back_inserter(vector1));	//destinaion
	
	//copy elements of list1 to deque1 by inserting them at the front
	//-reverse the order of the elements
	deque<int> deque1;
	copy(list1.begin(),list1.end(),//source
		front_inserter(deque1));//destination
	
	//copy elements of list1 to set1
	//only inserter that works for association collections
	set<int> set1;
	copy(list1.begin(),list1.end(),//source
		inserter(set1,set1.begin()));//destination
	
	//print vector1
	for(int i=0;i<vector1.size();++i)
		cout<<vector1[i]<<' ';
	HH;
	//print deque1
	for(int i=0;i<deque1.size();++i)
		cout<<deque1[i]<<' ';
	HH;
	//print set1
	set<int>::iterator it;
	for(it=set1.begin();it!=set1.end();++it)
		cout<<*it<<' ';
	HH;
	
	return 0;
} 

/*
	back_inserter(container)	appends in the same order by using push_back()
	front_inserter(container)	inserts at the front in reverse order by using 
								push_front()
	inserter(container,pos)		inserts at the pos in the same order by using 
								insert()
*/
