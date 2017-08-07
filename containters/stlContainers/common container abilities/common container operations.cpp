operatoin			effect
container c			create a empty container without any element
container c(c2)		copies a container with the same type
container c(beg,end)initialize a container with copies of range [beg,end)
c.~contType()		deletes all elements and frees the memory

c.size()			returns the actual number of elements
c.empty()			returns whether the container is empty(faster then size()==0)
c.max_size()		returns the maximum number of elements possible

c1 == c2
c1 != c2
c1 < c2
c1 > c2
c1 <= c2
c1 >= c2

c1 = c2				assigns all elements of c2 to c1
c2.swap(c2)			swaps the data of c1 and c2 
swap(c1,c2)			same as global function

c.begin()			returns an iterator for the first element
c.end()				returns an iterator for the position after the last element
c.rbegin()			returns a reverse first position(the position of last elem)
c.rend()			returns a reverse last position(the position before first elem)

c.insert(pos,elem)	insert a copy of elem
c.erase(beg,end)	remove all elements of the range [beg,end)

c.clear()			remove all elements(make the container empty)
c.get_allocator()	returns the memory model of the container

additionly you can initialize a container in the following ways:
(1)initialize with all elements of another container
list<int>  list1;
...
vector<float> vector1(list1.begin(),list1.end());

(2)initialize with the elements of  an array
int array[]={1,2,3,4,5,6};
...
set<int> set1(array,array+sizeof(array)/sizeof(array[0]));

(3)initalize by using standart input
deque<int> deque1((istream_iterator<int>(cin)),	//the two arguments must be in
				  (istream_iterator<int>())		// the parentheses,otherwise a
				 )								// syntax error may occur.
