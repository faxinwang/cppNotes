#ifndef Stack_hpp
#define Stack_hpp

#include<deque>
#include<exception>

template<class T>
class Stack{
	protected:
		std::deque<T> c;
	public:
		/* exception class for pop() and top() with empty stack */
		class ReadEmptyStack:public std::exception{
			public:
				virtual const char* what()const throw(){
					return "read empty stack";
				}
		};
		//number of elements
		typename std::deque<T>::size_type size()const{
			return c.size();
		};
		//is stack empty?
		bool empty()const{
			return c.empty();
		}
		//push elements into stack
		void push(const T& elem){
			c.push_back(elem);
		}
		//pop element out of stack and return its value
		T pop(){
			if(c.empty()){
				throw ReadEmptyStack();
			}
			T elem(c.back());
			c.pop_back();
			return elem;
		}
		T& top(){
			if(c.empty()){
				throw ReadEmptyStack();
			}
			return c.back();
		}
};

#endif
