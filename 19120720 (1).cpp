#include<iostream>
using namespace std;

void NHAP(int**& a, int&row ); 

void XUAT(int** a, int row); 

void SAPXEP(int** a, int row);

void SAPXEP1DONG(int*& a, int row);

void MENU() {
	int** a = nullptr;
	int n;
	NHAP(a, n);
	int temp = 1;
	int sel = 0;
	while (temp) {
		cout << "\nFRESS 1 DE SAP XEP.";
		cout << "\nFRESS 2 DE XUAT MANG.";
		cout << "\nFRESS 3 DE NHAP LAI MANG MOI.";
		cout << endl;
		cin >> sel;
		switch (sel) {

		case 1: {
			SAPXEP(a, n);
			cout << "\nMANG SAU KHI SAP XEP.";
			cout << endl;
			XUAT(a, n);
			break;
		}
		case 2: {
			cout << "\nMANG BAN VUA NHAP : " << endl;
			XUAT(a, n);
			break;
		}
		case 3: {
			if (a != nullptr) {
				for (int i = 0; i < n; i++) {
					delete[]a[i];
					a[i] = nullptr;
				}
				delete[]a;
				a = nullptr;
				NHAP(a, n);
			}
		  }
		}
		cout << "\nBAN CO MUON TIEP ?" << "\t CO.1 \t KHONG.0";
		cout << endl;
		cin >> temp;
	}
	if (a != nullptr) {
		for (int i = 0; i < n; i++) {
			delete[]a[i];
			a[i] = nullptr;
		}
		delete[]a;
		a = nullptr;
	}
}
int main() {

	MENU();
	return 0;
}
void NHAP(int**& a, int& row ) {
	// ham nhap mang hai chieu

	// kiem tra dieu kien cua so dong 
	do {
		cout << "\nNHAP SO DONG CUA MANG CUA MA TRAN VUONG : ";
		cin >> row;
		if (row <= 0) {
			cout << "\nBAN VUA NHAP SAI.HAY NHAP LAI.";
		}
	} while (row <= 0);
	a = new( std::nothrow) int* [row];
	if (!a) {
		cout << "\nLOI CAP PHAT DONG.";
		return;
	}
	for (int i = 0; i < row; i++) {
		a[i] = new( std::nothrow) int[row];
		if (!a[i]) {
			cout << "\nLOI CAP PHAT DONG.";
			return;
		}
	}
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < row; j++) {
			cout<< "a[" << i << "][" << j << "]:";
			cin >> a[i][j];
			cout << endl; 
		}
	}
}

void XUAT(int** a, int row) {

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < row; j++) {
			cout  << a[i][j];
			cout << "\t";
		}
		cout << endl;
	}
}

void SAPXEP(int** a, int row) {

	// sap xep ma tran tung dong giam dan 
	for (int i = 0; i < row; i++) {
		SAPXEP1DONG(a[i], row);
	}
}

void SAPXEP1DONG(int*& a, int row) {
	// ham sap xep 1 hang 
	for (int i = 0; i < row - 1; i++) {
		for (int j = i + 1; j < row; j++) {
			if (a[i] < a[j]) {
				int max = a[i];
				a[i] = a[j];
				a[j] = max;
			}
		}
	}
}