#include<iostream>
#include<fstream>
#include <stdint.h>
#include<string>
#include<cstdlib>

using namespace std;

struct COMPANYSTORE {
	int16_t ID;
	char NAME[100];// ta nen su dung char de dinh dang ro so byte.
	float Sale;
};

void readAndShow(const char* filename);

void writeFileBinary(COMPANYSTORE *a , int n);

int main() {
	COMPANYSTORE a[6];
	int n = 6;
	
	a[0] = { 100,"Lan",100 };
	a[1] = { 200,"Khang",100 };
	a[2] = { 100,"Lan",300 };
	a[3] = { 100,"van",400 };
	a[4] = { 300,"an",150 };
	a[5] = { 200,"Lan",250 };

	writeFileBinary(a, 6);
	
	readAndShow("D:\\filename.bin");
	
	return 0;
}

void readAndShow(const char* filename) {
	//int nSize = 6;
	ifstream  ifs;
	ifs.open(filename, ios::binary );

	
	if (!ifs) {
		cout << "\nCan not open file! " << endl;
		return;
	}
	COMPANYSTORE *DS=(COMPANYSTORE*) malloc(sizeof(COMPANYSTORE));
	
	
	int i = 0;
	while (!ifs.eof()){
		ifs.read((char*)&DS[i], sizeof(COMPANYSTORE));
		if (ifs.good()) {
			cout << DS[i].ID << "\t" << DS[i].NAME << "\t" << DS[i].Sale << endl;
			// kiem no doc duoc , co loi hay khong ?
		}
		i++;
		int m = i + 1;
		COMPANYSTORE*DSNEW = (COMPANYSTORE*) realloc(DS, m* sizeof(COMPANYSTORE));
		if (DSNEW) {
			DS = DSNEW;
			DSNEW = nullptr;
		}
	}
	int nSize = i-1;
	
	for (int i = 0; i < nSize - 1; i++) {

		for (int j = i + 1; j < nSize; j++) {
			if (DS[i].ID == DS[j].ID) {
				DS[i].Sale += DS[j].Sale;
				for (int k = j; k < nSize; k++) {
					DS[i] = DS[k];
				}
				nSize--;
			    j--;
			}
		}
	}
	cout << "\nID \tNAME \tTOTAL SALES" << endl;
	for (int i = 0; i < nSize; i++) {
		cout << DS[i].ID << "\t" << DS[i].NAME << "\t" << DS[i].Sale << endl;
	}
	ifs.close();
	if (DS) {
		free(DS);
		DS = nullptr;
	}
	
}

void writeFileBinary(COMPANYSTORE *a, int n) {
	ofstream wf("D:\\filename.bin",  ios::binary | ios::out);
	if (!wf) {
		cout << "\nCannot open file " << endl;
		return;
	}
	
	for (int i = 0; i < n; i++) {
		wf.write((char*)&a[i], sizeof(COMPANYSTORE));
			
	}
	wf.close();

}
