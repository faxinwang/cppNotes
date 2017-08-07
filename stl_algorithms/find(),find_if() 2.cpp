#include"algostuff.hpp"
using namespace std;

int main(){
	typedef vector<int> VectInt;
	VectInt coll;
	VectInt::iterator pos;
	INSERT_ELEMENTS(coll,1,9);
	PRINT_ELEMENTS(coll,"coll: ");
	
	//find first element greater than 3
	pos = find_if(coll.begin(),coll.end(),
				bind2nd(greater<int>(),3));
	//print its position
	cout<<"the "<<distance(coll.begin(),pos)+1<<"th element is the first greater than 3"<<endl;
	
	//find first element divisible by 3
	pos = find_if(coll.begin(),coll.end(),
				not1(bind2nd(modulus<int>(),3)));
	//print its position
	cout<<"the "<<distance(coll.begin(),pos)+1<<"th element is the first divisible by 3"<<endl;
	
	
	return 0;
}
