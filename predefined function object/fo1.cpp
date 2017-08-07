/*
	by using special function adapters you can combine predefined function objects
	with other ualues or use special cases.
	Here is a complete example:
*/ 

#include<iostream>
#include<set>
#include<deque>
#include<algorithm>
#include<functional>
#include"../udga/Print_coll.hpp"
using namespace std;

int main(){
	set<int,greater<int> >  set1;
	deque<int> deque1;
	
	//insert elements from 1 to 9
	for(int i=1;i<=9;++i){
		set1.insert(i);
	}
	Print_coll(set1,"initialized: ");
	
	//transform all elements into deque1 by multiplying 10
	transform(set1.begin(),set1.end(),		//range
			back_inserter(deque1),			//destination
			bind2nd(multiplies<int>(),10)	//operation
			);
	Print_coll(deque1,"transformed: ");
	
	//replace value equal to 70 with 42
	replace_if(deque1.begin(),deque1.end(),		//range
				bind2nd(equal_to<int>(),70),	//replace criterion
				42);							//new value
	Print_coll(deque1,"replaced: ");
	
	//remove all elements with values less than 50
	deque1.erase(remove_if(deque1.begin(),deque1.end(),	//range
							bind2nd(less<int>(),50)),	//remove criterion
				deque1.end()
				);
	Print_coll(deque1,"removed: ");
	return 0;
}
