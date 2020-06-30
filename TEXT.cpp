#include<iostream>
#include<string>


using namespace std;

struct Subject {
	float math;
	float physics;
	float chemistry;
	float medium;
};

struct Student {
	char ID[20] = "0";
	string name;
	string date_of_birth;
	Subject sub;
};

void input_Array(Student*& a, int  ele);

void output_Array(Student* a, int ele);

string nameOfStudent(string a);

void sortName(Student*& a, int ele);

bool compareName(char* a, char* b);

void sortMediumScore(Student*& a, int ele);

void sortMathScore(Student*& a, int n_ele);

bool isSubString(char* src, char* dest);

void searchIDOfStudent(Student* a, int n_ele);

char* stranferArray(char* src);

void searchNameOfStudent(Student* a, int n_ele);

void addStudent(Student*& a, int& n_ele);



int main() {
	Student* a = nullptr;
	int n_ele = 0;
	cout << "ENTER THE NUMBER OF STUDENTS : ";
	cin >> n_ele;
	a = new (std::nothrow) Student[n_ele];
	if (!a) {
		cout << "\nERROR MEMORY. " << endl;
		return 0;
	}
	int temp = 1;
	int sel = 0;
	input_Array(a, n_ele);
	cout << " THE ARRAY JUST ENTERED. " << endl;
	output_Array(a, n_ele);
	while (temp != 0) {
		cout << "FRESS 1 SORTNAME." << endl;
		cout << "FRESS 2 SORTMEDIUM." << endl;
		cout << "FRESS 3 SEARCHSTUDENTBYID." << endl;
		cout << "FRESS 4 SEARCHSTUDENTBYNAME." << endl;
		cout << "FRESS 5 ADDSTUDENT." << endl;
		cin >> sel;

		switch (sel) {
		case 1:
			sortName(a, n_ele);
			cout << "ARRAYS AFTER SORTED BY NAME (ALPHABET). " << endl;
			output_Array(a, n_ele);
			break;
		case 2:
			sortMediumScore(a, n_ele);
			cout << " ARRAYS AFTER SORTED BY ID (ALPHABET). " << endl;
			output_Array(a, n_ele);
			break;
		case 3:
			searchIDOfStudent(a, n_ele);
			break;
		case 4:
			searchNameOfStudent(a, n_ele);
			break;
		case 5:
			addStudent(a, n_ele);
			cout << "\nARRAY AFTER ADDED ELEMENTS." << endl;
			output_Array(a, n_ele);
		}
		cout << " DO YOU WANT CONTINUE ?  \t YES 1 \tNO 0 " << endl;
		cin >> temp;
		cout << endl;
	}
	delete[]a;
	a = nullptr;
	/*string a = "VINH";
	  
	 char *b=stranferArray( (char*) a.c_str());
	 for (int i = 0; i < a.size(); i++)
		 cout << b[i];
	system("pause");*/
	/*char a[10] = "cuong";
	char c[10] = "canh";
	cout<<" the result "<<compareName(a, c);*/
	return 0;
}

void input_Array(Student*& a, int ele) {

	// su dung getline de nhap vao cac gia tri cua sinh vien 

	for (int i = 0; i < ele; i++) {
		cout << "\nEnter ID : ";
		cin >> a[i].ID;
		cout << "\nEnter name : ";
		cin.ignore();
		getline(cin, a[i].name);
		cout << "\nEnter date of birth : ";
		getline(cin, a[i].date_of_birth);
		cout << "\nEnter math score : ";
		cin >> a[i].sub.math;
		cout << "\nEnter physics score : ";
		cin >> a[i].sub.physics;
		cout << "\nEnter chemistry score : ";
		cin >> a[i].sub.chemistry;
		a[i].sub.medium = (a[i].sub.math + a[i].sub.physics + a[i].sub.chemistry) * 1 / 3;
	}
}

void output_Array(Student* a, int ele) {
	// xuat danh sach sinh vien ra man hinh console 
	for (int i = 0; i < ele; i++) {
		cout << "----------------  " << "0" << i << "  ----------------";
		cout << "\nID : " << a[i].ID;
		cout << "\nName : " << a[i].name;
		cout << "\nDate of birth : " << a[i].date_of_birth;
		cout << "\nMath score : " << a[i].sub.math;
		cout << "\nPhysics score : " << a[i].sub.physics;
		cout << "\nChemistry score : " << a[i].sub.chemistry;
		cout << "\nMedium score : " << a[i].sub.medium;
		cout << endl;
	}
}

