#ifndef TimeOfDay_H
#define TimeOfDay_H

#include<iostream>
#include<iomanip>

template<int base>//数制为base的数 
class Number{
	int n;//存放当前数值 
	public:
		Number(int i=0):n(i){}// i必须小于base 
		int advance(int k);//当前值增加k个单位 
		int getValue(){return n;}
};
template<int base>
int Number<base>::advance(int k){
	int s=0;
	n+=k;
	while(n>=base){
		n -= base;
		++s;
	}
	
	return s;
}

class TimeOfDay{
		Number<24> hours;//小时（0-23） 
		Number<60> minutes;
		Number<60> seconds;
		Number<1000> milliseconds;//毫秒（0 - 999） 
	public:
		TimeOfDay(int h=0,int m=0,int s=0,int mi=0):hours(h),
			minutes(m),seconds(s),milliseconds(mi){}
		void advanceMillis(int k){
			advanceSecond(milliseconds.advance(k));
		}
		void advanceSecond(int k){
			advanceMinute(seconds.advance(k));
		}
		void advanceMinute(int k){
			advanceHour(minutes.advance(k));
		}
		void advanceHour(int k){
			hours.advance(k);
		}
		//安"时:分:秒.毫秒" 的格式显示时间 
		void show(){ 
			using namespace std;
			char ch=cout.fill('0');//获取当前填充字符 
			cout<<setw(2)<<hours.getValue()<<":"
				<<setw(2)<<minutes.getValue()<<":"
				<<setw(2)<<seconds.getValue()<<"."
				<<setw(3)<<milliseconds.getValue()<<endl;
			cout.fill(ch);//还原填充字符 
		}
};
#endif
