Name			Effect
Nonmodifying Algorithms
for_each()		performs an operation for each element
count()			returns the number of elements
count_if()		returns the number of elements that match a criterion
min_element()	returns the element with the smallest value
max_element()	returns the elmeent with the largest value
find()			searches for the first element with the passed value
find_if()		searches for the first element what matches a criterion
search_n()		searches for the first n consecutive elements with certain properties
search()		searches for the first occurrence of a subrange
find_end()		searches for the last occurrence of a subrange
find_first_of()	searches for the first several possible elements
adjacent_find()	searches for two adjacent elements that are equal (by some criterion)
equal()			returns whether two ranges are equal
mismatch()		returns the first elements of two sequences that differ
lexicographical_compare()
				returns wheter a range is lexicographically less than another range
				
Modifying Algorithms
for_each()		performs an operation for each element
copy()			copies a range starting with the first element
copy_backword()	copies a range starting with the last element
transform()		modifies(and copies) elements;combines elements fo two range
merge()			merges two range
swap_ranges()	swaps elements of two ranges
fill()			replaces each elements with a given value
fill_n()		replaces n elements with a given value
generate()		replaces each elments with the result of an operation
generate_n()	replaces n elements with the result of an operation
replace()		replaces elements that have a special value with another value
replace_if()	replaces elements that match a criterion with another value
replace_copy()	replaces elements that have a special value while copying the whole range
replace_copy_if() replaces elements that match a criterion while copying the whole range

Removing Algorithms
remove()		removes elements with a given value
remove_if()		removes elements that match a given criterion
remove_copy()	copies elements that don't match a given value
remove_copy_if()copies elements that don't match a given criterion
unique()		removes adjacent duplicates(elements that are equal to their predecessor)
unique_copy()	copies elements while removing adjacent duplicates

Mutating Algorithms
(algorithms that change the order of elements(and not their values)by
assign and swapping their values)
reverse()		reverses the order of the elements
reverse_copy()	copies the elements while reversing their order
rotate()		rotate the order of the elements
rotate_copy()	copies the elements while rotating their order
next_permutation()	permutate the order of the elements
prev_permutation() 	permutate the order of the elements
random_shuffle()brings the elements into a random order
partition()		changes the order of elments so that elements that match a criterion are 
				at the front
stable_partition()	same as partition() but preserves the relative order of matching and 
					nonmatching elements
				
Sorting Algorithms
sort()			sorts all elements
stable_sort()	sorts while preserving order of equal elements
partial_sort()	sorts unitl the first n elements are correct
partial_sort_copy()	copies elements in sorted order
nth_element()	sorts according to the nth position
partition()		changes the order of the elements so that elements that match a criterion
				are at the front
stable_partition()	same as partition() but preserves the relative order of matching and 
				nonmatching elements
make_heap()		converts a range into a heap
push_heap()		adds a elements to a heap
pop_heap()		removes an element from a heap
sort_heap()		sorts the heap(it is no longer a heap after the call)

Sorted Range Algorithms
(sorted range algorithms require that the ranges on witch they operate are sorted
according to their sorting criterion)
binary_search()	returns whether a range contains an element
includes()		returns whether each element of a range is also an element of another range
lower_bound()	finds the first element greater than or equal to a given value
upper_bound()	finds the first element greater than a given value
equal_range()	returns the range of elements equal to a given value
merge()			merges the elements of two range
set_union()		process the sorted union of two ranges
set_intersection()	process the sorted intersection fo two range
set_difference()process a sorted range that contains all elements of a range that are not
				part of another
set_symmetric_difference() process a sorted range that contains all elements that are in 
				exactly one of two ranges
inplace_merge()	merges two consecutive sorted ranges

Numeric Algorithms
accumulate()	combines all element value(process sum,product,and so forth)
inner_product()	combines all element of two ranges
adjacent_product()	combines all elements of two ranges
adjacent_difference()	combines each elements with its predecessor
partial_sum()	combines each elements with all of its predecessors


Search for							string function		STL algorithm
first occurrence of one element		find()				find()
last occurrence of one element		rfind()				find() with reverse iterators
first occurrence of a subrange		find()				search()
last occurrence of a subrange		rfind()				find_end()
first occurrence of several element find_first_of()		find_first_of()
last occurrence of several element 	find_last_of()		find_first_of() with reverse iterators
first occurrence of n consecutive
elements												search_n()
