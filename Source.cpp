#include <iostream>
#include <vector>
#include <memory>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <array>
#include <typeinfo>
#include <algorithm>
#include <string.h>
using namespace  std;

template <typename T, template <typename, typename> class Container>
ostream& operator<<(ostream& os, Container<T, allocator<T> > c1)
{
	for (const auto& ele : c1)
		cout << ele << ' ';
	cout << endl;
	return os;
}

template <
	typename T, 
	template <typename, typename> class Container1,
	template <typename, typename> class Container2 >
ostream& operator<< (ostream& os, Container1 < Container2 <T, allocator<T>>, allocator <Container2 <T, allocator<T>> >> C)
{
	for (const auto& v : C)
	{
		for (const auto& ele : v)
			cout << ele << ' ';
		cout << endl;
	}
	return os;
}

//template <typename T, template <typename, size_t N> class Container >
//ostream& operator<< (ostream& os, Container <T, N> ar)
//{
//
//}

//template <typename T, template <typename, typename> class Container>
//class MyContainer
//{
//public:
//	MyContainer()
//
//private:
//	Container <T, allocator <T>> data;
//};

template <class T>
struct A
{
	//A(T) { ; }
	struct B{};
	typedef void C;
	void f();

	template <class U>
	void g(U);
};

template <class B>
void A<B>::f()
{
	B b;
	C a();
	cout << typeid(b).name() << endl;
	cout << typeid(a).name() << endl;
}

//template <class B>
//template <class C>
//void A<B>::g(C)
//{
//
//}

template <class T, class U>
void func(T, U)
{
	cout << typeid(T).name() << endl << typeid(U).name() << endl;
	cout << typeid(string).name();
}

template <class T, class _Ty = vector<T>, class _Alloc = allocator<T> >
void Func()
{

}

int main1()
{
	/*vector<int> vec({ 1,2,3,4,5, });
	stack<int> s({ 1,2,3,4,5,10 });
	queue<int> q({ 1,2,3,4,5,5,10 });
	deque<int> dq({ 1,23,4,5,5 });
	list<int> l({ 1,2,3,4,5,23,23,23,23 });
	array<int, 10> ar({ 1,2,3,4,5,6,7,8,9,10 });*/

	A<int> obj;
	obj.f();

	func(2022, "Hello World!"); cout << endl;

	cout << int() << "  " << typeid(int()).name() << endl;
	cout << string() << "  " << typeid(string()).name() << endl;
	cout << float() << "  " << typeid(float()).name() << endl;
	cout << bool() << "  " << typeid(bool()).name() << endl;
	return 0;
}