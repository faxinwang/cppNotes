#include<iostream>
#include<valarray>
using namespace std;

//print valarray
template<class T>
void printValarray(const valarray<T>& va){
	for(int i=0;i<va.size();++i)
		cout<<va[i]<<' ';
	cout<<endl;
}

int main(){
	//define two valarrays with ten elements
	valarray<double> va1(10),va2(10);
	
	//assign values 0.0,1.1 up to 9.9 to the first valarray
	for(int i=0;i<10;++i){
		va1[i]=i*1.1;
	}
	//assign -1 to all elements of the second valarray
	va2=-1;
	
	//print poth valarrays
	printValarray(va1);
	printValarray(va2);
	
	//print min,max,and sum of the first valarray
	cout<<"min(): "<<va1.min()<<endl;
	cout<<"max(): "<<va1.max()<<endl;
	cout<<"sum(): "<<va1.sum()<<endl;
	
	//assign values of the va1 to va2
	va2=va1;
	
	//remove all elements of the first valarray
	va1.resize(0);
	
	//print both valarrays again
	printValarray(va1);
	printValarray(va2);
	
	return 0;
}
