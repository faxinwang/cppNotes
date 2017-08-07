operation			effect
list<T> c			create an empty list
list<T> c(c2) 		create a copy of another list of the same type
list<T> c(n)		create a list of n elements that are created by default constructor
list<T> c(n,elem)	create a list initialized by n copies of elem
list<T> c(beg,end)	create a list initialized by the elements of range [beg,end)
c.~list<T>()		destory all elements and frees the memory

c.assign(n,elem)	assign n copies of the elem
c.assign(beg,end)	assign the elements of the range [beg,end)

c.insert(pos,elem)	insert a copy of elem at pos and returns the pos of the new element
c.insert(pos,n,elem)insert at pos n copies of elem(returns nothing)
c.insert(pos,beg,end)insert at pos a copy of all elements of the range [beg,end)

c.push_front(elem)	insert the copies of elem at the beginning
c.front()			returns the first element
c.pop_front()		removes the first element(does not return it)
c.push_back(elem)	appends the copies of elem at the end
c.back()			returns the last element
c.pop_back()		removes the last element(does not return it)

c.remove(val)		removes all elements with value val
c.remove_if(op)		removes all elements for which op(elem) yields true

c.erase(pos)		removes the element at pos and returns the next pos
c.erase(beg,end)	removes all elements of range[beg,end) and returns the next pos

c.resize(num)		changes the number of elements to num(if size() grows,new elements 
					are created by the default constructor)
c.resize(num,elem)	changes the number of elements to num(if size() grows,new elements
					are copies of the elem)

c.unique()			removes duplicates of consecutive elements with the same value
c.unique(op)		removes duplicates of consecutive elements for which op()yields true

c1.splice(pos,c2)	moves all elements of c2 to c1 in front of the pos
c1.splice(pos,c2,c2pos)moves the element at c2pos in c2 to c1 in front of pos
c1.splice(pos,c2,	moves all elements of range [c2beg,c2end) in c2 to c1 in front of pos
		c2beg,c2end)

c.sort()			sorts all elements with operator <
c.sort(op)			sorts all elements with op()

c1.merge(c2)		assuming both containers contain the elements sorted.moves all
					elements of c2 into c1 so that all elements are merged and still sorted
c1.merge(c2,op)		assuming both containers contain the elements sorted due to the
					sorting criterion op().moves all elements of c2 into c1 so that
					all elements are merged and still sorted according to op()

c.reverse()			reverse the order of all elements

