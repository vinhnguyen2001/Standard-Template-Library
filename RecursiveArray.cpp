#include<iostream>

using namespace std;

void inputArray(int*& a, int& n);

void outputArray(int* a, int n);

int CountSubsetSum(int* a, int n, int i , int& count , int value);

bool arrayDecreaseSteadily (int* a, int n  , int i);

void sortAssendingOrderArray(int*& a, int n);

int main() {
	int* a = nullptr;
	int n = 0;
    int b[] = { 2, 3, 5, 6, 8, 10 };
//	for (int i = 0; i < 5; i++) {
	inputArray(a, n);
	//}
	outputArray(a, n);
	int i = 0;
	int count = 0;
	int value = abs(a[1] - a[0]);
	cout << "\ncount : " << CountSubsetSum(a, n, i, count, 10) << endl;
	cout << arrayDecreaseSteadily(a, n, value) << endl;
	sortAssendingOrderArray(a, n);
	outputArray(a, n);
	if (a) {
		delete[]a;
		a = nullptr;
	}
	return 0;
}

void inputArray(int*& a, int& n) {
	cout << "\nNHAP SO PHAN TU CUA MANG : ";
	do {
		cin >> n;
		if (n <= 0) {
			cout << "\nBAN VUA NHAP SAI.HAY NHAP LAI !";
		}
	} while (n <= 0);
	a = new(std::nothrow) int[n];
	if (!a) {
		cout << "\nLOI VUNG NHO TRONG LUC CAP PHAT !";
		return;
	}
	cout << "\nNHAP LAP LUOT CAC PHAN TU CUA MANG." << endl;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
}

void outputArray(int* a, int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << "  ";
	}
}

int CountSubsetSum(int* a, int n, int i ,int& count , int value) {
	
	if (i == n) {
		if (value == 0) {
			count++;
		}
		return count;
	}
  CountSubsetSum(a, n, i + 1, count, value - a[i]);
  CountSubsetSum(a, n, i + 1, count, value);
}

bool arrayDecreaseSteadily(int* a, int n , int i) {
	if (n == 1) return true;

	if (n > 1) {

		if (abs(a[n - 1] - a[n - 2]) != i || a[n-1] >= a[n-2]) {
			return false;
		}
		else return arrayDecreaseSteadily(a, n - 1, i);
	}
}

void sortAssendingOrderArray(int*& a, int n) {
	if (n == 2) {
		if (a[n - 2] > a[n - 1]) {
			swap(a[n - 2], a[n - 1]);
		}
	}
	if (n > 2) {
		sortAssendingOrderArray(a, n - 1);
		int X = a[n - 1];
		for (int i = 0; i < n - 1; i++) {
			if (a[i] > X) {
				for (int j = n - 1; j > i; j--) {
					a[j] = a[j - 1];
				}
				a[i] = X;
				break;
			}
		}
	}
}