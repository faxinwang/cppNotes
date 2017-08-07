#include<iostream>
#include<list>
#include<algorithm>
#include"../udga/Print_coll.hpp"
using namespace std;

class AddValue{
	private:
		int theValue;	//the value to add
	public:
		AddValue(int v):theValue(v){}
		void operator()(int& elem){
			elem+=theValue;
		}
};

int main(){
	list<int> list1;
	//insert elements from 1 to 9
	for(int i=1;i<=9;++i){
		list1.push_back(i);
	}
	Print_coll(list1,"initialized: ");
	
	//add value 10 to each elements
	for_each(list1.begin(),list1.end(),	//range
			AddValue(10));				//operation
	Print_coll(list1,"after adding 10: ");
	
	//add valeu of the first element to each element
	for_each(list1.begin(),list1.end(),	//range
			AddValue(*list1.begin()));	//operation
	Print_coll(list1,"after adding first element: ");
	
	return 0;
}
