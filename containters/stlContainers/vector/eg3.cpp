#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>
#include"../../udga/Print_coll.h"
#define HH puts("")
using namespace std;


int main(){
	int a[]={1,2,3,4,5,6,7,8,9,10};
	//create an empty vector
	vector<int> v1;
	//create a vector with range [1,10)
	vector<int> v2(a,a+sizeof(a)/sizeof(int));
	
	Print_coll(v1,"v1:");
	Print_coll(v2,"v2:");
	HH;
	//show technical data
	cout << "v1.size():" << v1.size() << endl;
	cout << "v1.capacity():" << v1.capacity() << endl;
	cout << "v2.size():" << v2.size() << endl;
	cout << "v2.capacity():" <<v2.capacity() << endl;
	HH;
	//assign [1,5) to v1
	v1.assign(a,a+4);
	//append 5 to v1;
	v1.push_back(5);
	Print_coll(v1,"v1:");
	cout << "v1.capacity():" << v1.capacity() << endl;
	HH;
	//v2.capacity() will double(from 10 to 20)
	v2.push_back(11);
	cout << "v2.size():" << v2.size()<<endl;
	cout << "v2.capacity():" << v2.capacity()<<endl;
	HH;
	vector<int> vv;
	cout<< "vv.size():"<<vv.size()<<endl;
	cout<< "vv.capacity():"<<vv.capacity()<<endl;
	HH;
	vv.swap(v2);
	cout<<"after vv.swap(v2):"<<endl;
	cout<< "vv.size():"<<vv.size()<<endl;
	cout<< "vv.capacity():"<<vv.capacity()<<endl;
	cout<< "v2.size():"<<v2.size()<<endl;
	cout<< "v2.capacity():"<<v2.capacity()<<endl;
	HH;
	//v3.capacity()=v1.size()
	vector<int> v3(v1);
	cout << "after vector<int> v3(v1):"<<endl;
	cout << "v3.size():" << v3.size() << endl;
	cout << "v3.capacity():" << v3.capacity() << endl;
	//this is a good away to shrink the capacity of a vector.
	v1.swap(v3);
	cout<<"after v1.swap(v3):"<<endl;
	cout<<"v1.size():"<<v1.size()<<endl;
	cout<<"v1.capacity():"<<v1.capacity()<<endl;
	cout<<"v3.size():"<<v3.size()<<endl;
	cout<<"v3.capacity():"<<v3.capacity()<<endl;
	HH;
	
	return 0;
}
