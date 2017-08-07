#ifndef linkStack_h
#define linkStack_h

#include"../myColl/Coll.hpp"
#include"../myExp/Exp.hpp"

template<class T>
class LinkStack:public Coll<T> {
	private:
		struct Node{
			T data;
			Node* next;
			Node(const T& x,Node* nxt=0):data(x),next(nxt){}
			Node():next(0){}
		}*head;
		int counter;
	public:
		LinkStack():counter(0),head(0){}
		LinkStack(const T& dat):counter(0),head(0){
			push(dat);
		}
		int size()const{return counter;}
		bool empty()const{return !counter;}
		void push(const T& dat){
			head = new Node(dat,head);
			++counter;
		}
		const T& peek(){return head->data;}
		void pop(){
			Node* tmp=head;
			head=head->next;
			delete tmp;
			--counter;
		}
		~LinkStack(){
			while(counter) pop();
		}
		int capacity()const;
};

template<class T>
int LinkStack<T>::capacity()const{
	return -1;
}





#endif 
