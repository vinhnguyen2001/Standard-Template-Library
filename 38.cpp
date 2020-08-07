#include<iostream>

using namespace std;

struct Snode {
	int data;
	Snode* pnext;
};

struct Slist {
	Snode* head;
	Snode* tail;
};

void initialize(Slist*& w_list);

bool isEmty(const Slist* r_list);

int lengthList(Slist* r_list);

Snode* newNode(int val);

Snode* pushBack(Slist*& u_list, int val);

void deleteAtPosition(Slist*& u_list, int pos);

void popBack(Slist*& u_list);

void printList(Slist* r_list);

int sumEvenNumber(Slist* r_list, int sum ,int n);

int sumEvenNumbers(Snode* cur, int sum);

Snode* findMaxValue(Slist* r_list, int n, Snode *& max);

void reserveLinkedList(Slist*& u_list, int n, int i);

Snode* reserveList(Slist*& u_list, Snode* temp);

Snode* findValue(Slist* r_list, int value, int n);

void directInsertion(Slist*& u_list, int n);

void destroyList(Slist*& u_list);

int main() {
	Slist* list = nullptr;
	initialize(list);
	int val = 0;
	int _nsize = 0;

	cout << "\nNHAP SO PHAN TU CUA DANH SACH : ";
	cin >> _nsize;
	if (_nsize <= 0) {
		cout << "\nKHONG HOP LE.";
		return -1;
	}
	cout << "\nNHAP LUOT CAC PHAN TU CUA DANH SACH." << endl;
	for (int i = 0; i < _nsize; i++) {
		cin >> val;
		pushBack(list,val);
	}
	int n = lengthList(list);
	cout << "\nDANH SACH BAN VUA NHAP : " << endl;
	printList(list);
	cout << endl;
	int contin = 1;
	int select = 0;
	while (contin) {
		cout << "NHAP 1.TINH TONG CAC PHAN CHAN CHAN TRONG DANH SACH.";
		cout << "\nNHAP 2.TIM PHAN TU LON NHAT TRONG DANH SACH.";
		cout << "\nNHAP 3.TIM PHAN TU CHO TRUOC TRONG DANH SACH.";
		cout << "\nNHAP 4.DAO DANH SACH.";
		cout << "\nNHAP 5.SAP XEP DANH SACH TANG DANH THEO PHUONG PHAP CHEN TRUC TIEP." << endl;
		cin >> select;
		switch (select) {
		case 1: {
			int sum = 0;
			cout << "\nTONG CUA CAC PHAN TU CHAN : " << sumEvenNumbers(list->head, sum);
			break;
		}
		case 2: {

			Snode* max = nullptr;
			findMaxValue(list, lengthList(list), max);
			cout << "GIA TRI LON NHAT : " << max->data << endl;
			break;
		}
		case 3: {
			int value;
			cout << "\nNHAP GIA TRI CAN TIM TRONG DANH SACH : ";
			cin >> value;
			Snode* temp = findValue(list, value, n);
			if (temp == nullptr) {
				cout << "\nGIA TRI BAN TIM KHONG CO TRONG DANH SACH !";
			}
			break;
			
		}
		case 4: {
			int i = 0;
			//reserveLinkedList(list, n, i);
			Snode* temp_4 = list->head;
			reserveList(list,temp_4);
			cout << "\nDANH SAU  DUOC DAO THANH CONG." << endl;
			printList(list);
			break;
		}
		case 5: {
			directInsertion(list, n);
			cout << "\nDANH DA DUOC SAP XEP TANG DAN THANH CONG." << endl;
			printList(list);
		}
		}
	    cout << " \nBAN MUON TIEP TUC KHONG ? \tCO.1 \tKHONG.0 " << endl;
		cin >> contin;
		cout << endl;
	}
	destroyList(list);
	return 0;
}

void initialize(Slist*& w_list) {
	w_list = new (std::nothrow) Slist;
	if (!w_list) {
		cout << "\nError Memory !";
		return;
	}
	(w_list)->head = nullptr;
	(w_list)->tail = nullptr;
}

bool isEmty(const Slist* r_list) {

	// kiem tra danh sach rong hay khong.

	if (r_list->head == nullptr) {
		return true;
	}
	return false;
}

int lengthList(Slist* r_list) {
	//tinh do dai cua danh sach.

	Snode* temp = r_list->head;
	int count = 0;
	while (temp) {
		count++;
		temp = temp->pnext;
	}
	return count;
}

Snode* newNode(int val) {

	//tao 1 node moi .

	Snode* node = new(std::nothrow) Snode;
	if (!node) {
		cout << "\nError Memory !";
		exit(0);
	}
	node->data = val;
	node->pnext = nullptr;
	return node;
}


Snode* pushBack(Slist*& u_list, int val) {

	//chen phan tu vao cuoi danh sach.

	Snode* node = newNode(val);
	if (isEmty(u_list)) {
		u_list->head = u_list->tail = node;
	}
	else {
		u_list->tail->pnext = node;
		u_list->tail = node;
	}
	return u_list->head;
}

void deleteAtPosition(Slist*& u_list, int pos) {

	// xoa phan tu o vi nao do trong danh sach ( tru dau danh sach & cuoi danh sach ).

	if (u_list->head == nullptr) return;
	if (u_list->head == u_list->tail) {
		delete u_list->head;
		delete[]u_list;
		u_list = nullptr;
		return;
	}
	Snode* temp = u_list->head;
	for (int i = 0; i < pos; i++, temp = temp->pnext);
	if (temp->pnext == u_list->tail) {
		u_list->tail = temp;
	}
	Snode* r = temp->pnext;
	*temp = *r;
	delete[] r;
	r = nullptr;
}

