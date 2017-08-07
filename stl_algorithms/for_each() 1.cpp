#include"algostuff.hpp"
using namespace std;

/*
	UnaryProc
	for_each(InputIter beg,InputIter end,UnaryProc op)
	* colls op(elem) for each element in the range [beg,end)
	* returns a copy of the(internally modified) op
*/

//function called for each element
void print(int elem){
	cout<<elem<<' ';
}

int main(){
	vector<int> coll;
	INSERT_ELEMENTS(coll,1,9);
	
	//call print for each element
	for_each(coll.begin(),coll.end(),print);
	cout<<endl;
	
	return 0;
}
