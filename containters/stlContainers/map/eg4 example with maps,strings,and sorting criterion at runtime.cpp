/*
	Here is another example.It is for advanced programmers rather than STL 
	beginners.You can take it as an example of both the power and the snags 
	of the STL.In particular,this example demonstrates the following techniques:
		1.how to use maps
		2.how to write and ues function objects
		3.how to define a sorting criterion at runtime
		4.how to compare stirngs in a case-insensitive way
*/

#include<iostream>
#include<iomanip>
#include<map>
#include<string>
#include<algorithm>
#include"../../udga/Print_coll.hpp"
using namespace std;

/*	function object to compare strings
 *	-allows you to set the comparison criterion at runtime
 *	-allows you to compare case insensitive
 */
class RuntimeStringCmp{
	public:
		//constants for the comparison criterion
		enum cmp_mode{ normal, nocase};
	private:
		//actual comparison mode
		const cmp_mode mode;
		
		//auxiliary function to compare case insensitive
		static bool nocase_compare(char c1,char c2){
			return toupper(c1)<toupper(c2);
		}
	public:
		//initializes the function object with normal comparison 
		RuntimeStringCmp(cmp_mode m=normal):mode(m){
		}
		//the comparison
		bool operator()(const string& s1,const string& s2){
			if(mode==normal){
				return s1<s2; 
			}else{
				return lexicographical_compare(s1.begin(),s1.end(),
												s2.begin(),s2.end(),
												nocase_compare);
			}
		}
};

typedef map<string,string,RuntimeStringCmp> StrStrMap;

void fillAndPrint(StrStrMap& map){
	//fill insert elements in random order
	map["Deutschland"]="Germany";
	map["deutsch"]="German";
	map["Haken"]="snag";
	map["arbeiten"]="work";
	map["Hund"]="dog";
	map["gehen"]="go";
	map["Unternehmen"]="enterprise";
	map["unternehmen"]="undertake";
	map["gehen"]="walk";
	map["Bestatter"]="walk";
	
	//print map
	Print_acoll(map,15);
}

int main(){
	//coll:map
	//key:string
	//value:string
	StrStrMap map1;
	
	fillAndPrint(map1);
	
	//create an object for case-insensitive comparisons
	RuntimeStringCmp ignorecase(RuntimeStringCmp::nocase);
	
	//create a container with the case-insensitive comparisons criterion
	StrStrMap map2(ignorecase);
	
	fillAndPrint(map2);
	
	return 0;
}
