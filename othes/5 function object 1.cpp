/*
	the usage of function object
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class PrintInt{
	public:
		void operator()(int elem)const{
			cout << elem <<' ';
		}
};

int main(){
	vector<int> vector1;
	//insert elements from 1 to 9
	for(int i=1;i<=9;++i) {
		vector1.push_back(i);
	}
	//print all elements
	for_each(vector1.begin(),vector1.end(),	//range
			PrintInt());					//operation
	cout<<endl;
	
	return 0;
}
