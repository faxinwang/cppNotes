#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<ctype.h>
#include<iomanip>
using namespace std;
/*
	例1：
	从外存文件中读入一片正文，统计其中26个英文字母出现得次数，
	分别考虑区分大小写和 不区分大小写的情况
	---用两个长度为26的向量upper和lower分别统计大，小写的字母个数，
	不区分大小写的结果为upper+lower. 
*/

const int line = 5;
int main(){
	vector<int> upper(26,0),lower(26,0),temp(26,0);
	ofstream ofile;
	ofile.open("test.txt");
	char str[80];
	for(int i=1;i<=line;i++){
		cout<<"输入第"<<i<<"行:" ;
		cin.getline(str,80);
		ofile<<str;
	}
	ofile.close();
	
	ifstream ifile("test.txt");
	char c;
	while((c=ifile.get())!=EOF) {
		if(islower(c)) lower[c-'a']++;
		if(isupper(c)) upper[c-'A']++;
	}
	ifile.close();
	
	for(char ch='A';ch<='Z';ch++) cout<<"  "<<ch; cout<<endl;
	for(int i=0;i<26;i++) cout<<setw(3)<<upper[i]; cout<<endl;
	puts("");
	
	for(char ch='a';ch<='z';ch++) cout<<"  "<<ch; cout<<endl;
	for(int i=0;i<26;i++) cout<<setw(3)<<lower[i]; cout<<endl;
	puts("");

	for(char ch='A';ch<='Z';ch++) cout<<ch<<char(ch+32)<<" "; cout<<endl;
	for(int i=0;i<26;i++) cout<<setw(3)<<lower[i]+upper[i]; cout<<endl;
	puts("**************** 1 *****************************************");
	
	return 0;
}
