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

Snode* newNode (int val);

Snode* pushBack(Slist*& u_list, int val);

void deleteAtPosition(Slist*& u_list, int pos);

void popBack(Slist*& u_list);

void printList(Slist* r_list);

int sumEvenNumber( Slist* r_list , int n );

int findMaxValue (Slist* r_list , int n , int max);

void reserveLinkedList(Slist*& u_list, int n, int i  );

int findValue (Slist* r_list, int value , int n );

void directInsertion(Slist*& u_list, int n);

void destroyList(Slist*& u_list);

int main(){
	Slist*list=nullptr;
	initialize(list);
	int val=0;
	int k = 3;
	//int a[] = { -2,-1,0,1,2,3,4,5 };
	int a[] = { -2,4,-3,2,5,6,7,-9 };
	for (int i = 0; i < 8; i++) {
		//cin >> val;
		pushBack(list, a[i]);
	}
	printList(list);
	int n= lengthList(list);
	cout<<"\nsum: "<<sumEvenNumber(list, n);
	int max=-1;
	cout << "\nmax-value :" << findMaxValue(list, n, max) << endl;
	
	int i = 0;
	reserveLinkedList(list, n,i);
	printList(list);
	cout << endl;
	directInsertion(list, n);
	printList(list);
    cout<<"\nVi tri "<<findValue(list, 6, 8);
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
	if (r_list->head == nullptr) {
		return true;
	}
	return false;
}

int lengthList(Slist* r_list) {
	Snode* temp = r_list->head;
	int count = 0;
	while (temp) {
		count++;
		temp = temp->pnext;
	}
	return count;
}

Snode* newNode(int val) {
	Snode* node = new(std::nothrow) Snode;
	if (!node) {
		cout << "\nError Memory !";
		exit(0);
	}
	node->data = val;
	node->pnext = nullptr;
	return node;
}


Snode* pushBack(Slist*& u_list , int val) {
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
	if (u_list->head ==nullptr) return;
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

int sumEvenNumber(Slist* r_list, int n) {
	static int sum = 0;
	if (n > 0) {
		int count = 0;
		Snode* temp = r_list->head;
		while (count!=n-1) {
			count++;
			temp = temp->pnext;
		}
		if (temp->data % 2 == 0) {
			sum += temp->data;
		}
	}
	else return sum;
	return sumEvenNumber(r_list, n - 1);
}

int findMaxValue (Slist* r_list , int n , int max  ) {
	if (n == 2) {
		if (r_list->head->data > r_list->head->pnext->data) {
			return r_list->head->data;
		}
		else return r_list->head->pnext->data;
	}
	max = findMaxValue(r_list, n - 1,max);
	int count = 0;
	Snode* temp = r_list->head;
	while (count != n - 1) {
		count++;
		temp = temp->pnext;
	}
	if (max < temp->data) {
		return temp->data;
	}
	else return max;
}

void reserveLinkedList(Slist*& u_list,  int n , int i = 0  ) {	
	if (n == 2) return;
	if (i == 0) {
		swap(u_list->head->data, u_list->tail->data);
	}
	else if (n>=3 && i < n) {
		int _count = 0;
		Snode* temp = u_list->head;
		
		while (_count != n-1) {
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
	reserveLinkedList(u_list, n - 1, i+1);
}

void directInsertion(Slist*& u_list, int n) {
	if (n == 2) {
		if (u_list->head->data > u_list->head->pnext->data) {
			swap(u_list->head->data, u_list->head->pnext->data);
		}
	}
	if (n > 2) {
		directInsertion(u_list, n - 1);
		int count = 0;
		Snode* temp = u_list->head;
		while (count != n-1) {
			count++;
			temp =temp->pnext;
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

int findValue(Slist* r_list, int value, int n) {
	if (n == 0) {
		return -1;
	}
	int count = 1;
	Snode* temp = r_list->head;
	while (count != n) {
		count++;
		temp = temp->pnext;
	}
	if (temp->data == value) {
		return count;
	}
	else return findValue(r_list, value, n - 1);
}


void destroyList(Slist*& u_list) {
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