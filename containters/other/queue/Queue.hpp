#ifndef Queue_hpp
#define Queue_hpp

#include<deque>
#include<exception>

template<class T>
class Queue{
	protected:
		std::deque<T> c;
	public:
		/* exception class for pop() and top() with empty queue */
		class ReadEmptyQueue{
			public:
				virtual const char* what()const throw(){
					return "read empty queue";
				}
		};
		typename std::deque<T>::size_type size()const{
			return c.size();
		}
		bool empty()const{
			return c.empty();
		}
		void push(const T& elem){
			c.push_back(elem);
		}
		//read element from the queue and return its value
		T pop(){
			if(c.empty()){
				throw ReadEmptyQueue();
			}
			T elem(c.front());
			c.pop_front();
			return elem;
		}
		//return value of next element
		T& front(){
			if(c.empty()){
				throw ReadEmptyQueue();
			}
			return c.front();
		}
};




#endif
