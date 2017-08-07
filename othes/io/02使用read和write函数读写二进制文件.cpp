#include<fstream>
#include<string.h>
#include<iostream>
using namespace std;

//istream& read(unsigned char* buf,int num)
//ostream& write(const unsigned char *buf,int num)


int main2(){
	ofstream fout("test.txt");
	if(!fout){
		cout<<"打开文件写失败!"; 
		return 1;
	}
	int a=123,b=0;
	char str[]="向文件写入双精度数和字符串!",str2[50]; 
	fout.write((char*)&a,sizeof(double));
	fout.write(str,strlen(str));
	fout.close();
	
	ifstream fin("test.txt");
	if(!fin){
		cout<<"打开文件读失败"; 
		return 1;
	}
	fin.read((char*)&b,sizeof(double));
	fin.read(str,26);
	cout<<b<<"	"<<str2<<endl;
	fin.close();
	return 0;
}
