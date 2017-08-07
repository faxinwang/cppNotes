#include<iostream>
#include<vector>
#include<algorithm>
#include"../../udga/Print_coll.hpp"
using namespace std;

int main(){
	vector<int> v1;
	
	if(v1.size()>5){		//OK
		cout<<v1[5]<<endl;
	}
	if(!v1.empty()){		//OK
		cout<<v1.front()<<endl;
		cout<<v1.back()<<endl;
	}
//	cout<<v1.at(5)<<endl;	//throws out_of_range exception
	
	for(int i=0;i<15;++i){
		v1.push_back(i%5+1);
	}
	Print_coll(v1,"v1:\n");
	//the way to remove all elements with value 5;
	v1.erase(remove(v1.begin(),v1.end(),5),
			v1.end());
	Print_coll(v1,"after remove all elements with value 5:\n");
	
	//the way to remove the first element with value 3
	vector<int>::iterator pos;
	pos = find(v1.begin(),v1.end(),3);
	if(pos != v1.end()){
		v1.erase(pos);
	}
	Print_coll(v1,"after remove the first element with value 3:\n");
	
	return 0;
}
