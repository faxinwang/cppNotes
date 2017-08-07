/*
	another very helpful kind of iterator adapters is a stream iterator.Stream
	iterators are iterators that read from and write to a stream.Thus,they provide
	an abstraction that lets the input from the keyboard behave as a collection,
	from which you can read.Similar you can redirect the output of an algorithm
	directly into a file or onto the screen.
	Consider the following example,it's a typical example of the power of the
	whole STL.Compared with ordinary C or C++,it does a lot of complex processing
	by using only a few statemens£º 
*/
#include<iostream> 
#include<vector>
#include<string>
#include<algorithm>
#include<iterator>
using namespace std;

int main(){
	vector<string> vector1;
	
	/* read all word from the standard input
	   source:all strings unitl end-of-file(or error)
	   destination:vector1
	*/
	copy(istream_iterator<string>(cin),	//start of source
		 istream_iterator<string>(),	//end of source
		 back_inserter(vector1));		//destination
	
	//sort elements
	sort(vector1.begin(),vector1.end());
	
	/* print all elements without duplicates
	   source:vector1
	   destination:standard output(with new line between elements)
	*/
	unique_copy(vector1.begin(),vector1.end(),			//source
				ostream_iterator<string>(cout,"\n"));	//destination
	
	return 0;
}
