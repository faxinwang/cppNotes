#include<cstdlib> 
#include<ctime>
#include<iostream>
#include<iterator>
#include<list>
#include<queue>
using namespace std;

class Customer{
	int serviceTime;
	public:
		Customer():serviceTime(0){}
		Customer(int tm):serviceTime(tm){}
		int getTime(){return serviceTime;}
		void setTime(int tm){serviceTime=tm;}
		friend ostream& operator<<(ostream& out,const Customer& c){
			return out<<'['<<c.serviceTime<<']';
		}
};

class Teller{
	queue<Customer>& customers;
	Customer current;
	enum {SLICE=5};
	int ttime;//time left in slice
	bool busy;//Is teller serving a customer?
	public:
		Teller(queue<Customer>& cq):customers(cq),ttime(0),busy(false){}
		Teller& operator=(const Teller& t){
			customers=t.customers;
			current=t.current;
			ttime=t.ttime;
			busy=t.busy;
			return *this;
		}
		bool isBusy(){return busy;}
		void run(bool recursion=false){
			if(!recursion) ttime=SLICE;
			int servtime=current.getTime();
			if(servtime>ttime){
				servtime-=ttime;
				current.setTime(servtime);
				busy=true;//still working on current
				return ;
			}
			if(servtime<ttime){
				ttime-=servtime;
				if(!customers.empty()){
					current=customers.front();
					customers.pop();//remove it
					busy = true;
					run(true);
				}
				return ;
			}
			if(servtime==ttime){
				//done with current,set to empty;
				current = Customer(0);
				busy = false;
				return ;//no more time in the slice
			}
		}
};
//inherit to access protected implementation
class CustomerQ:public queue<Customer>{
	public:
		friend ostream& operator<<(ostream& out,const CustomerQ& cq){
			copy(cq.c.begin(),cq.c.end(),ostream_iterator<Customer>(out,"\n"));
			return out;
		}
};


int main(){
	CustomerQ customers;
	typedef list<Teller> Tellers;
	Tellers tellers;
	typedef Tellers::iterator It;
	tellers.push_back(Teller(customers));
	srand(time(0));
	clock_t start=clock();
	//Run simulation for some second
	while(clock()<start+2*CLOCKS_PER_SEC){
		//add a random number of customers ot the queue,
		//with random service time
		for(int i=0;i<rand()%5;++i)
			customers.push(Customer(rand()%15+1));
		cout<<'{'<<tellers.size()<<'}'<<endl<<customers<<endl;
		//have the tellers service the queue
		for(It pos=tellers.begin();pos!=tellers.end();++pos)
			pos->run();
		cout<<'{'<<tellers.size()<<'}'<<customers<<endl;
		//if line is too long,add another teller
		if(customers.size()/tellers.size()>2)
			tellers.push_back(Teller(customers));
		//if line is short enough,remove a teller
		if(tellers.size()>1 && customers.size()/tellers.size()<2){
			for(It pos=tellers.begin();pos!=tellers.end();++pos)
				if(!pos->isBusy()){
					tellers.erase(pos);
					break;//out of for loop
				}
		}
	}
	
	
	
	return 0;
}
