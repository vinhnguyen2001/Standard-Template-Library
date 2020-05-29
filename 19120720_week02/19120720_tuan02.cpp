#include<iostream>
#include<fstream>
#include<malloc.h>
#include<string>

using namespace std;

struct phanso {
	int num;
	int deno;
 };
typedef phanso PHANSO;

istream& operator>>( istream& inDev, PHANSO &p) {
	inDev >> p.num >> p.deno;
	return inDev;
}

ostream& operator << (ostream& outDev , phanso &p) {
	if (p.deno < 0){
		p.num = -p.num;
		p.deno = -p.deno;
	}
	if (p.deno == 1 || p.num == 0)
		outDev << p.deno;
	else outDev << p.num << " " << p.deno;
	return outDev;
} 
phanso* inPutArray(istream& inDev, int& n);//HAM THUOC CAU3 

void sortUpAscending(phanso& p1, phanso& p2); //HAM THUOC CAU3

void insertFraction(phanso*& a, int& n, phanso x);// HAM THUOC CAU3

void sortUpAcsendingArray(ostream& outDev, phanso*& a, int n); // CAU 3

void copiFile(ifstream& filein, ofstream& fileout);//CAU2

void insertElement(int*& arr, int& n, int x);// HAM THUOC CAU3

void countOccurrences1(ifstream& filein, ofstream& fileout);//CAU4

void replaceChar (fstream& filein);//CAU1

void defineFraction(phanso& p);

int main() {




	int sel=0;
	
	int flag = 1;
	while (flag == 1) {
		cout <<"Fress 1. to replace old character with new character in a file " << endl;
		cout << "Fress 2. to copy one file to another " << endl;
		cout << "Fress 3. to sort in ascending order and copy to another file " << endl;
		cout << "Fress 4. to find the number of occurence of the character in a line " << endl;
		cin >> sel;
	switch (sel) {
		case 1:
		{
			fstream file("baitap1.txt", ios::in | ios::out);
			if (!file)
				cout << " \nCan't open this file baitap.txt" << endl;
			replaceChar(file);
			file.close();
		}
		break;
		case 2:
		{
			ifstream filein2("input2.txt");
			ofstream fileout2("output2.txt");
			if (!filein2)
				cout << " \nCan't open this file input2.txt" << endl;
			if (!fileout2)
				cout << "\nCan't open this file output2.txt" << endl;
			copiFile(filein2, fileout2);
			filein2.close();
			fileout2.close();
		}
		break;
		case 3:
		{
			ifstream filein3("input3.txt");
			ofstream fileout3("output3.txt");
			if (!filein3)
				cout << " \nCan't open this file input3.txt" << endl;
			if (!fileout3)
				cout << "\nCan't open this file output3.txt" << endl;
			phanso* a3;
			int n3;
			a3 = inPutArray(filein3, n3);
			sortUpAcsendingArray(fileout3, a3, n3);
			free(a3);
			a3 = nullptr;
			filein3.close();
			filein3.close();
		}
		break;
		case 4:
		{
			ifstream filein4("input4.txt");
			ofstream fileout4("output4.txt");
			if (!filein4)
				cout << " \nCan't open this file input4.txt" << endl;
			if (!fileout4)
				cout << "\nCan't open this file output4.txt" << endl;
			countOccurrences1(filein4, fileout4);
		}
	 }
	cout << "\Do you want continue ? " << "\t" << " YES 1." << "\t NO 0." << endl;
	cin >> flag;
}
	return 0;

}

void insertFraction(phanso*& a, int& n, phanso x) {
	// ham chan 1 phan tu 
	int m = n + 1;
	phanso* anew = (phanso*)realloc(a, m * sizeof(phanso));
	if (anew != NULL) {
		anew[n].num = x.num;
		anew[n].deno = x.deno;
		n++;
		a = anew;
	}
}

phanso* inPutArray(istream& inDev, int& n) {
	//ham nhap mang cac  phan so 
	phanso x;
	PHANSO* array = NULL;
	n = 0;
	while (inDev >> x) {
		insertFraction(array, n, x);
	}
	return array;
}

void defineFraction(phanso& p) {
	// dinh nghia lai phan so dang : -a / b va a / b
	if (p.deno < 0) {
		p.num = -p.num;
		p.deno = -p.deno;
	}
}
void sortUpAscending(phanso& p1, phanso& p2) {
	// ham sap xep phan so tang dan 

	defineFraction(p1);
	defineFraction(p2);
	float temp_1 =(float) p1.num * p2.deno;
	float temp_2 =(float) p2.num * p1.deno;
	if (temp_1 > temp_2) {
		swap(p1, p2);
	}
}

void sortUpAcsendingArray(ostream& outDev, phanso*& a, int n) {
	// ham sap xep phan so tang dan trong 1 mang 
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++)
			sortUpAscending(a[i], a[j]);

	}
	// tien hanh ghi file 
	for (int t = 0; t < n; t++) {
		outDev << a[t] << endl;
	}
}

void copiFile(ifstream& filein, ofstream& fileout) {
	string k;
	while (getline(filein, k)) {
		fileout << k << endl;
	}
}

void insertElement(int*& arr, int& n, int x) {
	//ham chen phan tu
	int m = n + 1;
	int* anew = (int*)realloc(arr, m * sizeof(int));
	if (anew != NULL) {
		anew[n] = x;
		n++;
		arr = anew;
	}
}

void countOccurrences1 (ifstream& filein, ofstream& fileout) {
	string  k;
	int count = 0;
	int* array = nullptr;
	int n = 0;
	string knew;
	while (getline(filein, knew)) {
		k += knew;
	}
	string s = k;

	{   // ghi so lan xuat hien cua cac phan tu trong mang k vao mang array 
		// xoa phan tu trung cua mang s
		for (int i = 0; i < s.size() - 1; i++)
			for (int j = i + 1; j < s.size(); j++)
				if (s[i] == s[j] || s[j] == ' ')
				{
					s.erase(s.begin() + j);
					j--;
				}
		for (int i = 0; i < s.size(); i++) {
			count = 0;
			for (int j = 0; j < k.size(); j++) {
				if (s[i] == k[j])
					count++;

			}
			insertElement(array, n, count);
		}
		//ghi vao fileout
		for (int i = 0; i < s.length(); i++) {

			fileout << s[i] << ":" << array[i] << endl;
		}
		free(array);
		array = nullptr;
	}
}

void replaceChar(fstream& filein) {
	// cau 1: ham thay the ki tu cu bang ki tu moi
	char ch;
	char k;
	string l;
	string lnew;
	cout << " Enter the character you want to replace " << endl;
	cin.ignore();
	cin.get(k);
	cout << " Enter the new character " << endl;
	char knew;
	cin.ignore();
	cin.get(knew);
	while (filein.get(ch)) {
		if (ch == k) {
			int pos = filein.tellg();
			pos--;
			filein.seekp(pos);
			filein.put(knew);
			filein.seekg (pos + 1);
		}
	}

}