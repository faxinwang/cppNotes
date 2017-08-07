#ifndef isPrime_h
#define isPrime_h

#include<cmath>
#include<cstdlib>
#include<ctime>
/*
	有这样两个判断素数的定理： 
	1.如果p是素数，并且0<x<p，那么 pow(x,p-1) % p == 1 恒成立.
	2.如果p是素数，并且0<x<p，那么 pow(x,2) % p == 1 恒成立的唯一可能
		的根是 x=1 和 x=p-1. 
	如果 p 没有通过上面两个定理，并不一定能证明P不是素数，如果x是随机选择的，
	任然有1/4的概率会误将合数判为素数，但如果能对不同的x多做几次测试，比如随机选择
	5 个 x ,则失误的概率仅为pow(0.25,5)，已经可以忽略。 
*/

template<class Num>
class  primeChecker{
	private:
		const int Trials;
	private:
		bool check(int x,int i,Num p);
	public:
		primeChecker(int trial=5):Trials(trial){}
		bool isPrime(Num p);
};

//判断p是否满足上面两个定理 
template<class Num>
bool primeChecker<Num>::check(int a,int i,Num p){
	if(i==0) return 1;
	int x =check(a,i/2,p);
	if(x==0) return 0;
	
	int y=(x*x)%p;
	if(y==1 && x!=1 && x!=p-1) return 0;
	if(i%2) y=(a*y)%p;
	return y;
}

template<class Num>
bool primeChecker<Num>::isPrime(Num n){
	srand(time(0));
	for(int i=0;i<Trials;++i)
		if(check(rand()%(n-1)+1,n-1,n)!=1)
			return false;
	return true;//五次都满足,则可确定n为素数 
}


#endif 
