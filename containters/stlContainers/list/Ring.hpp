#ifndef Ring_h
#define Ring_h

#include<iterator>
#include<list>



template<class T>
class Ring:public std::list<T>{
	std::list<T> lst;
	public:
		//declaration necessary so the following 'friend' statment
		//sees this 'iterator' instead of std::iterator
		class iterator;
		friend class iterator; 
		class iterator:public std::iterator<std::bidirectional_iterator_tag,T,ptrdiff_t>
		{
				typedef typename std::list<T>::iterator It;
				It it;
				std::list<T> *ring;
			public:
				iterator(){}
				iterator(std::list<T> &lst,It it):ring(&lst),it(it){}
				bool operator==(const iterator& x)const{
					return it==x.it;
				}
				bool operator!=(const iterator& x)const{
					return !(*this==x);
				}
				typename std::list<T>::reference operator*()const{
					return *it;
				}
				iterator& operator++(){
					++it;
					if(it==ring->end())
						it=ring->begin();
					return *this;
				}
				//postfix
				iterator& operator++(int){
					iterator tmp=*this;
					++*this;
					return tmp;
				}
				iterator& operator--(){
					if(it==ring->begin())
						it=ring->end();
					--it;
					return *this;
				}
				//postfix
				iterator& operator--(int){
					iterator tmp=*this;
					--*this;
					return tmp;
				}
				iterator insert(const T& x){
					return iterator(*ring,ring->insert(it,x));
				}
				iterator erase(){
					return iterator(*ring,ring->erase(it));
				}
		};
		void push_back(const T& x){ lst.push_back(x); }
		iterator begin(){ return iterator(lst,lst.begin()); }
		int size(){ return lst.size(); }
};
/*
	可以看出，绝大多数编码都是针对迭代器进行的。这个Ring iterator必须知道
	如何循环到其实短点，所以它必须持有一个指向作为其"双亲"Ring对象的引用，
	从而知道什么时候该从一端跳到另一端。
	需要注意的是，为Ring设置德接口相当有限，特别是，这里没有end()函数，因为
	一个环仅仅保存进行循环的状态。这就意味着不能在任何需要以end()为参数的任何
	STL算法中使用Ring。 
*/

#endif
