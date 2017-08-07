/*
	the thrid kind of predefined iterator adapters are reverse iterators.Reverse
	iterators operate in reverse.They switch the call of an increament operator
	internally into a call of the decreament operator.and vice versa.All containers
	can create reverse iterators via their memnber function rbegin() and rend().
	Consider the following example:
*/

#include<iostream>
#include<vector> 
#include<algorithm>
#include<iterator>
using namespace std;

int main(){
	vector<int> vector1;
	//insert elements from 1 to 9
	for(int i=1;i<=9;++i){
		vector1.push_back(i);
	}
	//print all elements in reverse order by call rbegin() and rend()
	copy(vector1.rbegin(),vector1.rend(),		//source
		ostream_iterator<int>(cout," "));	//destination
	cout<<endl;
	return 0;
}
