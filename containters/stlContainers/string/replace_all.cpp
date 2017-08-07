#include<iostream>
#include<string>
using namespace std;

/* 通过调用newString=replace_all(str,substr,newsubstr) 得到str中的substr全部被
newsubstr替换的新串，原str不被改变*/

string replace_all(string str,string substr,string newsubstr){
	string newStr(str);
	int n=substr.length();
	int pos=0;
	while((pos=newStr.find(substr,pos))!=string::npos)
		newStr.replace(pos,n,newsubstr);
	return newStr;
}



int main(){
	string str("I love you,but you love him!");
	cout<<replace_all(str,"love","LOVE")<<endl;
	
	
	return 0;
}
