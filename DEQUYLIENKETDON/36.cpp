#include<iostream>

using namespace std;

double XMu_N(int x, int n);

double sumOfSequenceOfnum(int n);

int Factorial(int n);

int Combination(int n, int k);


int main() {
	int temp = 1;
	int select = 0;
	while (temp) {
		cout << "\nNHAN 1.TINH x ^ n.";
		cout << "\nNHAN 2.TINH TONG   S = 1 - 1/2 + 1 / 3 +....(+/-) 1/n. ";
		cout << "\nNHAN 3.TINH C(N,K)=C(N-1,K-1)+C(N-1,K)." << endl;
		cin >> select;
		switch (select) {
		case 1: {
			int  x = 0;
			int  n = 0;
			cout << "\nNHAP x : ";
			cin >> x;
			cout << "\nNHAP n : ";
			cin >> n;
			cout << x << "^" << n << " : " << XMu_N(x, n);
			break;
		}
		case 2: {
			cout << "\nNHAP n : ";
			int n2 = 0;
			do {
				cin >> n2;
				if (n2 <= 0) {
					cout << "\nBAN VUA NHAP SAI.HAY NHAP SO NGUYEN DUONG" << endl;
				}
			} while (n2 <= 0);
			cout << " TONG  S : " << sumOfSequenceOfnum(n2);
			break;
		}
		case 3: {
			int k = 0;
			int n3 = 0;
			cout << "\nNHAP N : ";
			do {
				cin >> n3;
				if (n3 <= 0) {
					cout << "\nHAY NHAP SO  NGUYEN DUONG." << endl;
				}
			} 
			while (n3 <= 0 );
			cout << "\nNHAP K : ";
			do {
				cin >> k;
				if (k <= 0 ||k > n3) {
					cout << "\nBAN VUA NHAP SAI.HAY NHAP SO NHO HON BANG N & LON HON BANG 0 !" << endl;
				}
			} while (k < 0  || k>n3);
			cout << "C(" << n3 << "," << k << ") : " << Combination(n3, k);
		}
		}
		cout << "\nBAN CO MUON TIEP TUC KHONG ? \tCO.1 \tKHONG.0" << endl;
		cin >> temp;
		cout << endl;
	}
	return 0;
}



double XMu_N(int x, int n ) {
	if (n < 0) {
	
		if (n == -1) return x;
		else return 1 / (double)(x * XMu_N(x, n + 1));
	}
	else {
		if (x == 0) return 0;
		if (n == 0) return 1;
		if (n == 1) {
			return x;
		}
		return  x * XMu_N(x, n - 1);
	}

}

double sumOfSequenceOfnum(int n) {
	if (n == 1) return 1;
	return pow(-1, n - 1) * (1 / (double)n) + sumOfSequenceOfnum(n - 1);
}

int Factorial(int n) {
	int fac = 1;
	for (int i = 1; i <= n; i++) {
		fac *= i;
	}
	return fac;
}

int Combination(int n, int k) {
	if (k == 0) return 1;
	else return (Factorial(n) / (Factorial(k) * Factorial(n - k)));
	return Combination(n-1,k-1)+ Combination(n-1,k);
}
