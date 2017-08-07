#include<iostream>
#include<functional>
#include<algorithm>
#include"carray.hpp"
#include"../../udga/Print_coll.hpp"
using namespace std;

int main(){
	carray<int,10> a;
	for(unsigned i=0;i<a.size();++i){
		a[i]=i+1;
	}
	a[0]=-a[0];
	Print_coll(a,"a: ");
	
	reverse(a.begin(),a.end());
	Print_coll(a,"a: ");
	
	transform(a.begin(),a.end(),	//source	
			  a.begin(),			//destination
			  negate<int>());		//operation
	Print_coll(a,"a: ");
	
	return 0;
}
