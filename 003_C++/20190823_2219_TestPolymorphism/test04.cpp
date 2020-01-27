#include <iostream>
using namespace std;
#include <string>



class A {
	public:
		A(){ f() ;}
		virtual void f() const {cout << "A::f()" << endl ;}
};

class B : public A {
	public:
		virtual void f() const {cout << "B::f()" << endl ;}
};

int main() {
	A a;
	B b;
	A* pa(&b);
	pa->f();
	return 0;
}

/* result : 
$ g++ test04.cpp -o test04
$ ./test04
A::f()
A::f()
B::f()


*/


