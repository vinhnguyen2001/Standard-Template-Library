#include<iostream>
#include<stdlib.h>
#include<cstdlib>

using namespace std;

struct node {
	void* key;
	node * next;
};
typedef struct node* Ref;

struct Fraction {
	int numerator;
	int denomirator;
};
int lengthList(Ref head);

Ref getNode(void* k, int dSize);

void addFirst(Ref& head, Ref& tail, void* k, int dSize);

void addTail(Ref& head, Ref& tail, void* k, int dSize);

void destroyList (Ref& head);

Ref findList(Ref head, void* dat, bool(*cmp)(void*, void*));
 
bool fracComp(void* p, void* q);

Ref insertAfter(Ref& head, void* x, void* val, int dSize, bool(*cmp)(void*, void*));

Ref insertAtPosition(Ref& head,Ref &tail, void* val, int dSize, int pos);

void popFont (Ref& head,Ref &tail); 

void popBack(Ref&head ,Ref& tail);

void deleteAfter(Ref& head,Ref &tail , void* x, int dSize, bool(*cmp)(void*, void*));

void DeleteAtPosition(Ref& head,Ref& tail, int pos);

void printList(Ref head, void(*cmp)(void*));

void printDouble(void* f);

void printFraction(void* ps);

void inputFraction( Fraction*& w_f);

void main() {
	/*double x;
	int dSize = sizeof(double);
	Ref head = nullptr;
	Ref tail = nullptr;
	x = 2.5; addFirst(head, tail, &x, sizeof(double));
	x = 3.5; addFirst(head, tail, &x, sizeof(double));
	x = 5.5; addFirst(head, tail, &x, sizeof(double));*/
	Fraction ps[] = { {1,2},{-2,3},{3,4},{-4,5},{5,6}};
	Ref head = nullptr;
	Ref tail = nullptr;
	int n = sizeof(ps) / sizeof(ps[0]);
	int dSize = sizeof(struct Fraction);
	Ref p = nullptr;
	for (int i = 0; i < n; i++) {
		addTail(head, tail, &ps[i], dSize);
	}
	Fraction r1 = { -2, 3 }, r3 = { 16,20 }, r4 = { 113,17 };
	int temp = 1;
	int sel = 0;
	while (temp) {
		cout << "FRESS 1.ADD ELEMENT TO THE TOP OF THE LIST.";
		cout << "\nFRESS 2.ADD ELEMENT TO THE LAST OF THE LIST.";
		cout << "\nFRESS 3.ADD ELEMENT  TO ANY POSITION IN THE ARRAY.";
		cout << "\nFRESS 4.ADD ELEMENT TO THE BACK POSITON OF THE GIVEN ELEMENT.";
		cout << "\nFRESS 5.DELETE ELEMENT TO THE TOP OF THE LIST";
		cout << "\nFRESS 6.DELETE ELEMENT TO THE LAST OF THE LIST.";
		cout << "\nFRESS 7.DELETE ELEMENT  TO ANY POSITION IN THE ARRAY.";
		cout << "\nFRESS 8.DETELE ELEMENT TO THE BACK POSITON OF THE GIVEN ELEMENT.";
		cout << "\nFRESS 9.PRINT LIST.";
		cout << endl;
		cin >> sel;
		switch (sel) {
		case 1: {
			Fraction* ps_ = new(std::nothrow) Fraction;
			if (!ps_) {
				cout << "\nERROR MEMORY!";
				return;
			}
			inputFraction(ps_);
			addFirst(head, tail, ps_, dSize);
			if (!ps_) {
				delete ps_;
				ps_ = nullptr;
			}
			cout << "\nARRAY AFTER BEING ADDED."<<endl;
			printList(head, printFraction);
			break;
		}
		case 2: {
			Fraction* ps_ = new(std::nothrow) Fraction;
			if (!ps_) {
				cout << "\nERROR MEMORY!";
				return;
			}
			inputFraction(ps_);
			addTail(head, tail, ps_, dSize);
			if (!ps_) {
				delete ps_;
				ps_ = nullptr;
			}
			cout << "\nARRAY AFTER BEING ADDED." << endl;
			printList(head, printFraction);
			break;
		}
		case 3: {
			Fraction* ps_ = new(std::nothrow) Fraction;
			if (!ps_) {
				cout << "\nERROR MEMORY!";
				return;
			}
			int pos = 0;
			cout << "\nENTER THE POSITION YOU WANT TO INSERT : ";
			do {
				cin >> pos;
				if (pos < 0 || pos >= lengthList(head)) {
					cout << "\nYOU HAVE JUST ENTERED.PLEASE RE_ENTER !" << endl;
				}
			} while (pos < 0 || pos >= lengthList(head));
			inputFraction(ps_);
			insertAtPosition(head,tail, ps_, dSize, pos);
			if (!ps_) {
				delete ps_;
				ps_ = nullptr;
			}
			cout << "\nARRAY AFTER BEING ADDED." << endl;
			printList(head, printFraction);
			break;
		}
		case 4: {
			Fraction* ps_ = new(std::nothrow) Fraction;
			if (!ps_) {
				cout << "\nERROR MEMORY!";
				return;
			}
			inputFraction(ps_);
			insertAfter(head, &ps[1], ps_, dSize, fracComp);
			if (!ps_) {
				delete ps_;
				ps_ = nullptr;
			}
			cout << "\nARRAY AFTER BEING ADDED." << endl;
			printList(head, printFraction);
			break;
		}
		case 5: {
			popFont(head, tail);
			cout << "\nARRAY AFTER BEING DELETED."<<endl;
			printList(head, printFraction);
			break;
		}
		case 6: {
			popBack(head, tail);
			cout << "\nARRAY AFTER BEING DELETED." << endl;
			printList(head, printFraction);
			break;
		}
		case 7: {
			int pos = 0;
			cout << "\nENTER THE POSITION YOU WANT TO DELETE : ";
			do {
				cin >> pos;
				if (pos < 0 || pos >= lengthList(head)) {
					cout << "\nYOU HAVE JUST ENTERED.PLEASE RE_ENTER !" << endl;
				}
			} while (pos < 0 || pos >= lengthList(head));
			DeleteAtPosition(head, tail, pos);
			cout << "\nARRAY AFTER BEING DELETED." << endl;
			printList(head, printFraction);
			break;
		}
		case 8: {
			deleteAfter(head, tail, &r1, dSize, fracComp);
			cout << "\nELEMENT OF THE LIST." << endl;
			printList(head, printFraction);
			break;
		}
		case 9: {
			cout << "\nELEMENT OF THE LIST." << endl;
			printList(head, printFraction);
		}

	}
			  cout << "\nDO YOU WANT CONTINUE ?" << "\tYES 1. \tNO 0." << endl;
			  cin >> temp;
			  cout << endl;
	}
	destroyList(head);
}

