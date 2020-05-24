#include<iostream>
#include<malloc.h>

using namespace std;

struct phanso {
	float  num;  // numerrator
	float  deno; // denominator
};
typedef phanso ps;

void inputFraction(phanso& s);

void inputFractionarray(phanso*& a, int& n); 

void outPutFraction(ps* a, int n); 

void insertFraction(ps*& a, int& n, ps  x); 

void deleteFraction(ps* a, int& n); 

int  GCD(ps a);

void compactFraction(ps& a);

void compactFraction_array(ps* a, int n);


int main()
{
	ps* a;
	int n;
	ps x;
	int temp = 1;
	int sel = 0;
	inputFractionarray(a, n);

	while (temp != 0)
	{
		cout << " Export  elements of array .Fress 1." << endl;
		cout << " If you want to  insert  to the array  . Fress 2." << endl;
		cout << " If you want to  delete to  the array . Fress 3." << endl;
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
			deleteFraction(a, n);
			break;
		}
		cout << " Do you want to continue ?" << "\t YES.1 \tNO.0 " << endl;
		cin >> temp;
	}
	free(a);

}
void inputFraction(phanso& s) {
	cout << "\nEnter the numerator:  ";
	cin >> s.num;
	cout << "\nEnter the denominator:";
	cin >> s.deno;
	while (s.deno == 0) {

		if (s.deno == 0) {
			cout << "\nEnter the number other than zero !" << endl;
		}
		cin >> s.deno;
	}
}

void inputFractionarray(phanso*& a, int& n) {
	cout << " ** Enter the size of array ** " << endl;
	cin >> n;
	a=(ps*) malloc(n * sizeof(ps));
	cout << " ** Enter the array elements ** " << endl;
	for (int i = 0; i < n; i++) {
		inputFraction(a[i]);
	}
}

void outPutFraction(ps* a, int n) {
	for (int i = 0; i < n; i++)
	{
		if ((a + i)->deno == 1) {
			cout << (a + i)->num << endl;
		}
		else
			cout << (a + i)->num << "/" << (a + i)->deno << endl;
	}
}

void insertFraction(ps*& a, int& n, ps  x) {
	//(a + n)->num = x.num;
	//(a + n)->deno = x.deno;
	//n++;
	int m = n + 1;
	ps* anew = (ps*)realloc(a, m * sizeof(ps));
	if (anew != NULL) {
		anew[n].num = x.num;
		anew[n].deno = x.deno;
		n++;
		a = anew;
	}
	
}

int  GCD(ps a) {
	// greatest common  divisor 
	if (a.num == 0 || a.deno == 0) {
		return a.num + a.deno;
	}
	while (a.num != a.deno) {
		if (a.num > a.deno) {
			a.num -= a.deno;
		}
		else {
			a.deno -= a.num;
		}
	}
	return a.num;
}

void compactFraction(ps& a)
{
	int temp = GCD(a);
	a.num /= temp;
	a.deno /= temp;
}

void compactFraction_array(ps* a, int n) {
	for (int i = 0; i < n; i++) {
		compactFraction(*(a + i));
	}
}

void deleteFraction(ps* a, int& n) {
	int m = n - 1;
	ps* anew = (ps*)realloc(a, m * sizeof(ps));
	if (anew != NULL) {
		anew[n].num = NULL;
		anew[n].deno = NULL;
		n--;
		a = anew;
	}
}
