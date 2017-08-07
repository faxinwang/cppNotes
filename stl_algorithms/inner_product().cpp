#include"algostuff.hpp"
using namespace std;
/*
Computing the inner product of two sequence
	T
	inner_product(InputIter beg1, InputIter end1,
				  InputIter beg2, T initValue)
	T
	inner_product(InputIter beg1, InputIter end1,
				  InputIter beg2, T initValue,
				  BinaryFunc op1, BinaryFunc op2)
	
	* The first form computes and returns the inner product of initValue and all
	  elements in the range [beg,end) combined with the elements in the second
	  range,it calls
	  	initValue = initValue + elem1*elem2
	  for all corresponding elements
	* The second form computes and returns the result of calling op for initValue
	  and all elements in the first range combined with the elements in the second
	  range, it calls
	  	initValue = op1(initValue,op2(elem1,elem2))
	  for all corresponding elements
	* Thus,for the values:
		a1 a2 a3
		b1 b2 b3
	  they compute and return either
	  	initValue + (a1*b1) + (a2*b2) + (a3*b3)
	  or
	  	initValue op1 (a1 op2 a2) op1 (a2 op2 a2) op1 (a3 op2 a3)
*/
int main(){
	list<int> coll;
	INSERT_ELEMENTS(coll,1,6);
	PRINT_ELEMENTS(coll);
	
	//process sum of all products
	//0 + 1*1 + 2*2 + 3*3 + ... + 6*6
	cout<<"inner product: "
		<<inner_product(coll.begin(),coll.end(),//first range
						coll.begin(),			//second range
						0)						//initial Value
		<<endl;
	
	//process sum of 
	//0 + 1*6 + 2*5 + 3*4 + 4*3 + 5*2 + 6*1
	cout<<"inner reverse product: "
		<<inner_product(coll.begin(),coll.end(),
						coll.rbegin(),0)
		<<endl;
	//process product of all sum
	//1* 1+1 * 2+2 * 3+3 * 4+4 * 5+5 * 6+6
	cout<<"product of sums: "
		<<inner_product(coll.begin(),coll.end(),
						coll.begin(),1,
						multiplies<int>(),
						plus<int>())
		<<endl;
		
	return 0;
}
