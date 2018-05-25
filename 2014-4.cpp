#include <iostream>
using namespace std;
class B {
public:
	B() { z = -5; cout << "B() : z = " << z << endl; }
	B(int z_val) :z(z_val) { cout << "z = " << z << endl; z++; }
	virtual int get_val() { --z; return (z - 1); };
	int gv2() { --z; return (z - 2); }
private:
	int z;
};
class D1 : public B {
public:
	D1() { x = 7; cout << "D1() : x = " << x << endl; x++; }
	D1(int x_val) : x(x_val) { cout << "x = " << x << endl; x--; }
	virtual int get_val() { x++; return x; };
	int gv2() { x++; return x + 1; }
private:
	int x;
};
class D2 : public B {
public:
	D2() { y = 2; cout << "D2() : y = " << y << endl; }
	D2(int y_val) : y(y_val) { cout << "y = " << y << endl; }
	int get_val() { y--; return y; }
	virtual int gv2() { y--; return y*y; };
private:
	int y;
};
void myf1(B& f) { cout << "7 : " << f.get_val() << endl; }
void myf2(B& f) { cout << "8 : " << f.gv2() << endl; }
void myf3(D1& f) { cout << "9 : " << f.get_val() << endl; }
void myf4(D1& f) { cout << "10 : " << f.gv2() << endl; }
int main()
{
	B Zero(0); D1 Two; D2* d2ptr;
	B* B_ptrArray[2];
	B_ptrArray[0] = &Zero;
	B_ptrArray[1] = &Two;
	d2ptr = new D2;
	cout << "0 : " << B_ptrArray[0]->get_val() << endl;
	cout << "1 : " << Two.get_val() << endl;
	cout << "2 : " << Two.gv2() << endl;
	cout << "3 : " << B_ptrArray[1]->get_val() << endl;
	cout << "4 : " << B_ptrArray[1]->gv2() << endl;
	cout << "5 : " << d2ptr->gv2() << endl;
	cout << "6 : " << d2ptr->get_val() << endl;
	myf1(Two);
	myf2(Two);
	myf3(Two);
	myf4(Two);
	delete d2ptr;
	return 0;
}