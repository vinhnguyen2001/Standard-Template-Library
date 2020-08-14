#include<iostream>

using namespace std;

struct SOPHUC {
	int thuc;
	int ao;

};
typedef struct SOPHUC sophuc;

void nhapSOPHUC(SOPHUC& s);

void nhapMangSoPhuc(SOPHUC*& a, int  n);

void xuatMangSoPhuc(SOPHUC* a, int n);

SOPHUC* chen1SoPhuc(SOPHUC* a, int& n_ele);

SOPHUC* xoa1SoPhuc(SOPHUC* a, int&n_ele);

int main() {
	SOPHUC* a;
	int n = 0;
	cout << " NHAP SO LUONG CUA MANG : ";
	cin >> n;
	a = new(std::nothrow) SOPHUC[n];
	if (!a) {
		cout << "\nCAP PHAT THAT BAI.";
		return -1;
	}
	nhapMangSoPhuc(a, n);
	xuatMangSoPhuc(a, n);
	//a = chen1SoPhuc(a, n);
	//xuatMangSoPhuc(a, n);

	a = xoa1SoPhuc(a, n);
	xuatMangSoPhuc(a, n);
	if (a != nullptr) {
		delete[] a;
		a = nullptr;
	}
	return 0;
}

void nhapSOPHUC(SOPHUC& s) {
	cout << "\nNHAP PHAN THUC : ";
	cin >> s.thuc;
	cout << "\nNHAP PHAN AO : ";
	cin >> s.ao;
}

void nhapMangSoPhuc(SOPHUC*& a, int  n) {

	cout << "\nNHAP LAN LUOT CAC PHAN TU CUA SO PHUC." << endl;
	for (int i = 0; i < n; i++) {
		nhapSOPHUC(a[i]);
	}
}

void xuatMangSoPhuc(SOPHUC* a, int n) {

	for (int i = 0; i < n; i++)
	{
		if (a[i].thuc != 0) {
			cout << a[i].thuc;
		}
		if (a[i].ao > 0) {
			if (a[i].ao == 1)  cout << " + i";

			else if (a[i].thuc == 0) {
				cout << a[i].ao << "i";
			}
			else cout << " + " << a[i].ao << "i";

		}
		else if (a[i].ao < 0) {
			if (a[i].ao == -1) cout << " - i";

			else cout << a[i].ao << "i";
		}
		cout << endl;
	}
}


SOPHUC* chen1SoPhuc(SOPHUC* a, int& n_ele) {
	cout << "\nNHAP SO PHUC MA BAN MUON CHEN VAO.";
	SOPHUC temp;
	nhapSOPHUC(temp);
	cout << "\nNHAP VI TRI BAN MUON CHEN VAO.";
	int pos = 0;
	do {
		cout << "\nNHAP VI TRI BAN MUON CHEN VAO.";
		cin >> pos;
		if (pos < 0 || pos >= n_ele) {
			cout << "\nBAN VUA NHAP SAI.HAY NHAP LAI.";
		}
	} while (pos < 0 || pos >= n_ele);
	int n = n_ele + 1;
	SOPHUC* anew = new(std::nothrow) SOPHUC[n];
	if (!anew) {
		cout << "\nCAT PHAT LOI.";
		return nullptr;
	}
	if (pos == 0) {
		*(anew) = temp;
		for (int i = 1, j = 0; j < n_ele; j++, ++i) {
			*(anew + i) = *(a + j);
		}
		n_ele++;
	}
	else if (pos != 0) {
		for (int i = 0; i < pos; i++) {
			*(anew + i) = *(a + i);
		}

		for (int i = pos, j = pos + 1; i < n_ele && j < n; i++, j++) {
			*(anew + j) = *(a + i);

		}
		*(anew + pos) = temp;
		n_ele++;
	}
	
	return anew;
}

SOPHUC* xoa1SoPhuc(SOPHUC* a, int& n_ele) {
	
	int pos = 0;
	do {
		cout << "\nNHAP VI TRI BAN MUON XOA : ";
		cin >> pos;
		if (pos < 0 || pos >= n_ele) {
			cout << "\nBAN VUA NHAP SAI.HAY NHAP LAI.";
		}
	} while (pos < 0 || pos >= n_ele);

	SOPHUC* anew = new (std::nothrow) SOPHUC[n_ele - 1];
	if (anew != nullptr) {
		if (pos == 0) {
			for (int i = 1; i < n_ele; i++) {
				anew[i - 1] = a[i];
			}
			n_ele--;
		}
		else if (pos != 0) {
			for (int i = 0; i < n_ele; i++) {
				anew[i] = a[i];
				if ( i>=pos) {
					anew[i] = a[i + 1];
				}
			}
			n_ele--;
		}
	}
	return anew;
}
