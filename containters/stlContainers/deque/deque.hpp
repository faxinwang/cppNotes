operations			effect
deque<T> c			create an empty deque
deque<T> c(c2)		create a copy of another deque
deque<T> c(n)		create a deque with n elements created by the default constructor
deque<T> c(n,elem)	create a deque initialized with n copies of elements elem
deque<T> c(beg,end)	create a deque initialized with the range [beg,end)
c.~deque<T>			destory all element and frees the memory

c.at(inx)			returns the element with index idx(checked)
c[idx]				returns the element with index idx(unchecked)
c.front()			returns the first element(unchecked)
c.back()			returns the last element(unchecked)

c.assign(n,elem)	assign n copies of elements elem
c.assign(beg,end)	assign the elements of the range [beg,end)

c.insert(pos,elem)	insert elem at pos and returns the position of the new element
c.insert(pos,n,elem)insert n copies of elem at pos returns nothing
c.insert(pos,beg,end)insert the elements of range [beg,end) at pos returns nothing

c.push_back(elem)	appends a copy of elem at the end
c.pop_back()		remove the last element(does not return it)
c.push_front(elem)	insert a copy of elem at the beginning
c.pop_front()		remove the first element(does not return it)

c.erase(pos)		remove the element at pos and return the pos of next element
c.erase(beg,end)	remove all elements of the range [beg,end)

c.resize(num)		changes the number of elements to num(if size() grows,new 
					elements are created by the default constructor)
c.resize(num,elem)	changes the number of elements to num(if size() grows,new
					elements are copies of the elem)
					
deque operations differ from vector operatoins only as follows:
	1.Deque do not provide the function for capacity() and reserve().
	2.Deque do provide direct functions to insert and to delete the first element
	  push_front(),pop_front().
	3.No member functions for elements access (except at()) check whether an index
	  or an iterator is valid.
	4.An insertion or deletion of elements might cause a reallocation.Thus,any 
	  insertion or deletion invalidations all pointer,references,and iterators that
	  refer to other elements of the deque.The exception is when elements are 
	  inserted or the front or the back.In this case,references and pointers to 
	  elements stay valid but iterators don't. 
