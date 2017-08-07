/*
	a special kind of auxiliary function for algorithm is a predicate.Predicates 
	are functions that return a Boolean value.They are often used to specify a 
	sorting criterion.Depending on their purpose,predicates are unary or binary.
	Note that not every unary or binary function that return a Boolean value is
	a valid predicate.The STL requires that predicates always yield the same result
	for the same value.This rule out functions that modify their internal state 
	when they are called.
	
	unary predicate check a specific property of a single argument.A typical 
	example is a function that is used as a search criterion to find the first
	prime number.
*/

#include<iostream>
#include<list>
#include<algorithm>

using namespace std;

//predicate,which returns whether an integer is a prime number
bool isPrime(int num){
	//ignore negative sign
	if(num<0)
		num=-num;
	//0 and 1 are prime number
	if(num==0 || num == 1){
		return true;
	}
	//find divisor that divides without remainder
	int div;
	for(div=num/2; num%div; --div);//empty loop
	
	//if no divisor greater than 1 is found.it is a prime number
	return div==1; 
}

int main(){
	list<int> list1;
	//insert elements from 24 to 30
	for(int i=24;i<=30;++i){
		list1.push_back(i);
	}
	//search for prime number
	list<int>::iterator pos;
	pos = find_if(list1.begin(),list1.end(),	//range
					isPrime);					//predicate
	if(pos != list1.end()){
		//found
		cout<<*pos<<" is the frist prime number found"<<endl;
	}else{
		//not found
		cout<<"no prime number found"<<endl;
	}
	
	return 0;
}
