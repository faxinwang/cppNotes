#include<iostream>
using namespace std;

/*

enum{
	skipws	//跳过输入中的空白，用于输入
	left	//左对齐输出
	right 	//右对齐输出
	internal//在符号位和基指示符后填入字符。用于输出
	dec		//十进制输出
	oct		//八进制输出
	hex		//十六进制输出
	showbase//显示基指示符,用于输入或输出
	showpoint//显示小数点,用于输出
	showpos	 //正整数前显示'+' 号，用于输出
	scientific //用科学计数法显示浮点数,用于输出
	fixed	//用定点形式显示浮点数
	unitbuf	//在输出操作后立即刷新输出流
	stdio	//在输出操作后刷新stdout stderr，用于输出 
};		

设置状态标志:setf(ios::状态标识1|ios::状态标识2|...); 
清除状态标识符:unsetf(ios::状态标志); 
*/

int main2(){
	cout<<"cout.width()="<<cout.width()<<endl;
	cout<<"cout.fill()="<<cout.fill()<<endl;
	cout<<"cout.precision()="<<cout.precision()<<endl;
	cout<<123<<"	"<<123.456<<endl;
	cout<<"----------------------------------\n"; 
	cout.width(10);
	cout.precision(3);
	cout.fill('*');
	cout<<123<<"	"<<123.4567<<endl;
	cout<<"width()="<<cout.width()<<endl;
	cout<<"precision()="<<cout.precision()<<endl;
	cout<<"---------------------------------------\n";
	cout.width(10);
	cout.fill('#');
	cout<<123<<"	"<<123.456789<<endl;
	cout.setf(ios::right|ios::showpos);
	cout<<123<<"	"<<123.456789<<endl;
	
	return 0;
}


