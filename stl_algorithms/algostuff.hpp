#ifndef ALGOSTUFF_HPP
#define ALGOSTUFF_HPP

#include<iostream>
#include<vector>
#include<deque>
#include<list>
#include<set>
#include<map>
#include<iterator>
#include<string>
#include<algorithm>
#include<functional>
#include<numeric>
#include<limits>

/*prints optional C-string hint followed by
 *-all elements of collection coll
 *-separated by spaces
 */
template<class T>
inline void PRINT_ELEMENTS(const T& coll,const char* hint=" "){
	typename T::const_iterator pos;
	std::cout<<hint;
	for(pos=coll.begin();pos!=coll.end();++pos)
		std::cout<<*pos<<' ';
	std::cout<<std::endl;
}

/*fill values from first to last into the collection
 *Note:NO half-open range
 */
template<class T>
inline void INSERT_ELEMENTS(T& coll,int first,int last){
	for(int i=first;i<=last;++i)
		coll.insert(coll.end(),i);
}

#endif
