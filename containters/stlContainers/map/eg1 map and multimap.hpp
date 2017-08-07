operation			effect
map c				create an empty map/multimap without any elements
map c(op)			create an empty map/mmap that use op as the sorting criterion
map c1(c2)			create an copy of of another map/mmap of the same type
map c(beg,end)		create an map/mmap initialized by the range [beg,end)
map c(beg,end,op)	create an map/mmap with the sorting criterion op and initialized
					by elements of the range [beg,end)
c.~map()			destroys all elements and frees memory

map<key,T>			a map that sorts keys with less<>
map<key,T,op>		a map that sorts keys with op
multimap<key,T>		a mmap that sorts keys with less<>
multimap<key,T,op>	a mmap that sorts keys with op

count(key)			returns the number of elements with key key
find(key)			returns the pos of the first element with key key or end()
lower_bound(key)	returns the first position an element with key key would get inserted
upper_bound(key)	returns the last position an element with key key would get inserted
equal_range(key)	returns the first and last position where an element with key key 
					would get inserted
					
c.insert(elem)		insert a copy of elem and returns the position of the new element,
					and for maps,whether it succeeded
c.insert(pos,elem)	insert a copy of elem and returns the position of the new element,
					pos is used to hint pointing to where the insert should start the search
c.insert(beg,end)		inserts a copy of all elements of the range [beg,end) returns nothing

c.erase(elem)		removes all elements with value elem and returns the number of 
					removed elements
c.erase(pos)		removes the element at pos returns nothing
c.erase(beg,end)	removes all elements of the range [beg,end)

m[key]				returns the reference to the value of the element with key key
					inserts an elements with key if it does not yet exist
					

