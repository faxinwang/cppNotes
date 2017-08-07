//Delete pointers in an STL sequence container.
#ifndef Purge_ptr_hpp
#define Perge_prt_hpp

#include<algorithm>

template<class Seq>
void purge_ptr(Seq& c){
	//此处typename是必须的，因为Seq是一个模板参数，而iteraotr是嵌套在Seq中的
	//某种东西,需要用typename关键字来告诉编译器遇到的是一个类型 
	typename Seq::iterator it;
	for(it=c.begin();it!=c.end();++it){
		delete *it;
		*it=0;
	}
}

//Iteraotr version
template<class Iter>
void purge_ptr(Iter beg,Iter end){
	for(;beg!=end;++beg){
		delete *beg;
		*beg=0;
	}
}


#endif
