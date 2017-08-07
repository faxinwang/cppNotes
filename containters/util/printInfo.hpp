

template<class T>
void printInfo(Coll<T> &coll){
	using namespace std;
	cout<<"empty:"<<boolalpha<<coll.empty()<<endl;
	cout<<"size:"<<coll.size()<<endl;
	cout<<"capacity:"<<coll.capacity()<<endl;
}
