#include<iostream>
#include<string>

using namespace std;

int stringLength(char* s);

char* stringNCopy(char* dest, char* src, int numChars);

void CopySubString(char* dest, char* src, int startPos, int numChars);

char* stringCopy(char* dest, char* src);

void InsertSubString(char* str, char* substr, int startPos);

void deleteSubString(char* src, int  startPos, int numChars);

int findSubString (char* src, char* dest, int pos);

bool isSubString(char* src, char* dest);

int countMatches(char* src, char* dest);

int main() {
	// H E L L O   W O R L D
	// 0 1 2 3 4 5 6 7 8 9 10

	char src[100];// = "HELLO WORLD";
	
	
	cout << "Enter the string to check " << endl;
	cin.getline(src, 257);
	int len_src = stringLength(src);


	int sel = 0;
	int n = 1;
	while (n != 0) {
		cout << "\nFRESS 1. EXCERCISE 1";
		cout << "\nFRESS 2. EXCERCISE 2";
		cout << "\nFRESS 3. EXCERCISE 3";
		cout << "\nFRESS 4. EXCERCISE 4";
		cout << "\nFRESS 5. EXCERCISE 5";
		cout << "\nFRESS 6. EXCERCISE 6" << endl;
		cin >> sel;
		switch (sel) {
		case 1:
		{
			int num_1 = 0;
			cout << "\nEnter the number of character to copy : " << endl;
			cin >> num_1;
			cout << "\nEnter where to start copying :";
			int startPos = 0;
			cin >> startPos;
			char* a = new char[num_1 + 1]; 
			if(a!=NULL){
		//	stringNCopy(a, src, num_1);
		//	cout << " \nCharacter string after copied :" << a;
			CopySubString(a, src, startPos, num_1);
			cout << " \nString after copied from position " << startPos << " : " << endl << a;

			delete[] a;
			a = nullptr;
			}
		
			break;
		}
		case 2:
		{
			char* b = new char[len_src + 1];
			char b1[100];
			cout << "\nEnter the position you want to insert :";
			int posb = 0;
			cin >> posb;

			cout << "\nEnter the string you want to insert :";
			cin.ignore();
			cin.getline(b1, 100);

			if (b != NULL) {
				stringCopy(b, src);
				cout << " \nThe string has been copied : " << b;
				InsertSubString(src, b1, posb);
				cout << " \nThe string has been insert : " << src;
				delete[]b;
				b = nullptr;
			}
			break;
		}
		case 3:
		{
			cout << "\nEnter the location to start deleting :";
			int posDet = 0;
			cin >> posDet;
			cout << "\nEnter the quantity to delete :";
			int numDet = 0;
			cin >> numDet;
			deleteSubString(src, posDet, numDet);
			cout << "\nThe String has been deleted : " << src;
			break;
		}
		case 4:
		{
			char d[100];
			cout << "\nEnter the positon you start to searching :";
			int posSea = 0;
			cin >> posSea;
			cout << "\nEnter the string you are looking for : ";
			cin.ignore();
			cin.getline(d, 100);
			int temp = findSubString(src, d, posSea);
			if (temp != -1)
				cout << "\The first position of the string you are searching for is " << temp;
			else cout << "\nThe string you searched for does not appear in the source string ";
			break;
		}
		case 5:
		{
			char e[100];
			cout << "\nEnter the string you are looking for : ";
			cin.ignore();
			cin.getline(e, 100);

			if (isSubString(src, e))
				cout << "\nThe string you entered exists ";
			else if (!isSubString(src, e))
				cout << "\nThe string you enteread unexists ";
			break;
		}
		case 6:
		{
			char G[100];
			cout << "\nEnter the substring you want to check :";
			cin.ignore();
			cin.getline(G, 100);
			cout << "\nNumber of occurrences of substring : " << countMatches(src, G);
			break;
		}
		}
		
		cout << "\nDO you want to continue ?" << "\tYES 1" << "\tNO 0" << endl;
		cin >> n;
	
	}
	return 0;
}

