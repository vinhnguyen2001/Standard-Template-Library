#include<iostream>
#include<stdlib.h>
#include<algorithm>

using namespace std;

void inputArray(int*& a, int& n);

void outputArray(int* a, int n);

void  sumEvenNumber(int* a, int n, int sum );

int searchMaxValue(int* a, int n);

int findElement(int* a, int n , int val);

void  reserseArray(int*& a, int n);

void sortArray(int*& u_arr, int n);

int Factorial(int n);

int Combination(int n , int k );

void frintPascal(int n);

double XMu_N(double x, int n);// x mũ n.

double sumOfSequenceOfnum(int n );


int main() {
	int* a = nullptr;
	int n = 0;
	inputArray(a,n);
	int temp=1;
	while (temp) {
		cout << "NHAN 1 . TINH TONG CUA CAC PHAN TU CHAN TRONG MANG.";
		cout << "\nNHAN 2 . TIM GIA TRI LON NHAT TRONG MANG.";
		cout << "\nNHAN 3 . TIM VI TRI CUA MOT PHAN TU CHO TRUOC CO TRONG MANG HAY KHONG.";
		cout << "\nNHAN 4 . DAO NGUOC MANG BAN DAU .";
		cout << "\nNHAN 5 . SAP XEP MANG TANG DAN THEO THUAT TOAN CHEN TRUC TIEP.";
		cout << "\nNHAN 6 . IN TAM GIAC  Pascal.";
		cout << "\nNHAN 7 . TINH TONG   S = 1 - 1/2 + 1 / 3 +....(+/-) 1/n ";
		cout << "\nNHAN 8 . TINH x ^ n  ";
		cout << "\nNHAN 9 . TINH C(K+1,N+1).(tuong duong tinh to hop )" << endl;
		int selec = 0;
		cin >> selec;
		switch (selec) {
		case 1: {
			int sum = 0;
			sumEvenNumber(a, n, sum);
			break;
		}
		case 2: {
			cout<<"\nGIA TRI LON NHAT TRONG MANG LA : "<<searchMaxValue(a, n);
			break;
		}
		case 3: {
			int val = 0;
			cout << "\nNHAP GIA TRI MA BAN MUON TIM KIEM : ";
			cin >> val;
			int pos = findElement(a, n, val);
			if (pos != -1) {
				cout << "\nVI TRI CUA GIA TRI " << val << " TRONG MANG LA : " << pos;
			}
			else {
				cout << "\nGIA TRI " << val << " KHONG CO TRONG MANG.";
			}
			break; 
		}
		case 4: {
			reserseArray(a, n);
			cout << "\nMANG SAU KHI DUOC DAO NGUOC  : ";
			outputArray(a, n);
			break; 
		}
		case 5: {
			int value = 0;
			sortArray(a, n);
			cout << "\nMANG SAU KHI DUOC SAP XEP .";
			outputArray(a, n);
			break; 
		}
		case 6: {
			int row = 0;
			cout << "\nNHAP SO DONG BAN MUON IN RA : ";
			do {
				cin >> row;
				if (row <= 0) {
					cout << "\nBAN VUA NHAP SAI. HAY NHAP LAI.";
				}
			} while (row <=0);
			frintPascal(row);
			break; 
		}
		case 7: {
			cout << "\nNHAP  n :";
			int N = 0;
	
			do {
				cin >>N;
				if (N <= 0) {
					cout << "\nBAN VUA NHAP SAI. HAY NHAP LAI." << endl;
				}
			} while (N <= 0);
			cout<<"TONG LA : "<<sumOfSequenceOfnum(N);
			break;
		}
		case 8: {
			cout << "\nNHAP GIA TRI CUA X :";
			int x=0;
			cin >> x;
			cout << "\nNHAP SO MU : ";
			int mu = 0;
			cin >> mu;
			cout<<"\nGIA TRI CUA "<<x<<"^"<<mu<<" : "<<XMu_N(x, mu);
			break; 
		}
		case 9: {
			cout << "\nNHAP N :";
			int N_1 = 0;
			cin >> N_1;
			cout << "\nNHAP K :";
			int K = 0;
			cin >> K;
			cout <<"KET QUA : "<< Combination(N_1, K);
			
		}

		}
		cout << "\nBAN MUON TIEP TUC KHONG ? \t CO. 1 \t KHONG 0" << endl;
		cin >> temp;
		cout << endl;
	}
	if (a) {
		delete[]a;
		a = nullptr;
	}
}

