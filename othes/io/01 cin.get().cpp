#include <iostream>
using namespace std;
/*
	int get() 从流中抽取单个字符并返回
 	istream& get(char*,int,char) 从流中抽取字符直到终止符(默认为'\n')或抽取字符数达到第二个参数指定的个数或
	达到文件尾，将其存储在第一个参数指定的字符数组里。
	istream& get(char&) 从流中抽取单个字符并存入引用变量中。 
	istream& get(streambuf&, char)从流中取得字符存入streambuf对象，直到终止符或文件尾。 
	istream& getline(char*,int,char) 从流中抽取字符到终止符(默认为'\n'),或抽取字符数达到给定参数，或到文件尾。
	如果发现终止符，其从流中抽取终止符，但只是将其抛弃。 
*/
int main1(int argc, char *argv[]) {
	char str1[80],str2[80],ch;
	cout<<"plesse input a char: ";
	cout<<cin.get()<<endl;
	cout<<"please input a char: ";
	cin.get(ch);
	
	cout<<ch<<endl;
	
	cout<<"please input s string: ";
	for(int i=0;i<80;i++){
		cin.get(str1[i]);
		if(str1[i]=='\n'){
			str1[i]=0;
			break;
		}
	}
	cout<<str1<<endl;
	cout<<"please input a string: ";
	cin.get(str2,80);
	cout<<str2<<endl;
	cout<<"please input a string"<<endl; 
	cin.getline(str1,80);
	cin.getline(str2,80);
	cout<<"str1: "<<str1<<endl;
	cout<<"str2: "<<str2<<endl;
	
	return 0;
}