void popBack(Slist*& u_list) {

	// lay phan tu cuoi danh sach.

	if (u_list->head == nullptr) return;
	if (u_list->head == u_list->tail) {
		delete u_list->head;
		delete[]u_list;
		u_list = nullptr;
		return;
	}
	Snode* temp = u_list->head;
	for (; temp->pnext != u_list->tail; temp = temp->pnext);
	delete[]u_list->tail;
	temp->pnext = nullptr;
	u_list->tail = temp;
}

void printList(Slist* r_list) {
	Snode* temp = r_list->head;
	for (; temp; temp = temp->pnext) {
		cout << temp->data << "  ";
	}
}

int sumEvenNumber(Slist* r_list, int sum ,int n) {
	/*
	Tinh tong cac so chan trong mang :
	+ neu mang co cac so chan thi du lieu tra ve la tong cua cac so chan.
	+ nguoc lai thi tra ve 0.
	
	*/
	
	//static int sum = 0;
	if (n > 0) {
		int count = 0;
		Snode* temp = r_list->head;
		while (count != n - 1) {
			count++;
			temp = temp->pnext;
		}
		if (temp->data % 2 == 0) {
			sum += temp->data;
		}
	}
	else return sum;
	return sumEvenNumber(r_list,sum, n - 1);

}
int sumEvenNumbers(Snode* cur, int sum) {
	if (cur == nullptr) return sum;
	
	if (cur->data % 2 == 0) {
			sum += cur->data;
		}
	return sumEvenNumbers(cur->pnext, sum);

	
}
Snode* findMaxValue(Slist* r_list, int n, Snode*& max) {
	/*
	Tim phan tu lon nhat trong mang & du lieu tra ve la vi tri cua phan tu do 

	*/
	if (n == 2) {
		if (r_list->head->data > r_list->head->pnext->data) {
			return r_list->head;
		}
		else return r_list->head->pnext;
	}
    max = findMaxValue(r_list, n - 1, max);
	int count = 0;
	Snode* temp = r_list->head;
	while (count != n-1 ) {
		count++;
		temp = temp->pnext;
	}
	if (max->data  < temp->data ) {
		max = temp;
	}
	 return max;
}

void reserveLinkedList(Slist*& u_list, int n, int i = 0) {
	/*
    WAY 1:	Dao nguoc mang ban dau.
	*/

	if (n == 2) return;
	if (i == 0) {
		swap(u_list->head->data, u_list->tail->data);
	}
	else if (n >= 3 && i < n) {
		int _count = 0;
		Snode* temp = u_list->head;

		while (_count != n - 1) {
			_count++;
			temp = temp->pnext;
		}
		int count_2 = 0;
		Snode* temp_2 = u_list->head;
		while (count_2 != i) {
			count_2++;
			temp_2 = temp_2->pnext;
		}
		int value = temp->data;
		swap(temp_2->data, temp->data);
	}
	reserveLinkedList(u_list, n - 1, i + 1);

}


Snode* reserveList(Slist*& u_list , Snode* curr  ) {
	/*
	WAY 2: dao mang ban dau
	*/
	
	if (curr == nullptr ||curr->pnext == nullptr) {
		u_list->tail = u_list->head;
		u_list->head = curr;
		return curr;
	}
	
	Snode* Node_next = curr->pnext;
    curr->pnext = nullptr;

	Snode* phead = reserveList(u_list,Node_next);
	
	Node_next->pnext = curr;

	return phead;
	
}


void directInsertion(Slist*& u_list, int n) {

	/*
    Ham sap xep danh sach tang dan theo phuong phap chen truc tiep.
    Tra ve danh sach tang da duoc sap xep theo thu tu tang dan.
    */

	if (n == 2) {
		if (u_list->head->data > u_list->head->pnext->data) {
			swap(u_list->head->data, u_list->head->pnext->data);
		}
	}
	if (n > 2) {
		directInsertion(u_list, n - 1);
		int count = 0;
		Snode* temp = u_list->head;
		while (count != n - 1) {
			count++;
			temp = temp->pnext;
		}
		int X = temp->data;
		for (Snode* p = u_list->head; p != temp; p = p->pnext) {
			if (u_list->head->data > X) { 
				Snode* q = newNode(X);
				q->pnext = u_list->head;
				u_list->head = q;
				if (temp == u_list->tail) {
					popBack(u_list);
				}
				else deleteAtPosition(u_list, n);
				break;
			}
			else if (p->pnext->data > X) {
				Snode* q_0 = newNode(X);
				if (u_list->tail == temp) {
					q_0->pnext = p->pnext;
					p->pnext = q_0;
					popBack(u_list);
				}
				else {
					q_0->pnext = p->pnext;
					p->pnext = q_0;
					deleteAtPosition(u_list, n);
				}
				break;
			}
		}
	}

}


Snode* findValue(Slist* r_list, int value, int n) {
	/*
	Tim phan cua co trong danh sach :
	+ Du lieu vao la gia tri can tim.
	+ Neu thanh cong tra ve phan tu do trong danh sach.
	+ Nguoc lai tra ve con tro rong.
	*/

	if (n == 0) {
		return nullptr;
	}
	int count = 1;
	Snode* temp = r_list->head;
	while (count != n) {
		count++;
		temp = temp->pnext;
	}
	if (temp->data == value) {
		cout << "\nVI TRI CUA PHAN TU VUA TIM TRONG DANH SACH LA : " << count-1;
		return temp;
	}
	else return findValue(r_list, value, n - 1);
}

void destroyList(Slist*& u_list) {
	
	//Ham huy danh sach.

	if (u_list != nullptr) {
		for (Snode* temp = u_list->head; temp != nullptr;) {
			Snode* next = temp->pnext;
			delete temp;
			temp = next;
		}
		delete[] u_list;
		u_list = nullptr;
	}
}