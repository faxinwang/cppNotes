vector operation 	effect
vector<T> c			create an empty vector without any elements
vector<T> c(c2)		initialize a vector with another vector of the same type
vector<T> c(n)		create a vector	with n elements that are created by the default constructor
vector<T> c(n,elem)	create a vector initialized with n copies of element elem
vector<T> c(beg,end)create a vector initialized with the range [beg,end)
c.~vector<T>()		destory all elements and frees the memory

//nonmodifying operation
c.capacity()		returns the max possible number of elements without reallocation
c.reserve()			enlarges capacity,if not enough yet

//assingments
c.assign(n,elem)	assign n copies of element elem
c.assign(beg,end)	assign the elements of the range [beg,end)

//element access
c.at(idx)			returns the element if index idx is valid(checked)
c[idx]				returns the element with index idx(unchecked)
c.front()			returns the first element(unchecked)
c.back()			returns the last element(nuchecked)

//operate elements
c.insert(pos,elem)	insert the copy of elem at pos and returns the position of the new element
c.insert(pos,n,elem)insert n copies of elem at pos returns nothing
c.insert(pos,beg,end)insert a copy of all elements of the range [beg,end) at pos returns nothing

c.push_back(elem)	appends a copy of elem at the end
c.pop_back()		remove the last element(does not return it)

c.erase(pos)		remove the element at pos and returns the position of the next element
c.erase(beg,end)	remove all elements of the range [beg,end) returns the position of next element

c.resize(num)		changes the number of elements to num(if size() grows,new elements are created by the default constructor)
c.resize(num,elem)	changes the number of elements to num(if size() grows,new elements are copies of elem)

