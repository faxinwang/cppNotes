/*
	the simplest example is the for_each() algorithm.It calls a user-defined
	function for each elements of the specified range.
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//function that print the passed argument
inline void print(int elem){
	cout<< elem <<' ';
}


int main(){
	vector<int> vector1;
	//insert elements from 1 to 9
	for(int i=1;i<=9;++i){
		vector1.push_back(i);
	}
	//print all elements
	for_each(vector1.begin(),vector1.end(),	//range
			print);							//operation (do not need parentheses)
	cout<<endl;
	
	return 0;
}
