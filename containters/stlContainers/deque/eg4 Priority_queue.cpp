#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<iterator>
#include<queue>
using namespace std;

//a more compact version of priority_queue
template<class T>
class Priority_queue:public priority_queue<T>{
	private:
		vector<T> v;
	public:
		const vector<T>& getVector(bool reversed=false){
			v.assign(this->c.begin(),this->c.end());
			//c is already a heap
			sort_heap(v.begin(),v.end(),this->comp);
			//put it into priority_queue order
			if(!reversed)
				reverse(v.begin(),v.end());
			return v;
		}
};

int main(){
	Priority_queue<int> pq;
	srand(time(0));
	for(int i=0;i<25;++i)
		pq.push(rand()%50);
	const vector<int>& v=pq.getVector(true);
	copy(v.begin(),v.end(),ostream_iterator<int>(cout," "));
	cout<<"\n----------------------------------"<<endl;
	while(!pq.empty()){
		cout<<pq.top()<<' ';
		pq.pop();
	}
	return 0;
}
