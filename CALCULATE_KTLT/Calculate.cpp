#include<iostream>
#include<fstream>
#include<string>
#include<cmath>

using namespace std;

struct Stack {
	void* data;
	Stack* next;
};

typedef struct Stack* Ref;

int isEmty(Stack* top);

Ref newNode(void* val, int dSize);

void push(Stack*& top, void* val, int dSize);

char pop(Stack*& top);

void convertInfixtoPostfix(string r_arr, Stack*& top, fstream& w_file);

int Priority(char r_val);

void calculatePostfixt(fstream& r_file, fstream& w_file);

int convertChartoInt(char* r_Ch);


int main(int argc, char* argv[]) {

	Stack* top = nullptr;
	fstream filein(argv[2], ios_base::in);
	if (!filein)
		cout << "\nCAN NOT OPEN  FILEIN.";
	else
	{
		fstream fileout(argv[3], ios_base::out);
		if (!fileout)
			cout << "\nCAN NOT OPEN FILEOUT.";
		else
		{

			string arr;
			if (argv[1][1] == 'i')
			{
				fstream temp1("D:\\19120720\\POSTFIX.txt", ios::out);

				if (!temp1) {
					cout << "\nERROR OPEN FILE !";
					return -1;
				}
				getline(filein, arr);
				convertInfixtoPostfix(arr, top, temp1);
				temp1.close();

				fstream temp2("D:\\19120720\\POSTFIX.txt", ios::in);

				if (!temp2) {
					cout << "\nERROR OPEN FILE!";
					return -1;
				}
				calculatePostfixt(temp2, fileout);
				temp2.close();
			}
			else
			{
				calculatePostfixt(filein, fileout);
			}

			fileout.close();
		}
		filein.close();

	}

	return 0;
}

int isEmty(Stack* top)
{
	return top == nullptr;
}

Ref newNode(void* val, int dSize) {
	Ref temp;
	temp = (Ref)malloc(sizeof(struct Stack));
	if (temp == NULL) {
		cout << "\nHeap Overflow !";
		exit(0);
	}
	temp->data = new(std::nothrow) char[dSize];
	if (!temp->data) {
		cout << "\nError Memory !";
		return nullptr;
	}
	temp->next = nullptr;
	if (temp->data == nullptr) {
		free(temp);
		return nullptr;
	}
	memcpy(temp->data, val, dSize);
	return temp;
}

void push(Stack*& top, void* val, int dSize) {

	if (val == nullptr) return;
	Ref temp = newNode(val, dSize);
	if (temp) {
		temp->next = top;
		top = temp;
	}
}

char pop(Stack*& top) {
	Stack* temp;
	if (top == nullptr) {
		cout << "\nStack Underflow !" << endl;
	}
	else {
		temp = top;
		char val = *(char*)top->data;
		top = top->next;
		temp->next = nullptr;
		if (temp->data) {
			delete[](char*)temp->data;
		}
		free(temp);
		temp = nullptr;
		return val;
	}
	return NULL;
}

void convertInfixtoPostfix(string r_arr, Stack*& top, fstream& w_file) {
	/*
	 ham doi tu trung to sang hau to
	*/
	int i = 0;
	string str;
	int len_arr = r_arr.length();
	while (i < len_arr) {
		char temp = r_arr[i];
		if (temp != ' ') {
			if ((0 <= temp - '0' && temp - '0' <= 9)){
				/*
				Truong hop su li cho so nguyen duong.
				*/
				str += temp;
			}
			else if (temp == '-' && (i == 0 || r_arr[i - 1] == '-' || r_arr[i - 1] == '+' || r_arr[i - 1] == '*' || r_arr[i - 1] == '/' || r_arr[i - 1] == '(' || r_arr[i - 1] == '^')) {
				/*
				Truong hop nay xu li cho so nguyen am.
				*/
				str += temp;
			}
			else {
				w_file << str << " ";
				str = "";
				if (temp == '(') {
					push(top, &temp, sizeof(char));
				}
				else {
					if (temp == ')') {
						while (*(char*)top->data != '(') {
							w_file << *(char*)top->data;
							pop(top);
						}
						pop(top);
					}
					else {
						while (!isEmty(top) && Priority(temp) <= Priority(*(char*)top->data)) {
							w_file << *(char*)top->data << " ";
							pop(top);
						}
						push(top, &temp, sizeof(char));
					}
				}
			}
		}
		i++;
	}
	if (str != "") w_file << str << " ";

	while (!isEmty(top)) {
		w_file << pop(top);
		//den day toan bo du lieu trong stack da duoc pop ra ngoai.
	}
}

int Priority(char r_val) {

	//do uu tien cua cac toan tu.

	if (r_val == '(' || r_val == ')') return 0;
	else if (r_val == '+' || r_val == '-') return 1;
	else if (r_val == '*' || r_val == '/') return 2;
	else if (r_val == '^') return 3;
	else return 4;
}

void calculatePostfixt(fstream& r_file, fstream& w_file) {
	/*
	Tinh toan hau to.
	*/

	Stack* top = nullptr;
	string str;
	string temp;
	getline(r_file, str);

	int j = 0;
	int len_str = str.length();
	for (int i = 0; i < len_str; i++) {

		int flag = 0;
		if ((0 <= str[i] - '0' && str[i] - '0' <= 9) || (str[i] == '-' && '0' <= str[i + 1] && str[i + 1] <= '9')) {
			if (str[i] == '-')
			{
				flag = 1;
				i++;
			}
			j = i + 1;
			while (str[j] != ' ') {
				j++;
			}
			temp = str.substr(i, j - i); // cat chuoi con tu vi tri i voi so phan tu la : j-i.

			double num = convertChartoInt((char*)temp.c_str());
			if (flag == 1) {
				//truong hop nay de xu li cho so am.
				num = -num;
			}
			push(top, &num, sizeof(double));
			num = 0;
			i = j;
			temp = "";
		}
		else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '^') {
			double a = 0;
			double b = 0;
			if (top) {
				a = *(double*)top->data;
				pop(top);
			}
			if (top) {
				b = *(double*)top->data;
				pop(top);
			}
			double result = 0;

			if (str[i] == '+') result = a + b;
			else if (str[i] == '-')result = b - a;
			else if (str[i] == '*')result = a * b;
			else if (str[i] == '/')result = b / a;
			else if (str[i] == '^')result = pow(b, a);
			push(top, &result, sizeof(double));
		}
	}
	if (top) {
		w_file << *(double*)top->data;
		delete[](char*)top->data;
		free(top);
		top = nullptr;
	}
}

int convertChartoInt(char* r_Ch) {
	/*
	Doi so tu ki tu sang so nguyen.
	*/

	int result = 0;
	int len_r_ch = strlen(r_Ch);
	for (int i = strlen(r_Ch) - 1, j = 0; i >= 0; i--, j++) {
		result += int(int(r_Ch[i] - 48) * pow(10, j));
	}
	return result;
}