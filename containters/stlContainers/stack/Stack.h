#ifndef STACK_H
#define STACK_H

template<class T>
class Stack{
	private:
		int counter;
		
		struct Link{
			T data;
			Link* next;
			Link(T data,Link* next):data(data),next(next){}
		}*head;
	
	public:
		Stack():head(0),counter(0){}
		~Stack(){
			while(head){
				pop();
			}
		}
		void push(T& dat){
			head = new Link(dat,head);
			++counter;
		}
		int size(){
			return counter;
		}
		const T& peek()const{
		//	return head?head->data:0;	//如果返回指针就可以这样写 
			return head->data;
		}
		void pop(){
			if(head==0)
				return ;
			Link* temp = head;
			head=head->next;
			delete temp;
			--counter;
		}
};

#endif
