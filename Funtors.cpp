#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <memory>

using namespace std;

//Overloading operator<< to cout vector
template <typename T, template <typename, typename> class Container> 
ostream& operator<< (ostream& os, Container <T, allocator<T> > c)
{
	for (const auto& ele : c)
		cout << ele << ' ';
	cout << endl;
	return os;
}

template <typename T>
class X {
public:
	bool operator() (const T& x, const T& y) const { return x > y;}
};

template <typename T>
bool func(const T& x, const T& y) { return x > y; }

namespace User
{
	template <typename T>
	class X
	{
	public:

		X() { ; }
		X(T _val) : val(_val) { ; }
		void operator() (T& x) { x += val;}

		template <T Max>
		T RandomNumber() { return rand() % Max; }
		
		template <T Max>
		T operator() () { return rand() % Max; }

	private:
		T val;
	};
	
	template <int Max>
	int RandomNumber() { return rand() % Max; }
}

int main()
{
	srand(unsigned(time(nullptr)));

	/*===============================================*/
	typedef map<int, string, X<int> > value_type;
	
	value_type mp;
	mp[22] = "Ngo";
	mp[10] = "Quang";
	mp.insert({ 2003, "Thang" });

	value_type::iterator It = mp.begin();
	while (It != mp.end())
	{
		cout << It->first << ": " << It->second << endl;
		++It;
	}
	/*=================================================*/

	int val = 10;
	vector<int> v = { 1,2,3,4,5 };
	cout << "Before Modifying: " << v << endl;
	for_each(v.begin(), v.end(), User::X<int>(val));

	cout << "After  Modifying: " << v << endl;

	/*=================================================*/
	//Cach 1
	const int Max = 100;
	vector <int> RandomVec(10);
	generate(RandomVec.begin(), RandomVec.end(), User::RandomNumber<Max>);
	cout << RandomVec;

	// Cach 2
	vector <int> Random(10);
	//generate(Random.begin(), Random.end(), User::X<int>::RandomNumber<100>);
	generate(Random.begin(), Random.end(), User::X<int>());
	cout << Random;


	User::X<int> obj;
	
	
	return 0;
}