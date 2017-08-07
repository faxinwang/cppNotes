#ifndef seqQueue_h
#define seqQueue_h

#include"../myColl/Coll.hpp"
#include"../myExp/Exp.hpp"
template<class T>
class seqQueue:public Coll<T>{
	private:
		T *data;
		int front,rear;
		int maxSize,counter;
	public:
		seqQueue(int size=50):maxSize(size),counter(0),front(0),rear(0){
			data=new T[maxSize];
		}
		~seqQueue(){
			delete[] data;
		} 
		int size()const{return counter;}
		int capacity()const{return maxSize;}
		bool empty()const{return !counter;}
		void enQueue(const T& x);
		T& deQueue();
		
};
template<class T>
void seqQueue<T>::enQueue(const T& x){
	if(counter<maxSize){
		data[rear]=x;
		rear=(rear+1)%maxSize;	//rear指向最后一个元素的后一个位置 
		++counter;
	}else{
		throw CollectionIsFull();
	}
}

template<class T>
T& seqQueue<T>::deQueue(){
	if(counter){
		T &tmp = data[front];
		front=(front+1)%maxSize;//front指向第一个元素的位置 
		--counter;
		return tmp;
	}else{
		throw CollectionIsEmpty();
	}
}





#endif 
