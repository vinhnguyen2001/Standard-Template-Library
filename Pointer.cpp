#include<iostream>
using namespace std;
int main() {
	
	float a[5] = { 5,10,15,20,25 };
	float* p = &a[0];
	float* q = &a[1];
	cout << "\n&p:" << &p;
	cout << "\np:" << p;
	cout << "\n*p" << *p;
	cout << "\n&a[0]:" << &a[0];
	cout << "\na[0]:" << a[0];
	cout << "\n&a[1]:" << &a[1];
	cout << "\na[1]:" << a[1];
	cout << "\n&a[2]:" << &a[2];
	cout << "\na[2]:" << a[2];
	cout << endl;
	cout << "\n*p++" << *p++;
	cout << endl;
	cout << "\n&p:" << &p;
	cout << "\np:" << p;
	cout << "\n*p" << *p;
	cout << "\n&a[0]:" << &a[0];
	cout << "\na[0]:" << a[0];
	cout << "\n&a[1]:" << &a[1];
	cout << "\na[1]:" << a[1];
	cout << "\n&a[2]:" << &a[2];
	cout << "\na[2]:" << a[2];
	cout << endl;
	cout << "\n*++p" << *++p;
	cout << endl;
	cout << "\n&p:" << &p;
	cout << "\np:" << p;
	cout << "\n*p" << *p;
	cout << "\n&a[0]:" << &a[0];
	cout << "\na[0]:" << a[0];
	cout << "\n&a[1]:" << &a[1];
	cout << "\na[1]:" << a[1];
	cout << "\n&a[2]:" << &a[2];
	cout << "\na[2]:" << a[2];
	cout << endl;
	cout << "\n++*p" << ++*p;
	cout << endl;
	cout << "\n&p:" << &p;
	cout << "\np:" << p;
	cout << "\n*p" << *p;
	cout << "\n&a[0]:" << &a[0];
	cout << "\na[0]:" << a[0];
	cout << "\n&a[1]:" << &a[1];
	cout << "\na[1]:" << a[1];
	cout << "\n&a[2]:" << &a[2];
	cout << "\na[2]:" << a[2];
	cout << "\n&a[3]:" << &a[3];
	cout << "\na[3]:" << a[3];
	cout << endl;
	cout << "\n(*p)++" << ((* p)++);
	cout << endl;
	cout << "\n&p:" << &p;
	cout << "\np:" << p;
	cout << "\n*p" << *p;
	cout << "\n&a[0]:" << &a[0];
	cout << "\na[0]:" << a[0];
	cout << "\n&a[1]:" << &a[1];
	cout << "\na[1]:" << a[1];
	cout << "\n&a[2]:" << &a[2];
	cout << "\na[2]:" << a[2];
	cout << "\n&a[3]:" << &a[3];
	cout << "\na[3]:" << a[3];
	cout << endl;
	cout << "\n&q:" << &q;
	cout << "\nq:" << q;
	cout << "\n*q" << *q;
	cout << endl;
    cout << "*p++ = *q++" << (*p++ = *q++);
	cout << endl;
	cout << "\n&p:" << &p;
	cout << "\np:" << p;
	cout << "\n*p" << *p;
	cout << "\n&q:" << &q;
	cout << "\nq:" << q;
	cout << "\n*q" << *q;
	cout << "\n&a[0]:" << &a[0];
	cout << "\na[0]:" << a[0];
	cout << "\n&a[1]:" << &a[1];
	cout << "\na[1]:" << a[1];
	cout << "\n&a[2]:" << &a[2];
	cout << "\na[2]:" << a[2];
	cout << "\n&a[3]:" << &a[3];
	cout << "\na[3]:" << a[3];
	
	system("pause");
	return 0;
}