string nameOfStudent(string a) {
	// lay ten cua sinh vien tu chuoi ho va ten luc dau 
	int _len_a = a.length();
	int count = 0;
	int pos = 0;
	for (int i = _len_a - 1; i >= 0; i--) {
		count++;
		if (a[i] == ' ') {
			pos = i;
			break;
		}
	}
	string result = a.substr(pos + 1, count); // dung ham substr de copy ten cua chuoi a sang chuoi reSult 
	return result;
}
bool compareName(char* a, char* b) {
	int len_a = strlen(a);
	int len_b = strlen(b);
	int i = 0;
	bool flag = true;
	if ((int)a[i] > (int)b[i]) return false;
	else if ((int)a[i] < (int)b[i]) return true;
	else if (a[i] == b[i]) {
		while (i<len_a && i<len_b) {
			i++;
			if ((int)a[i] <(int) b[i]) {
				flag = true;
				break;
			}
			else if ((int)b[i] <(int)a[i]) {
				flag = false;
				break;
			}
		}
		return flag;
	}
	/*
	neu a dung truoc b thi xuat ra true
	neu a dung sau b thi xuat ra false
	*/
}

void sortName(Student*& a, int ele) {
	// sap xep danh sach sinh vien theo  ten
	for (int i = 0; i < ele; i++) {
		for (int j = i + 1; j < ele; j++) {
			if (!compareName((char*)nameOfStudent(a[i].name).c_str(), (char*)nameOfStudent(a[j].name).c_str())) {
				Student x = a[i];
				a[i] = a[j];
				a[j] = x;
			}	
		}
	}
}

void sortMediumScore(Student*& a, int ele) {
	// sap xep danh sach sinh vien theo diem trung binh
	for (int i = 0; i < ele - 1; i++) {
		for (int j = i + 1; j < ele; j++) {
			if (a[i].sub.medium < a[j].sub.medium) {
				Student temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}

void sortMathScore(Student*& a, int n_ele) {
	for (int i = 0; i < n_ele - 1; i++)
	{
		for (int j = i + 1; j < n_ele; j++) {
			if (a[i].sub.math < a[j].sub.medium) {
				Student temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}

bool isSubString(char* src, char* dest) {
	/*
	ta xet src[i+length_dest-1]= dest[length_dest-1] && src[i]=dest[0]
	sau đo kiem tra xem cac phan tu ben trong co sai hay khong
	neu count == length_dest dieu do nghia la dung va tra ve true ket thuc ham
	neu sai count =0 va thuc hien cho i tiep theo

	*/
	int length_src = strlen(src);
	int length_dest = strlen(dest);
	src = stranferArray(src);
	dest = stranferArray(dest);
	int count = 0;
	bool flag = false;
	for (int i = 0; i <= length_src - length_dest; i++) {
		if (src[i] == dest[0] && src[i + length_dest - 1] == dest[length_dest - 1]) {

			for (int j = i, t = 0; j < i + length_dest; j++, t++) {
				if (*(src + j) == *(dest + t)) {
					count++;
				}
				else {
					count = 0;
					break;
				}
				if (count == length_dest) {
					return true;
				}
			}
		}
	}
	return false;
}


void searchIDOfStudent(Student* a, int n_ele) {
	char MSSV[20];
	cout << "\nEnter ID of Student : ";
	cin >> MSSV;

	for (int i = 0; i < n_ele; i++) {
		if (isSubString(a[i].ID, MSSV)) {
			output_Array((a + i), 1);
			break;
		}
	}
}

char* stranferArray(char* src) {
	for (int i = 0; i < strlen(src); i++) {
		if ('A' <= src[i] && src[i] <= 'Z') {
			src[i] += 32;
		}
	}
	return src;
}

void searchNameOfStudent(Student* a, int n_ele) {
	string name;
	cout << "\nEnter name of student : ";
	getchar();
	getline(cin, name);
	for (int i = 0; i < n_ele; i++) {
		if (isSubString((char*)a[i].name.c_str(), (char*)name.c_str())) {
			output_Array((a + i), 1);
		}
	}
}

void addStudent(Student*& a, int& n_ele) {

	cout << "\nEnter number of students to add : ";
	int n = 0;
	cin >> n;
	n_ele += n;
	Student* temp = new(std::nothrow) Student[n];
	// kiem tra temp duoc cap phat thanh cong hay chua 
	if (!temp) {
		cout << "\nError Memory ";
		return;
	}
	input_Array(temp, n);

	Student* anew = new(std::nothrow) Student[n_ele];
	// kiem tra anew duoc cap phat thanh cong hay chua 
	if (!anew) {
		cout << "\nError memory ";
		return;
	}
	// chep cac gia tri cua mang a sang mang moi anew 
	for (int i = 0; i < n_ele - n; i++) {
		anew[i] = a[i];
	}
	delete[] a;
	a = nullptr;
	// them cac gia tri cua mang temp sang mang moi anew
	for (int i = n_ele - n, j = 0; j < n; i++, j++) {
		anew[i] = temp[j];
	}
	delete[] temp;
	temp = nullptr;
	a = new Student[n_ele];

	for (int i = 0; i < n_ele; i++) {
		a[i] = anew[i];
	}
	delete[] anew;
	anew = nullptr;
}
