#include<iostream>
#include<bitset>
#include<string>
#include<limits>
using namespace std;
/*
Using bitset for I/O with binary representation
A useful festure of bitsets is the ability to convert values into a  sequence
of bits and vice versa.
*/

int main(){
	//print some numbers in binary representation
	cout<<"267 as binary short: "
		<< bitset<numeric_limits<unsigned short>::digits>(267)
		<<endl;
		
	cout<<"267 as binary long: "
		<<bitset<numeric_limits<unsigned long>::digits>(267)
		<<endl;
		
	cout<<"10,000,000 with 24 bit: "
		<<bitset<24>(1e7)
		<<endl;
	//transfrom binary representation into integral number
	cout<<"\"1000101011\" as number: "
		<<bitset<100>(string("1000101011")).to_ulong()<<endl;
	
	return 0;
}
