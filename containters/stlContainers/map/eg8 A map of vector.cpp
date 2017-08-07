#include<iostream> 
#include<map>
#include<vector>
#include<string>
#include<iterator>
#include<algorithm>
#include<ctime>
#include<cstdlib>
using namespace std;

typedef map<string, vector<string> > Thesaurus;
typedef pair<string,vector<string> > TEntry;
typedef Thesaurus::iterator It;

//name look up work-around
namespace std{
ostream& operator<<(ostream& out,const TEntry t){
	out<<t.first<<" : ";
	copy(t.second.begin(),t.second.end(),
		ostream_iterator<string>(out," "));
	return out;
}
}

//a generator for thesaurus test entries
class ThesaurusGen{
	private:
		static const string letters;
		static int count;
	public:
		int maxSize(){return letters.size();}
		TEntry operator()(){
			TEntry result;
			if(count>=maxSize()) count=0;
			result.first = letters[count++];
			int entries = (rand()%5)+2;
			for(int i=0;i<entries;++i){
				int choice=rand()%maxSize();
				char buf[2]={0};
				buf[0]=letters[choice];
				result.second.push_back(buf);
			}
			return result;
		}
};
int ThesaurusGen::count=0;
const string ThesaurusGen::letters("ABCDEFGHIJKLMNOPQRSTUVWXYZ"
									"abcdefghijklmnopqrstuvwxyz");
//ask for a "word" to look up
string menu(Thesaurus& thesaurus){
	while(true){
		cout<<"select a \"word\" ,0 to quit:";
		for(It it=thesaurus.begin();it!=thesaurus.end();++it)
			cout<< it->first <<' ';
		cout<<endl;
		string reply;
		cin>>reply;
		if(reply.at(0)=='0') exit(0);
		if(thesaurus.find(reply)==thesaurus.end())
			continue;//not in list,try angin
		return reply;
	
	}
}


int main(){
	srand(time(0));
	Thesaurus thesaurus;
	//fill with 10 entries
	generate_n(inserter(thesaurus,thesaurus.begin()),10,ThesaurusGen());
	//print all
	copy(thesaurus.begin(),thesaurus.end(),ostream_iterator<TEntry>(cout,"\n"));
	//create a list of the keys
	string keys[10];
	int i=0;
	for(It it=thesaurus.begin();it!=thesaurus.end();++it)
		keys[i++] = it->first;
	for(i=0;i<10;++i){
		//entry from the console
		string reply = menu(thesaurus);
		//Generate randomly
		//string reply=keys[rand()%10];
		vector<string>& v = thesaurus[reply];
		copy(v.begin(),v.end(),ostream_iterator<string>(cout," "));
		cout<<endl;
	}
	
	return 0;
}
