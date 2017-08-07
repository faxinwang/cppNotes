#include<iostream>
#include<bitset>
using namespace std;

/*
The first example of using bitset demonstrate how to use bitsets to manage a 
set of flags.
*/

int main(){
	//enumeration type for the bits
	//each bit represents a color
	enum Color{red,yellow,green,blue,white,black,pink,numColor};
	
	//create bitset for all bits/colors
	bitset<numColor> usedColors;
	
	//set bits for two colors
	usedColors.set(red);
	usedColors.set(blue);
	
	//print some bitset data
	cout<<"bitfield of used colors: "<<usedColors<<endl;
	cout<<"number of used colors: "<<usedColors.count()<<endl;
	cout<<"bitfield of unused colors: " <<~usedColors<<endl;
	
	//if any color is used
	if(usedColors.any()){
		//loop over all colors
		cout<<"colors used: ";
		for(int c=0;c<numColor;++c){
			//if the actual color is used
			if(usedColors[(Color)c]){
				string color="";
				switch(c){
				case red:color="red";break;
				case yellow: color="yellow";break;
				case green:color="green";break;
				case blue:color="blue";break;
				case white:color="white";break;
				case black:color="black";break;
				}
				cout<<color<<" ";
			}
		}
		cout<<endl;
	}
	
	return 0;
} 
