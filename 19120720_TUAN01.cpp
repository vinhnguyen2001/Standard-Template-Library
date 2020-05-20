#include<iostream>

using namespace std;

#define MAX 1000
struct phanso {
	float  num;  // numerrator
	float  deno; // denominator
};
typedef phanso ps;

void inputFraction(phanso& s) {
	cout << "\nEnter the numerator:  ";
	cin >> s.num;
	cout << "\nEnter the denominator:";
	cin >> s.deno;
	while ( s.deno == 0) {
		
		if (s.deno == 0) {
			cout << "\nEnter the number other than zero !"<<endl;
		}
		cin >> s.deno;
	}
}

void inputFractionarray(phanso*& a, int& n) {
	cout << " ** Enter the size of array ** " << endl;
	cin >> n;
	ps* a = new phanso [n];
	cout << " ** Enter the array elements ** " << endl;
	for (int i = 0; i < n; i++) {
		inputFraction(a[i]);
	}
}

void outPutFraction(ps* a, int n) {
	for (int i = 0; i < n; i++)
	{
		cout << (a + i)->num << "/" << (a + i)->deno << endl;
	}
}

void insertFraction(ps* a, int& n, ps  x) {
	(a + n)->num = x.num;
	(a + n)->deno = x.deno;
	n++;
}

void deleteFraction(ps* a, int& n) {
	(a - n)->num = NULL;
	(a - n)->deno = NULL;
	n--;
}

int  GCD  (ps a) {
	// greatest common  divisor 
	if (a.num  == 0 || a.deno == 0) {
		return a.num + a.deno ;
	}
	while (a.num !=a.deno ) {
		if (a.num > a.deno ) {
			a.num -= a.deno ; 
		}
		else {
			a.deno -= a.num;
		}
	}
	return a.num;
}
void compactFraction(ps &a)
{
	int temp = GCD(a);
	a.num /= temp;
	a.deno /= temp;
}
 
void compactFraction_array(ps* a , int n ) {
	for (int i = 0; i < n; i++) {
		compactFraction(*(a+i));
	}

}

int main()
{
	
	int n;
	ps x;
	int temp = 1;
	int sel = 0;
	inputFractionarray(a, n);

	while (temp != 0)
	{
		cout << " Export  elements of array .Fress 1." << endl;
		cout << " If you want insert  to the array  . Fress 2." << endl;
		cout << " If you want delete to  the array . Fress 3." << endl;
		cin >> sel;
		switch (sel)
		{
		case 1:
			cout << "\nExport  elements of array :" << endl;
			compactFraction_array(a, n);
			outPutFraction(a, n);
			break;
		case 2:
			cout << " * Enter the fraction you want to insert  to array *  " << endl;
			inputFraction(x);
			insertFraction(a, n, x);
			break;
		case 3:
			cout << " * Enter the fraction you want to element  to array " << endl;
			deleteFraction(a, n);
			break;
		}
		cout << " Do you want to continue ?" << "\t YES.1 \tNO.0 " << endl;
		cin >> temp;
	}
	delete[]a;

}
