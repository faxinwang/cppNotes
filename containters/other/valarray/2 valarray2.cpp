#include<iostream>
#include<valarray>
using namespace std;

//print valarray
template<class T>
void printValarray(const valarray<T>& va){
	for(int i=0;i<va.size();++i){
		cout<<va[i]<<' ';
	}
	cout<<endl;
}

int main(){
	//create and initialized valarray with nine elements
	valarray<double> va(9);
	for(int i=0;i<va.size();++i){
		va[i]=i*1.1;
	}
	printValarray(va);
	
	//double values in the valarray
	//here the right-value must have the same type with the elements,so you can write 2
	va*=2.0;
	printValarray(va);
	
	//create second valarray initialized by the values of the first plus 10
	valarray<double> vb(va+10.0);
	printValarray(vb);
	
	//create third valarray as a result of processing both existing valarrays
	valarray<double> vc;
	vc=sqrt(va)+vb/2.0-1.0;
	printValarray(vc);
	cout<<vc.size()<<endl;

	return 0;
}
