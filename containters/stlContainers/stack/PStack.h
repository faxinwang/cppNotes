#ifndef PStack_h
#define PStack_h

template<class T>
class PStack{
	private:
		int counter;
		struct Link{
			T* data;
			Link* next;
			Link(T* dat,Link* nxt):data(dat),next(nxt){}
		}*head;
	public:
		PStack():counter(0),head(0){}
		void push(T* dat){
			head = new  Link(dat,head);
			++counter;
		}
		void pop(){
			Link *tmp = head;
			head = head->next;
			delete tmp->data;
			delete tmp;
			--counter;
		}
		const T* peek()const{
			return head?head->data:0;
		}
		int getSize(){return counter;}
		~PStack(){
			while(counter){
				pop();
			}
		}
};

#endif