int lengthList(Ref head) {
	Ref p = head;
	int count = 0;
	for (; p; p = p->next) {
		count++;
	}
	return count;
}

void inputFraction(Fraction*& w_f) {
	cout << "\nENTER THE NUMERATOR : ";
	cin >> w_f->numerator;
	cout << "\nENTER THE DONOMIRATOR : ";
	cin >> w_f->denomirator;
}

Ref getNode(void* k, int dSize) {
	Ref p;
	p = (Ref)malloc(sizeof(struct node));
	if (p == NULL) {
		cout << "!Not Enough Memory !";
		exit(0);
	}
	p->key = new char[dSize];
	p->next = NULL;
	
	if (p->key == NULL) {
		free(p);
		return NULL;
	}
	memcpy(p->key, k, dSize);
	
	return p;
}

void addFirst(Ref& head, Ref& tail, void* k, int dSize) {
	if (k == NULL) return;
	Ref p = getNode(k, dSize);
	if (p != NULL) {
		if (head == nullptr) {
			head = tail = p;
		}
		else
		{
			p->next = head;
			head = p;
		}
	}
}

void addTail(Ref& head, Ref& tail, void* k, int dSize) {
	if (k == NULL)return;
	Ref p = getNode(k, dSize);
	if (p != NULL) {
		if (head == nullptr) {
			head = tail = p;
		}
		else {
			tail->next = p;
			tail = p;
		}
	}
}

