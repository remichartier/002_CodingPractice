#include <iostream>
using namespace std;

class A {
public:
	A() { f(); }
	virtual void f() const { cout << "A::f()" << endl; }
};

class B : public A {
public:
	virtual void f() const { cout << "B::f()" << endl; }
};

int main(){
	A a;
	B b;
	A* pa(&b);
	pa->f();
	return 0;
}

// g++ -o main.exe aspectPolymorphiqueConstructeurs.cpp
/*

./main.exe 
A::f()
A::f()
B::f()


*/