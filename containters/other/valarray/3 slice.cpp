#include<iostream>
#include<valarray>
using namespace std;

//print valarray line-by-line
template<class T>
void printValarray(const valarray<T>& va,int num){
	for(int i=0;i<va.size()/num;++i){
		for(int j=0;j<num;++j){
			cout<<va[i*num+j]<<' ';
		}
		cout<<endl;
	}
	cout<<endl;
}

int main(){
	// valarray with 12 elements four rows three columns
	valarray<double> va(12);
	for(int i=0;i<12;++i){
		va[i]=i;
	}
	printValarray(va,3);
	
	//first columu = second column raised to the third column
	va[slice(0,4,3)]=pow(valarray<double>(va[slice(1,4,3)]),
						 valarray<double>(va[slice(2,4,3)]));
	printValarray(va,3);
	
	//create valarray with three times the thrid elements of va
	valarray<double> vb(va[slice(2,4,0)]);
	//multiply the third column by the elements of vb
	va[slice(2,4,3)] *= vb;
	printValarray(va,3);
	
	//print the square root of the elements in the second row
//	printValarray( sqrt( valarray<double>(va[slice(3,3,1)]) ), 3);
	
	//double the elements in the third row
	va[slice(2,4,3)] = valarray<double>(va[slice(2,4,3)])*2.0;
	printValarray(va,3);
	
	return 0;
}
