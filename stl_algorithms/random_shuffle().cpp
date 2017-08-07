#include"algostuff.hpp"
using namespace std;

/*
	void
	random_shuffle(RandomAccessIter beg, RandomAccessIter end)
	
	void
	random_shuffle(RandomAccessIter beg, RandomAccessIter end)
	
	* the first form shuffles the order of elements in the range [beg,end) using
	  a uniform distribution random number generator
	* the second form shuffles the order of the elements in the range [beg,end)
	  using op. op is colled with an integral value of difference_type of the 
	  iterator: op(max)
	  It should return a random number greater than or equal to zero and less than
	  max.Thus,it should not return max itself.
*/

class MyRandom{
	public:
		ptrdiff_t operator()(ptrdiff_t max){
			double tmp;
			tmp=static_cast<double>(rand())/static_cast<double>(RAND_MAX);
			return static_cast<ptrdiff_t>(tmp*max);
		}
};

int main(){
	vector<int> coll;
	
	INSERT_ELEMENTS(coll,1,9);
	PRINT_ELEMENTS(coll,"coll: ");
	
	//shuffle all elements randomly
	random_shuffle(coll.begin(),coll.end());
	PRINT_ELEMENTS(coll,"shuffled: ");
	
	//sort them again
	sort(coll.begin(),coll.end());
	PRINT_ELEMENTS(coll,"sorted: ");
	
	//shuffle all elements randomly again
	random_shuffle(coll.begin(),coll.end());
	PRINT_ELEMENTS(coll,"shuffled again: ");
	
	//sort them again
	sort(coll.begin(),coll.end());
	PRINT_ELEMENTS(coll,"sorted again: ");
	
	//shuffle elements with self-written random number generator
	//to pass an value we have to use a temporary object
	MyRandom rand;
	random_shuffle(coll.begin(),coll.end(),rand);
	PRINT_ELEMENTS(coll,"shuffled again: ");
	
	return 0;
}
