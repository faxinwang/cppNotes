#ifndef OpenHashTable_h
#define OpenHashTable_h

#include<iostream>
#define DEBUG 1

template<class T>
class OpenHashTable{
	private:
		struct Node{
			T data;
			Node *next;
			Node(const T& x,Node* nxt=0):data(x),next(nxt){}
			Node():next(0){}
		}**array;
		int size;
	private:
		static int defaultKey(const int& key){return key;}
		int (*key)(const T& x);
		int lagerPrime(int n);
	public:
		OpenHashTable(int length=101,int (*f)(const T& x) = defaultKey );
		~OpenHashTable();
		bool find(const T& x)const;
		bool insert(const T& x);
		bool remove(const T& x);
};

template<class T>
int OpenHashTable<T>::lagerPrime(int n){
	int i,j;
	for(i=n+1;;++i){
		for(j=2; i % j ; ++j);
		if( j == i) return i;
	}
}

template<class T>
OpenHashTable<T>::OpenHashTable(int length, int (*f)(const T& x) ){
	size = lagerPrime(length);
	key = f;
	array = new Node*[size];
	for(int i=0;i<size;++i)
		array[i]=new Node;
	#if DEBUG
		std::cout<<"tableSize : "<<size<<std::endl;
	#endif
}
template<class T>
OpenHashTable<T>::~OpenHashTable(){
	Node *p,*q;
	for(int i=0;i<size;++i){
		p=array[i];
		while(p){
			q=p->next;
			delete p;
			p=q;
		}
	}
	delete []array;
}

template<class T>
bool OpenHashTable<T>::find(const T& x)const{
	int pos=key(x)%size;
	Node *p=array[pos];
	while(p->next && p->next->data!=x) p=p->next;
	
	return p->next?true:false;
}
template<class T>
bool OpenHashTable<T>::insert(const T& x){
	int pos=key(x)%size;
	Node *p=array[pos]->next;
	#if DEBUG
		std::cout<<"data : "<<x<<" ,key= "<<pos;
		if( p )
			std::cout<<" carsh,key!";
		std::cout<<std::endl;
	#endif
	while(p && p->data!=x ) p=p->next;
	if(p==0){
		p = new Node(x);
		p->next = array[pos]->next;
		array[pos]->next = p;
		return true;
	}
	return false;
}

template<class T>
bool OpenHashTable<T>::remove(const T &x){
	int pos=key(x)%size;
	Node* p=array[pos],*q;
	while(p->next && p->next->data!=x)	p=p->next;
	#if DEBUG
		std::cout<<"removing "<<x<<std::endl;
	#endif
	if(p->next == 0){
		return false;//表中没有该元素 
	}else{
		q=p->next;
		p->next = q->next;
		delete q;
		return true;
	}
}

#endif

