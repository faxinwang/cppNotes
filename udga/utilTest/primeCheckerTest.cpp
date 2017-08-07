#include<iostream> 
#include"../util/primeChecker.hpp"
using namespace std;


int main(){
	primeChecker<int> pc;
	int counter=0;
	for(int i=2;i<=100;++i)
		if(pc.isPrime(i))
			cout<<i<<(++counter%6==0?"\n":" ");
	
	for(int i=100000000;i<=100000100;++i)
		if(pc.isPrime(i))
			cout<<i<<(++counter%10==0?"\n":"");
	
	
	
	
	return 0;
}
