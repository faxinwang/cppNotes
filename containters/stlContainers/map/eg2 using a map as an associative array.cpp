/*
	the following example shows the use of a map as an associative array.The map
	is used as a stock chart.The elements of the map are pairs in which key is 
	the name of the stock and the value is its price.
*/

#include<iostream>
#include<map>
#include<string>
#include"../../udga/Print_coll.hpp"
using namespace std;
typedef map<string,float> StrFloatMap;

int main(){
	//coll:map
	//key:string
	//value:float
	StrFloatMap stocks;
	
	//insert some elements
	stocks["BASF"]=369.50;
	stocks["VW"]=413.50;
	stocks["Daimler"]=819.00;
	stocks["BMW"]=834.00;
	stocks["Siemens"]=842.20;
	Print_acoll(stocks,"after initialized:");
	
	//all prices doubled
	StrFloatMap::iterator pos;
	for(pos=stocks.begin();pos!=stocks.end();++pos){
		pos->second *= 2;
	}
	Print_acoll(stocks,"after prices doubled:");
	
	//remoe key from "VW" to "Volkswagen"
	//only provided by exchengeing elemen
	stocks["Volkswagen"] = stocks["VW"];
	stocks.erase("VW");
	Print_acoll(stocks,"after element changed:");
	
	return 0;
}
