operation			effect
set c				creates an empty set/multiset	without any elements
set c(op)			creates an set/mset that uses op as the sorting criterion
set c1(c2)			creates a copy of another set/mset of the same type
set c(beg,end)		creates a set/mset initialized by the elements of the range[beg,end)
set c(bed,end,op)	creates a set/mset with the sorting criterion op initialized
					by the elements of the range [beg,end)
c.~set()			destroys all elements and frees the memory

set<T>				a set that sorts with less<>( operator < )
set<T,op>			a set that sorts with op
multiset<T>			a mset that sorts with less<>( operator < )
multiset<T,op>		a mset that sorts with op

count(elem)			returns the number of elements with value elem
find(elem)			returns the position of the first element with value elem or end()
lower_bound(elem)	returns the first position where elem would get inserted(the first element >=elem)
upper_bound(elem)	returns the last position where elem would get inserted(the first element >elem)
equal_range(elem)	returns the first and last position where elem would get inserted(the range of elements==elem)

c.insert(elem)		inserts a copy of elem and rturns the position of the new element
					and for set,whether it succeeded
c.insert(pos,elem)	inserts a copy of elem and returns the position of the new element(
					pos is used as a hint pointing to where the insert should start the search)
c.insert(beg,end)	inserts a copy of all elements of the range[beg,end) returns nothing

c.erase(elem)		removes all elements with value elem and returns the number of removed elements
c.erase(pos)		removes the element at pos returns nothing
c.erase(beg,end)	removes all elements of the range [beg,end) returns nothing


