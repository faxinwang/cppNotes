/*
	processing iterator distance using distance()
*/

#include<iostream>
#include<list>
#include<algorithm>
using namespace std;

int main(){
	typedef list<int> IntList;
	IntList list;
	//insert element from -3 to 9
	for(int i=-3;i<=9;++i){
		list.push_back(i);
	}
	//search element with value 5
	IntList::iterator pos;
	pos=find(list.begin(),list.end(),5);
	if(pos!=list.end()){
		//process and print difference from the begining
		cout<<"difference between begining and 5:"
			<<distance(list.begin(),pos)<<endl;
	}else{
		cout<<"5 not found"<<endl;
	}
	
	return 0;
}
