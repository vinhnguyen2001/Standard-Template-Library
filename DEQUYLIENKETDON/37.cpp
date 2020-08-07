#include<iostream>

using namespace std;

int Factorial(int n);

int Combination(int n, int k);

void PrintPascal(int n);

int main() {
	int row = 0;
	cout << "\nNHAP SO DONG BAN MUON IN RA : ";
	do {
		cin >> row;

		if (row <= 0) {
			cout << "\nKHONG HOP LE.XIN HAY NHAP LAI " << endl;
		}
	} while (row <= 0);
	PrintPascal(row-1);
	return 0;
}


int Factorial(int n) {
	int fac = 1;
	for (int i = 1; i <= n; i++) {
		fac *= i;
	}
	return fac;
}

int Combination(int n, int k) {
	return (Factorial(n) / (Factorial(k) * Factorial(n - k)));
}

void PrintPascal(int n) {
	if (n == 0) {
		cout << "1";
	}
	else if (n >= 1) {
		PrintPascal(n - 1);
		cout << endl;
		for (int i = 0; i <= n; i++) {
			cout << Combination(n, i) << "\t";

		}
	}
}
