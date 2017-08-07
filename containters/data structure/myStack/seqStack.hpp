
#ifndef seqStack_h
#define seqStack_h

#include"../myColl/Coll.hpp"
#include"../myExp/Exp.hpp" 

template<class T>
class seqStack:public Coll<T>{
	private:
		T* data;
		int maxSize;
		int top;
	public:
		seqStack(int maxsz=10):maxSize(maxsz),top(0){
			data = new T[maxSize];
		}
		~seqStack(){
			delete[] data;
		}
		bool empty()const{return !top;}
		int size()const{return top;}
		int capacity(){return maxSize;}
		void push(const T& x){
			if(top+1==maxSize) doubleSpace();
			data[top++]=x;
		}
		const T& peek(){return data[top-1];}
		void pop(){--top;}
	private:
		void doubleSpace();
};

template<class T>
void seqStack<T>::doubleSpace(){
	T* tmp=new T[2*maxSize];
	for(int i=0;i<maxSize;++i){
		tmp[i]=data[i];
	}
	maxSize*=2;
	delete data;
	data=tmp;
}

#endif 
