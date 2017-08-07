/*
	the for_each() algorithm might writen like this:
*/
namespace std{
	template<class Iterator,class Operation>
	Operation for_each(Iterator pos,Iterator end,Operation op){
		while(pos!=end){	//as long as not reached the end
			op(*pos);		//call op() for actual elements
			++pos;
		}
		return op;
	}
}
/*
	for_each() uses the temporay function object op to call op(*pos) for each 
	element pos.If the third parameter is an ordinary function,it simply calls
	is with *pos as an argument.If the third argument is a function object,it 
	calls operator() for the function object op with *pos as an argument.
*/
