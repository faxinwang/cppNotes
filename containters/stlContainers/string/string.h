
可将stirng类视作一个容器，其部分操作如下:
(设pos,pos1,pos2, n,n1,n2, 是无符号整数， str,str1,str2,是string类型对象,
	istr,ostr分别是istream,ostream对象,ch,delim是字符,charArray是字符数组)
1.构造函数:
	string s				构造一个空串s 
	string s(charArray)		用字符数组初始化 
	string s(charArray,n)	用字符数组的前n个字符初始化 
	string s(str)			拷贝构造函数 
2.输入输出:
	getline(istr,s,delim)	从istr中读取字符存入s,个数达到n,或遇到文件尾,或遇到delim表示的字符时结束
	getline(istr,s)			从istr中提取字符存入s,遇到换行符结束,会提取换行符但不存入s中
	istr>>s					从istr中提取字符,遇到空白时结束,返回istr
	ostr<<s					将s插入ostr中，返回ostr
3.操作符
	s=val					赋值 
	s+=val					添加到s后面 
	s[pos]					下标操作 
	s+t						返回s和t连接的结果,t可以是串，字符数组，字符 
	<,<=,>,>=,==,!= 		比较
4.添加
	s.append(str)			将str添加在s之后 
	s.append(str,pos,n)		将str中从pos开始的n个字符添加到s之后 
	s.append(charArray)		将字符数组添加到s之后
5.赋值
	s.assign(str)			用str给s赋值 
	s.assign(str,pos,n)		用str中从pos开始的n个字符给s赋值 
	s.assign(charArray) 	用字符数组给s赋值
6.求长度
	s.size()				两个都不能用于统计c风格的一'\0'结尾的字符串的长度 
	s.length()
7.比较
	s.compare(str) 			根据s小于，等于或大于str,返回负数，0 ，正数 
	s.compare(charArray)	同上 
	s.compare(pos,n,str)	s中从pos的n个字符同str比较
8.插入
	s.insert(pos,str)			在pos处插入str 
	s.insert(pos1,str,pos2,n)	将str中从pos2开始的n个字符插入插入pos1处 
	s.insert(pos,charArray,n) 	将charArray前n个字符插入pos处
9.替换
	s.replace(pos1,n1,str)			用str替换s中从pos1开始的n个字符 
	s.replace(pos1,n1,str,pos2,n2)	用str中从pos2开始的n2个字符替换s中从pos1开始的n1个字符 
	s.replace(pos1,n1,charArray,n2)	用charArray的前n个字符替换s中从pos1开始的n1个字符 
	s.replace(pos1,n1,n2,ch)		用n2个字符ch替换s中从pos1开始的n1个字符
10.取子串
	s.substr(pos,n)			返回s中从pos开始的n个字符,pos默认值为0,n默认值为s的长度
11.判空
	s.empty() 
12.查找
	s.find(str,pos)			在s中从pos处开始查找str,若查找成功返回str首次出现的位置,pos默认值为0 
	s.find(charArray,pos) 	同上 
	s.rfind(str,pos)		在s的前(pos+str.size())中查找str,若查找成功返回最后一次出现的位置,否则返回-1，
	
size_type s.find_first_of(const string& str) const
size_type s.find_first_of(const string& str,size_type idx)const
size_type s.find_first_not_of(const string& str)const
size_type s.find_first_not_of(const string& str,size_type idx)const

size_type s.find_first_of(const char* cstr) const
size_type s.find_first_of(const char* cstr,size_type idx)const
size_type s.find_first_not_of(const char* cstr)const
size_type s.find_first_not_of(const char* cstr,size_type idx)const

size_type s.find_first_of(const char* cstr,size_type idx,size_type str_len)const
size_type s.find_first_not_of(const char* cstr,size_type idx,size_type str_len)const

size_type s.find_first_of(char c) const
size_type s.find_first_of(char c,size_type idx)const
size_type s.find_first_not_of(char c)const
size_type s.find_first_not_of(char c,size_type idx)const
//all those functions have corresponding function : find_last_
	
string类准备了三个函数将string类转换为C风格的字符串:
	s.c_str()	将存储在s中的字符串作为字符数组返回,并添加'\0' 作为结束符 
	s.data()	将存储在s中的字符串作为字符数组返回,不添加结束符 '\0' 
	s.copy(charArray,n,pos)	用s中从pos开始的n个字符替换charArray的前n个字符 ,pos的默认值为0,返回用于替换的字符个数 
