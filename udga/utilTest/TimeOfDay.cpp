#include<iostream>
#include"../util/TimeOfDay.h"

using namespace std;

int main(){
	TimeOfDay time(1,2,3,4);
	time.show();
	time.advanceHour(5);
	time.advanceSecond(122);
	time.advanceMillis(1017);
	time.show();
	time.advanceSecond(300);
	time.advanceMinute(111);
	time.advanceMillis(300);
	time.show();
	
	return 0;
}
