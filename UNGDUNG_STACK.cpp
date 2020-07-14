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

void push (Stack*& top, void * val , int dSize);

char pop(Stack*& top);

void convertInfixtoPostfix(string r_arr, Stack*& top, ofstream& w_file);

int Priority(char r_val);

void calculatePostfixt(ifstream& r_file, ofstream& w_file);

int convertChartoInt(char* r_Ch );


int main() {
	Stack* top = nullptr;
	ifstream filein("INPUT.TXT");
	ofstream fileout("OUTPUT.TXT", ios_base::out);
	string arr ;
	getline(filein ,arr);
	convertInfixtoPostfix(arr, top,fileout);
	filein.close();
	fileout.close();
	ifstream file("OUTPUT.TXT");
	ofstream f_Out("KETQUA.TXT", ios_base::out);
	calculatePostfixt(file, f_Out);
	file.close();
	f_Out.close();
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

void push (Stack*& top, void * val , int dSize) {
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

void convertInfixtoPostfix(string r_arr, Stack*& top, ofstream& w_file) {
	/*
	 ham doi tu trung to sang hau to 
	*/
	int i = 0;
	string str;
	int len_arr = r_arr.length();
	while (i <len_arr) {
		char temp = r_arr[i];
		if (temp != ' ') {
			if (0 <= temp - '0' && temp - '0' <= 9) {
				str += temp;
			}
			else {
				w_file << str << " ";
				str = "";
				if (temp == '(') {
					push(top,&temp,sizeof(char));
				}
				else {
					if (temp == ')') {
						while (*(char*)top->data != '(') {
							w_file <<*(char*)top->data;
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
	}
}

int Priority(char r_val) {
	if (r_val == '(' || r_val == ')') return 0;
	else if (r_val == '+' || r_val == '-') return 1;
	else if (r_val == '*' || r_val == '/') return 2;
	else if (r_val == '^') return 3;
	else return 4;
}

void calculatePostfixt(ifstream& r_file, ofstream& w_file) {
	Stack *top=nullptr;
	string str;
	string temp;
	getline(r_file, str);
	
	int j = 0;
	int len_str = str.length();
	for (int i = 0; i <len_str; i++) {
			if (0 <= str[i] - '0' && str[i] - '0' <= 9) {
				j = i + 1;
				while (str[j] != ' ') {
					j++;
				}
				temp = str.substr(i, j -i);
			    double num = convertChartoInt((char*)temp.c_str());
				push(top, &num, sizeof(double));
				num = 0;
				i = j;
				temp = "";
			}
			else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '^') {
				double a=0;
				double b=0;
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
				else if (str[i] == '^')result = pow(b,a);
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
	int result = 0;
	int len_r_ch = strlen(r_Ch);
	for (int i = strlen(r_Ch) - 1 ,j = 0 ;i >= 0; i--, j++) {
		result += ((double)(r_Ch[i]) -48) * pow(10, j);
	}
	return result;
}