valarray()

explicit valarray(size_t num)
* creates a valarray that contains num elements initialized with 0

valarray(const T& value, size_t num)
* create a valarray that contains num elements initialized with value

valarray(const T* array,size_t num)
* create a valarray that contains num elements
* the elements are initialized by the values of array

valarray(const valarray& va)

valarray& operator=(const valarray& va)
* if the size() of two valarray differs,the result is undefined

valarray& operator=(const T& value)
* assign value to each elements 

Member Functions

size_t size()const
* returns the current number of elements

void resize(size_t num)
void resize(size_t num, T value)
* both form change the size of valarray to num
* if the size grows, the new elements are initialized by 0 or value
* both forms invalidate all pointers and reference

T min()const
T max()const
* returns the min or max value of the array
* the elements are compared with operator < or > ,thus the operator must provided by
  the element type
* if the valarray contains no elements, the return value is undefined

T sum()const
* returns the sum of all elements
* the elements are processed by operator+=,thus this operator has to be provided for
  the element type
* if the valarray contains no elements,the return value is undefined

valarray shift(int num)const
* returns a new valarray in which all elements are shifted by num position
* elements of position that are shifted are initialized by the default constructor
* if num is positive, it shift to the left/front
  if num is negative, it shift to the right/back
  
valarray apply(T op(T))const
valarray apply(T op(const T&))const
* both froms returns a new valarray with all elements processed by op()

T& operator[](size_t idx)
T operator[](size_t idx)const

Valarray Operators

valarray unary-op()const
+ - ~ !
* the return type of operator! is valarray<bool>


valarray binary-op()(const valarray& va1,const valarray& va2)
valarray binary-op()(const valarray& va,const T& value)
valarray binary-op()(const T& value,const valarray& va)
+ - * / % ^ & | << >>
* if only one operand is passed as a single value,it is combined with each
  elements of va
* if va1 and va2 have different number of elements,the result is undefined

valarray<bool> logical-op(const valarray& va1,const valarray& va2)
valarray<bool> logical-op(const valarray& va,const T& value)
valarray<bool> logical-op(const T& value,const valarray& va)
==  !=  <  <=  >  >=  &&  ||
* if va1 and va2 have different number of elements,the result is undefined

valarray& assign-op(const valarray& va)
valarray& assign-op(const T& value)
+=  -=  *=  /=  %=  ^=  &=  |=  <<=  >>= 