void destroyList(Ref& head) {
	Ref p;
	while (head) {
		p = head;
		if (p->key != nullptr) {
			delete[](char*)p->key;
		}
		head = head->next;
		free(p);
	}
}

Ref findList(Ref head, void* dat, bool(*cmp)(void*, void*)) {
	Ref p = head;
	while (p != nullptr) {
		if (cmp(p->key, dat)) break;
		p = p->next;
	}
	return p;
}

bool fracComp(void* p, void* q) {
	Fraction* r = (Fraction*)p;
	Fraction* s = (Fraction*)q;
	int num1 = r->numerator * s->denomirator;
	int num2 = s->numerator * r->denomirator;
	return (num1 == num2);
}

Ref insertAfter(Ref& head, void* x, void* val, int dSize, bool(*cmp)(void*, void*)) {
	
	Ref q = findList(head, x, cmp);
	if (!q) {
		return nullptr;
	}
	Ref p = getNode(val, dSize);
	if (p) {
		p->next = q->next;
		q->next = p;
	}
	return p;
}

Ref insertAtPosition(Ref& head,Ref &tail, void* val, int dSize, int pos) {
	/* pos : vi tri ban muon chen trong mang
	   va phan tu luc dau tai vi tri day se bi lui ve phia sau.
	*/
	Ref temp = getNode(val, dSize);
	if (val == nullptr) return nullptr;
	if (pos == 0)
	{
		addFirst(head, tail, val, dSize);
	}
	else {
		Ref p = head;
		int i = 0;
		for (; i < pos - 1; p = p->next, i++);
		temp->next = p->next;
		p->next = temp;
		return temp;
	}
}

void popFont(Ref& head, Ref& tail) {
	if (head == nullptr) return;
	if (head == tail) {
		if (head->key) {
			delete[] head->key;
			head->key = nullptr;
		}
		free(head);
		head = tail = nullptr;
		return;
	}
	Ref temp = head;
	head = temp->next;
	if (temp->key) {
		delete[](char*) temp->key;
	}
	free(temp);

}

void popBack(Ref& head, Ref& tail) {
	if (head == nullptr) return;
	if (head == tail) {
		if (head->key) {
			delete[] head->key;
			head->key = nullptr;
		}
		free(head);
		head = tail = nullptr;
		return;
	}
	Ref temp = head;
	for (; temp->next != tail; temp = temp->next);
	if (tail->key) {
		delete[](char*) tail->key;
	}
	free(tail);
	tail = nullptr;
	free(tail);
	tail = temp;
	temp->next = nullptr;
}

void deleteAfter(Ref& head,Ref& tail, void* x,  int dSize, bool(*cmp)(void*, void*)) {
	Ref q = findList(head, x, cmp);
	if (!q) { //neu khong co gia tri cua x trong danh sach thi dung lai.
		cout << "\nDOES NOT EXIST IN VALUES !";
		return;
	}
	if (q == head) {
		popFont(head, tail);
		return;
	}
	Ref temp=head;
	for (; temp->next != q; temp = temp->next);
    temp->next=q->next;
	if (q) {
		if (q->key) {
			delete[](char*)q->key;
		}
		free(q);
		q = nullptr;
	}
}

void DeleteAtPosition(Ref& head, Ref& tail, int pos) {
	int i = 1;
	if (head == nullptr) return;
	if (pos == 0) {
		popFont(head, tail);
		return;
	}
	Ref temp = head;
	Ref r = head;
	while (temp->next != nullptr) {
		temp = temp->next;
		if (i == pos) {
			r->next = temp->next;
			if (temp != nullptr) {
				if (temp->key) {
					delete[](char*)temp->key;
				}
				free(temp);
				temp = nullptr;
				return;
			}
		}
		r = r->next;
		i++;
	}
}

void printList(Ref head , void(*cmp)(void*)) {
	
	for (Ref temp = head; temp; temp = temp->next) {
		(*cmp)(temp->key);
	}
}

void printDouble(void* f) {

	cout << *(double*)f << endl;
}

void printFraction(void*ps) {
	Fraction* PS = (Fraction*)ps;
	cout << PS->numerator << "/" << PS->denomirator << endl;
}