/*
	examples usage of numeric_limits
*/ 
#include<iostream>
#include<limits>	//numeric_limits
#include<string>
#include<cstdlib>
#define HH cout<<endl
using namespace std;

bool getTrue(){
	return true;
}
bool getFalse(){
	return false;
}


int main(){
	//use textual representation for bool
	cout <<boolalpha<<getFalse()<<" "<<getTrue()<<endl;
	
	//print maximum of integral types
	cout << "max(char):" << numeric_limits<char>::max() << endl;
	
	cout << "max(short): " << numeric_limits<short>::max() << endl;
	cout << "min(short): " << numeric_limits<short>::min() << endl;
	cout << "digits(short): " << numeric_limits<short>::digits << endl;
	cout << "digits(unsigned short): " << numeric_limits<unsigned short>::digits << endl;
	HH;
	cout << "max(int): " << numeric_limits<int>::max() << endl;
	cout << "min(int): " << numeric_limits<int>::min() << endl;
	cout << "digits(int): " << numeric_limits<int>::digits << endl;
	cout << "digits(unsigned int): " << numeric_limits<unsigned int>::digits << endl;
	HH;
	cout << "max(long): "<< numeric_limits<long>::max() << endl;
	cout << "min(long): "<< numeric_limits<long>::min() << endl;
	cout << "digit(long):" << numeric_limits<long>::digits << endl;
	cout << "digit(unsigned long):" << numeric_limits<unsigned long>::digits << endl;
	HH;
	cout << "max(long long): "<< numeric_limits<long long>::max() << endl;
	cout << "min(long long): "<< numeric_limits<long long>::min() << endl;
	cout << "digit(long long):" << numeric_limits<long long>::digits << endl;
	cout << "digit(unsigned long long):" << numeric_limits<unsigned long long>::digits << endl;
	HH;
		
	//print maximum of floating-point types
	cout << "max(float):" << numeric_limits<float>::max() << endl;
	cout << "min(float):" << numeric_limits<float>::min() << endl;
	cout << "digits(float):" << numeric_limits<float>::digits << endl;
//	cout << "digits(unsigned float):" << numeric_limits<unsigned float>::digits << endl; //没有unsigned float型 
	HH;
	
	cout << "max(double):" << numeric_limits<double>::max() << endl;
	cout << "min(double):" << numeric_limits<double>::min() << endl;
	cout << "digits(double):" << numeric_limits<double>::digits << endl;
//	cout << "disits(unsigned double):" << numeric_limits<unsigned double>::digits << endl;	//没有unsigned double型 
	HH;
	cout << "max(long double):" << numeric_limits<long double>::max() << endl;
	cout << "min(long double):" << numeric_limits<long double>::min() << endl;
	cout << "digits(long double):" << numeric_limits<long double>::digits << endl;
//	cout << "digits(unsigned long double):" << numeric_limits<unsigned long double>::digits << endl;
	HH;
	
	//print whether char is signed
	cout << "is_signed(char):" << numeric_limits<char>::is_signed << endl;
	HH;
	
	//print whether numeric limits for type string exist
	cout << "is_specialized(string):" << numeric_limits<string>::is_specialized << endl;
	
	system("pause");
	return 0;
}
