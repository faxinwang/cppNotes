/*  顺序表类的实现和定义  */
//定义两个异常类 

#ifndef Vector_h
#define Vector_h

#include"../myColl/Coll.hpp"
#include"../myExp/Exp.hpp"


template<class T>
class Vector:public Coll<T>{
	private:
		T* data;
		int maxSize;
		int counter;
	private:
		void doubleSpace();
	public:
		Vector(int sz=10);
		~Vector(){delete[]data;}
		void clear(){counter=0;}
		int size()const{return counter;}
		int capacity()const{return maxSize;}
		void insert(int pos,const T& elem);
		void push_back(const T& elem);
		void remove(int i);
		int find(const T& x)const;
		T& at(int pos)const;
		T& operator[](int i){return data[i];}
		bool empty()const{return (bool)counter;}
};

template<class T>
void Vector<T>::doubleSpace(){
	maxSize *= 2;
	T* tmp = new T[2*maxSize];
	for(int i=0;i<counter;++i){
		tmp[i]=data[i];
	}
	delete[] data;
	data=tmp;
}
template<class T>
Vector<T>::Vector(int sz):maxSize(sz),counter(0){
	if(sz<=0) throw IllegaSize();
	data=new T[maxSize];
}
template<class T>
void Vector<T>::insert(int pos,const T& elem){
	int i;
	if(pos<=0) throw OutOfBound();
	if(counter==maxSize) doubleSpace();
	for(i=counter;i>=pos;--i){
		data[i]=data[i-1];
	}
	data[i]=elem;
	++counter;
}
template<class T>
void Vector<T>::push_back(const T& elem){
	if(counter==maxSize) doubleSpace();
	data[counter++]=elem;
} 
template<class T>
void Vector<T>::remove(int pos){
	if(pos<0 || pos>=counter)
		throw OutOfBound();
	for(int i=pos;i<counter-1;++i){
		data[i]=data[i+1]; 
	}
	--counter;
} 
template<class T>
int Vector<T>::find(const T& x)const{
	int i;
	for(i=0;i<counter && data[i]!=x;++i);
	return i==counter?-1:i;
}
template<class T>
T& Vector<T>::at(int pos)const{
	if(pos<0||pos>=counter)
		throw OutOfBound();
	return data[pos]; 
}


#endif
