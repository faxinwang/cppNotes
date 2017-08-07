#ifndef LinkStack_h
#define LinkStack_h

#include"../myColl/Coll.hpp"
#include"../myExp/Exp.hpp"

template<class T>
class LinkQueue:public Coll<T>{
	private:
		struct Node{
			T data;
			Node *next;
			Node(const T& dat):data(dat),next(0){}
		}*front,*rear;
		int counter;
	public:
		LinkQueue():front(0),rear(0),counter(0){}
		~LinkQueue();
		int size()const{return counter;}
		int capacity()const{return -1;}
		bool empty()const{return !counter;}
		
		void enQueue(const T& x);
		T deQueue();
};
template<class T>
void LinkQueue<T>::enQueue(const T& x){
	if(rear==0){
		front=rear=new Node(x);
	}else{
		rear->next=new Node(x);
		rear=rear->next;
	}
	++counter;
}
template<class T>
T LinkQueue<T>::deQueue(){
	if(counter){
		Node* tmp=front;
		T dat=front->data;
		front=front->next;
		delete tmp;
		--counter;
		return dat;
	}else{
		throw CollectionIsEmpty();
	}
}

template<class T>
LinkQueue<T>::~LinkQueue(){
	Node* tmp;
	while(front!=0){
		tmp=front;
		front=front->next;
		delete tmp;
	}
}


#endif 
