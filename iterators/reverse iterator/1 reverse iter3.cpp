/*
	you can convert normal iterator to reverse iterators.normally ,the iterators
	must be the bidirectional itertors,but note that the logical position of an 
	iterator is moved during the coversion.consider the following example:
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	typedef vector<int> IntVector;
	IntVector vector;
	//insert elements from 1 to 9
	for(int i=1;i<=9;++i){
		vector.push_back(i);
	}
	//find position of element with value 5
	IntVector::iterator pos;
	pos=find(vector.begin(),vector.end(),3);
	//print value to which iterator refers
	cout<<"pos:"<<*pos<<endl;
	//convert iterator to reverse iterator rpos
	IntVector::reverse_iterator rpos1(pos);
	//print value to which reverse iterator rpos refers
	cout<<"rpos1:"<<*rpos1<<endl<<endl;
	
	pos=find(vector.begin(),vector.end(),1);
	//print value to which iterator refers
	cout<<"pos:"<<*pos<<endl;
	//convert iterator to reverse iterator rpos
	IntVector::reverse_iterator rpos2(pos);
	//print value to which reverse iterator rpos refers
	cout<<"rpos2:"<<*rpos2<<endl;
	
	return 0;
}
