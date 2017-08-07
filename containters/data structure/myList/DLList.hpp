
#ifndef DLList_h
#define DLList_h

#include"../myColl/Coll.hpp"
#include"../myExp/myExp.hpp"

/*双链表的实现*/
template<class T>
class DLList:public Coll<T>{
	private:
		struct Node{
			T data;
			Node *prev,*next;
			Node():prev(0),next(0){}
			Node(const T& x,Node* pre=0,Node* nxt=0):data(x),prev(pre),next(nxt){}
		};
		Node *head,*tail;
		int counter;
	private:
		Node* moveTo(int pos)const;
	public:
		DLList();
		~DLList(){clear();delete head;delete tail;}
		void clear();
		int size()const{return counter;}
		void remove(int pos);
		int find(const T& x)const;
		const T& at(int pos)const;
		void push_back(const T& elem);
		void push_front(const T& elem);
		void insert(int pos,const T& x);
		bool empty()const;
		int capacity()const{return -1;}
		
}; 



template<class T>
typename DLList<T>::Node* DLList<T>::moveTo(int n)const{
	Node* p = head;
	if(n<=0||n>counter) throw OutOfBound();
	while(n--)
		p=p->next;
	return p;
}

template<class T>
DLList<T>::DLList():counter(0){
	head=new Node;
	tail=new Node;
	head->next=tail;
	tail->prev=head;
}

template<class T>
bool DLList<T>::empty()const{
	return !counter;
}
template<class T>
void DLList<T>::clear(){
	Node *p=head->next;
	Node *q;
	head->next=tail;
	tail->prev=head;
	while(p!=tail){
		q=p->next;
		delete p;
		p=q; 
	}
	counter=0;
}
template<class T>
void DLList<T>::insert(int n,const T& elem){
	Node *pos,*tmp;
	pos=moveTo(n);
	tmp=new Node(elem,pos->prev,pos);//将elem放到n的前面一个位置 
	pos->prev->next=tmp;
	pos->prev=tmp;
	++counter;
}
template<class T>
void DLList<T>::remove(int n){
	Node *pos;
	pos=moveTo(n);
	pos->prev->next=pos->next;
	pos->next->prev=pos->prev;
	delete pos;
	--counter;
}

template<class T>
int DLList<T>::find(const T& x)const{
	Node *p=head->next;
	int i=0;
	while(p!=tail && p->data != x){
		p=p->next;
		++i;
	}
	return p==tail?-1:i;
}
template<class T>
const T& DLList<T>::at(int n)const{
	Node*p=moveTo(n);
	return p->data;
}
template<class T>
void DLList<T>::push_back(const T& elem){
	Node *tmp=new Node(elem,tail->prev,tail);
	tail->prev->next=tmp;
	tail->prev=tmp;
	++counter;
}
template<class T>
void DLList<T>::push_front(const T& elem){
	Node *tmp=new Node(elem,head,head->next);
	head->next->prev=tmp;
	head->next=tmp;
	++counter;
}


#endif
