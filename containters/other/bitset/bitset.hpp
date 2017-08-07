bitset<bits>::bitset()		
* create a bitset with all bits initialzed with zero
* eg: bitset<50> flags;	//flags:000...0000

bitset<bits>::bitset(unsigned long value)
* create a bitset that si initialized according to the bits of the integral value
* eg: bitset<50> flags(7); //flags:000...000111

explicit bitset<bits>::bitset(const string& str)
bitset<bits>::bitset(const string& str,string::size_type str_idx)
bitset<bits>::bitset(const string& str,string::size_type str_idx,
					 string::size_type str_num)
* all forms create a bitset that is initialized by the string str or a substring of str
* the string or substring may contain only the characters '0' and '1'
* str_idx is the index of the first character of str that is used for initialization
* throw invalied_argument if one of the characters is neither '0' nor '1'
* eg: bitset<50> flags(string("1010101")); 		//flags:000...0001010101
* eg: bitset<50> flags(string("1111000"),2,3); 	//flags:000...0000000110

Nonmanipluating Operation
size_t bitset<bits>::size()const
* returns the number of bits

size_t bitset<bits>::count()const
* returns the number of set bits(bits with value 1)

bool bitset<bits>::any()const
* returns whether any bit is set

bool bitset<bits>::none()const
* returns whether no bit is set

bool bitset<bits>::test(size_t idx)const
* returns whether the bit at idx is set
* throws out_of_range if idx>=size()

bool bitset<bits>::operator==(const bitset<bits>& bits)const
* returns whether all bits of the two have the same value

bool bitset<bits>::operator!=(const bitset<bits>& bits)const
* returns whether any bits of the two have different value

Manipulating Operations

bitset<bits>& bitset<bits>::set()
* set all bits to true
* returns the modified bitset

bitset<bits>& bitset<bits>::set(size_t idx,int value=0)
* sets the bit at idx according to the value
* returns the modified bitset
* the default value is false,any other value is regard as true

bitset<bits>& bitset<bits>::reset()
* resets all bits to false
* returns the modified bitset

bitset<bits>& bitset<bits>::reset(size_t idx)
* resets the bit as idx to false
* returns the modified bitset

bitset<bits>& bitset<bits>::flip()
* toggles all bits
* returns the modified bitset

bitset<bits>& bitset<bits>::flip(size_t idx)
* toggle the bit at idx

bitset<bits>& bitset<bits>::operator^=(const bitset<bits>& theBits)
* the bitwise exclusive or operator
* toggles the value of all bits that are set in theBits and leaves all othes unchanged

bitset<bits>& bitset<bits>::operator|=(const bitset<bits>& theBits)
* the bitwise or operator
* sets all bits that are set in theBits and leaves all others bits unchanged

bitset<bits>& bitset<bits>::operator&=(const bitset<bits>& theBits)
* the bitwise and operator
* resets all bits that are not set in theBits and leaves all other unchanged

bitset<bits>& bitset<bits>::operator<<=(size_t num)
* shifts all bits by num positions to the left
* the first num bits are set to false

bitset<bits>& bitset<bits>::operator>>=(size_t num)
* shifts all bits by num position to the right
* the last num bits are set to false

Access with operator []
bitset<bits>& bitset<bits>::operator[](size_t idx)
bool bitset<bits>::operator[](size_t idx)const
* both forms returns the bits at position idx

Creating new modified Bitsets
bitset<bits> bitset<bits>::operator~()const
* returns a new bitset what has all bits toggled with respect to *this

bitset<bits> bitset<bits>::operator<<(size_t num)const
* returns a new bitset that has all bits shifted to the left by num position

bitset<bits> bitset<bits>::operator>>(size_t num)const
* returns a new bitset that has all bits shifted to the right by num position

bitset<bits> bitset<bits>::operator&(const bitset<bits>& b1,const bitset<bits>& b2)
* returns the bitwise computing of operator and of b1 and b2
* returns a new bitset that has noly those bits set in b1 and b2

bitset<bits> bitset<bits>::operator|(const bitset<bits>& b1,const bitset<bits>& b2)
* returns the bitwise computing of operator or of b1 and b2
* returns a new bitset that has only those bits set in b1 or in b2

bitset<bits> bitset<bits>::operator^(const bitset<bits>& b1,const bitset<bits>& b2)
* returns the bitwise computing of operator exclusive-or of b1 and b2
* returns a new bitset that has noly those bits set in b1 and not set in b2 or vice sersa

Operation for type conversions

unsigned long bitset<bits>::to_ulong()const
* returns the intergal value that the bits of bitset represent
* throws overflow_error if the integral value can't be represented by type unsigned long

string bitset<bits>::to_string()const
* returns a string that contains the value of bitset as a binary representation written
  with character '0' and '1' 
* the order of the character is equivalent to the order of the bits with descending index

Input/Output Operation
istream& operator>>(istream& strm, bitset<bits>& bits)
* reads into bits a bitset as a character sequence of character '0' and '1'
* reads until any of the following happens:
  - at most,bits character are read
  - End-of-file occurs in strm
  - the next character is neither '0' nor '1'
* returns strm

ostream* operator<<(ostram* strm, bitset<bits>& bits)
* writes bits converted into a string that contains the binary representation
* use to_string() to create the output character
* returns strm