void inputArray(int*& a, int& n) {
	cout << "\nNHAP SO PHAN TU CUA MANG : ";
	do {
		cin >> n;
		if (n <= 0) cout << "\n";
	} while (n <= 0);
	a = (int*)malloc(n * sizeof(int));
	if (!a) {
		cout << "\nLoi bo nho ! ";
		return;
	}
	cout << "\nNHAP LAN LUOT CAC GIA TRI CUA CAC PHAN TU : " << endl;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
}

void outputArray(int* a, int n){
	for (int i = 0; i < n; i++) {
		cout << a[i] << "\t";
	}
}

void  sumEvenNumber(int* a, int n, int sum = 0) {
	// tong cua cac so chan trong mang 1 chieu 
	if (n > 0) {
		if ((a[n - 1]) % 2 == 0) {
			sum += a[n - 1];
		}
	}
	else {
		cout << " TONG CUA CAC PHAN TU CHAN TRONG MANG  : " << sum << endl;
		return;
	}
	sumEvenNumber(a, n - 1, sum);
}


int searchMaxValue(int* a, int n) {
	// tim gia tri lon nhat trong mang 
	if (n == 1) {
		return a[0];
	}
	int temp = searchMaxValue(a, n - 1);
	if (temp > a[n - 1]){
		return temp;
	}
	return a[n - 1];
}

int findElement(int* a, int n, int val) {
	/* tim vi tri cua 1 phan tu cho truoc trong mang :
	 + neu co tra ve vi tri cua phan tu do tron mang.
	 + neu khong thi tra ve -1.
	*/
	if (n ==0) {
		return -1;
	}
	if (a[n - 1] == val) {
		return n - 1;
	}
	else return findElement(a, n - 1, val);
}

void reserseArray(int*&a, int n) {
	// dao nguoc mang 
	static int i = 0;
	if (n == 2) {
		return ;
	}
	if (n >= 3 && i< n) {
		swap(a[i], a[n-1]);
	}
	i++;
	reserseArray(a, n - 1);
	
}

void sortArray(int*& u_arr, int n) {
	if (n == 2) {
		if (u_arr[n-2]  > u_arr[n-1]) {
			swap(u_arr[n-2], u_arr[n-1]);
		}
	}
	if (n > 2) {
		sortArray(u_arr, n - 1);
		for (int i = 0; i < n-1; i++)
		{
			int X = u_arr[n - 1];
			if (u_arr[i] > X) {
				for (int j = n - 1; j >= i; j--) {
					u_arr[j] = u_arr[j - 1];
				}
				u_arr[i ] = X;
				break;
			}
		}
	}
}

int Factorial(int n) {
	int fac = 1;
	for (int i = 1; i <= n; i++) {
		fac *= i;
	}
	return fac;
}

int Combination(int n , int k ) {
	return (Factorial(n) / (Factorial(k) * Factorial(n - k)));
}

void frintPascal(int n){
	if (n == 0) {
		cout << "1";
	}
	else if (n >= 1) {
		frintPascal(n - 1);
		cout << endl;
		for (int i = 0; i <= n; i++) {
			cout << Combination(n, i) << "\t";
		
		}
	}
}

double XMu_N (double x, int n) {
	if (n == 0) return 1;
	if (n == 1) return x;
	else return  x*XMu_N(x,n - 1);
}

double sumOfSequenceOfnum(int n){
	if (n == 1) return 1;
	return pow( -1, n-1)* ( 1 / (double) n) + sumOfSequenceOfnum(n - 1);
}