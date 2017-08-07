#include"algostuff.hpp"
using namespace std;

/*
	difference_type
	count(InputIter beg, InputIter end, const T& value)
	
	difference_type
	count(InputIter beg, InputIter end, UnaryPredicate op)
*/

bool isEven(int elem){
	return elem%2==0;
}


int main(){
	vector<int> coll;
	int num;
	INSERT_ELEMENTS(coll,1,9);
	PRINT_ELEMENTS(coll,"coll: ");
	
	//count and print elements with value 4
	num = count(coll.begin(),coll.end(),4);
	cout<<"number of elements equal to 4: "<<num<<endl;
	
	//count element with even value
	num = count_if(coll.begin(),coll.end(),isEven);
	cout<<"number of elements with even value: "<<num<<endl;
	
	//count elements that are greater than value 4
	num=count_if(coll.begin(),coll.end(),
				bind2nd(greater<int>(),4));
	cout<<"number of elements greater than 4: "<<num<<endl;
	
	return 0;
} 