int stringLength(char* s) {
	// dem do dai cua chuoi ki tu 
	int i = 0;
	while (s[i] != '\0') {
		i++;
	}
	return i;
}
// CAU 1
char *  stringNCopy (char * dest, char* src, int numChars) {
	// copy numChars ki tu cua mang chinh va tra ve vi tri cua mang dest  
	// vi tri copy la dau chuoi 
	int len_src = stringLength(src);
	int i=0;
	
	if (dest != NULL) {
		if (numChars <= len_src)
		{
			for (; i <  numChars; i++) {
				*(dest + i) = *(src + i);
			}
			*(dest+i) = '\0';
			return dest;
		}
	}
}

void CopySubString(char* dest, char* src, int startPos, int numChars) {
	stringNCopy(dest, src + startPos, numChars);
}

// CAU 2

char* stringCopy(char* dest, char* src) {
	int len_src = stringLength(src);

	int i=0;
	if (dest != NULL) {
		for (; i < len_src; i++) {
			*(dest + i) = *(src + i);
		}
		*(dest + i) = '\0';
		return dest;
	}
}

void InsertSubString(char* str, char* substr, int startPos) {
	int length = stringLength(str);
	int sublength = stringLength(substr);
	char* temp;
	 if (startPos > length) startPos = length;
	 if (startPos < length) {
		 temp = new char[length - startPos + 1];
		 stringCopy(temp, str + startPos);
		 stringCopy(str + startPos, substr);
		 stringCopy(str + startPos + sublength, temp);
		 delete[] temp;
	
	 }
	 else stringCopy(str + startPos, substr);

}

//CAU 3

void deleteSubString(char* src, int  startPos , int numChars) {
	// xoa numChars phan tu cua mang tu vi tri startPos 
	int len_src = stringLength(src);
	int i=startPos;
	int j = startPos + numChars;
	if (startPos > len_src) startPos = len_src;
	if (startPos < len_src) {
		while (j < len_src) {
			src[i] = src[j];
			i++;
			j++;
		}
		src[i] = '\0';
	}
}

//CAU 4
int findSubString(char* src, char* dest, int pos) {
	bool flag = false;
	int len_rest = stringLength(dest);
	int len_src = stringLength(src);
	int firstPos = pos;
	if (isSubString(src, dest) == true) {
	
		for (int i = pos; i < len_src; i++) {
			if (src[i] == dest[0])
			{
				flag = true;
				firstPos = i;
				break;
			}
		}
	}
	if (flag == true) return firstPos;
	else if( flag==false) return -1;
}

// CAU 5
bool isSubString (char* src, char* dest) {
	// kiem tra mang con cos xuat hien trong mang chinh hay khong
	int len_dest = stringLength(dest);
	int len_src = stringLength(src);
	int flag = true;
	int count = 0;

	int flag_2 = false;
	if (len_dest <= len_src) {
		for (int i = 0; i <= len_src - len_dest; i++) {
			if (src[i] == dest[0] && src[i + len_dest - 1] == dest[len_dest - 1])
			{
				flag_2 = true;
				int t = 0;
				for (int j = i; j < (i + len_dest - 1); j++, t++) {
					if (*(src + j) != *(dest + t)) {
						flag = false;
						break;

					}
				}
				if (flag == true) {
					break; // neu flag==true tuc la cac ki tu trong mang con se xuat hien tat ca trong mang chinh 
				}          // ma khong khac bat cu ki tu nao
			}

		}
		if (flag_2 == true)
		{
			if (flag == false) return false;
			else return true;
		}
		else return false;
	}
	else
		cout << " The string entered is not valid  " << endl;
}

//CAU 6
int countMatches(char* src, char* dest) {
	// dem so lan xuat hien cua mang con trong mang chinh 
	int len_dest = stringLength(dest);
	int len_src = stringLength(src);
	int flag = true;
	
	int count = 0;
	for (int i = 0; i <= len_src - len_dest; i++) {
	    int flag_3 = false;
		if (src[i] == dest[0] && src[i + len_dest - 1] == dest[len_dest - 1]){
			int t=0;
			flag_3 = true;
			for (int j = i; j < (i + len_dest - 1); j++, t++) {
				if (*(src + j) != *(dest + t)) {
					flag = false;
					break;
				}
			}
		}
		if (flag_3 == true && flag==true) {
			count++;
		}
	}
	return count;
}
