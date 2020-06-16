#include<iostream>
using namespace std;

struct Fraction {
	int num;
	int denom;
};

typedef  Fraction PS;

struct LinkedList {
	PS data;
    LinkedList* next;
};

typedef struct LinkedList* node; 

int length(node head);

node createNode(PS value);

node addHead(node head, PS value); 

node addTail(node head, Fraction value);

void insBefore(node &temp, Fraction k);

void insertAt(node& head, node& tail);

void delBeg(node& head, node& tail);
	
void delEnd(node& head, node& tail);

void  deleteMid(node head);

void deteteAt(node& head, node& tail);

void printList(node head);

void destroyList(node& head);

node Input();

int main() {
	node head = Input();
	printList(head);
	node tail = NULL;
	int temp = 1;
	int sel = 0;
	while (temp) {
		cout << "FRESS 1. Add the last element of the list. " << endl;
		cout << "FRESS 2.Insert a part into   the specified  positon." << endl;
		cout << "FRESS 3.Partially  delete  the specified  location." << endl;
		cin >> sel;
		switch (sel) {
		case 1: {
			
			Fraction value;
			cout << "Enter the numerator : ";
			cin >> value.num;
			cout << endl;
			cout << "Enter the denomirator : ";
			cin >> value.denom;
			cout << endl;
			addTail(head, value);
			printList(head);
			//destroyList(head);
			break;
		}
		case 2: {
			insertAt(head, tail);
			printList(head);
		//	destroyList(head);
			break;
		}
		case 3:
		{
			deteteAt(head, tail);
		    printList(head);
		//	destroyList(head);
			break;
		}
		}
		cout << "\Do you want to continue ? " << "\t Yes 1." << "\t No 0." << endl;
		cin >> temp;
	}
	destroyList(head);
	return 0;
	
	
}
int length(node head) {
	node temp;
	int count = 0;
	for (temp = head; temp; temp = temp->next) {
		count++;
	}
	return count;
}

node createNode(PS value) {
	node temp;
	temp = (node)malloc(sizeof(struct LinkedList));
	if (temp == NULL) {
		cout << "\nNot enough memory";
		exit(0);
	}
	temp->data = value;
	temp->next = NULL;

	return temp;
}

node addHead(node head, PS value) {
	// them phan tu vao dau danh sach 
	node temp = createNode(value);
	if (head == NULL) {
		head = temp;
	}
	else {
		temp->next = head;
		head = temp;
	}
	return head;
}

node addTail(node head, Fraction value) {
	// them phan tu vao cuoi danh sach 
	node temp;
	if (head == NULL) {
		head = createNode(value);
	}
	else {
		temp = head;
		while (temp->next) {
			temp = temp->next;
		}
		temp->next = createNode(value);
	}
	return head;
}

void insBefore(node &temp, Fraction k) {
	// them phan tu vào vi tri bat ky nam giua danh sach 
	node q;
	q = (node)malloc(sizeof(struct LinkedList));
	if (q == NULL) {
		cout << "Not enough memory\n";
		exit(0);
	}
	*q = *temp;
	temp->next = q;
	temp->data = k;
}

void insertAt(node& head, node& tail) {
	// them phan tu vao vi tri bat ky trong danh sach 
	int n = length(head);

	int i = 0;
	int pos = -1;
	node temp;
	PS k;
	//kiem tra dieu kien cua pos 
	do {
		cout << "\nEnter the location you want to insert : ";
		cin >> pos;
		if (pos<0 || pos > n) {
			cout << "Input location is invalid.Please retype ! \n";
		}
	} while (pos < 0 || pos>n);

	cout << "\nEnter the value location you want to insert.Enter the numerator : ";
	cin >> k.num;
	cout << "\nEnter the denomirator : ";
	cin >> k.denom;
	if (pos == 0) {
	 head =	addHead(head, k);
	}
	else {
		if (pos == n) {
		head = addTail(head, k);
		}
		else {
			for (i = 0, temp = head; i < pos; i++, temp = temp->next);
			insBefore(temp, k);	
		}
	}
}

void delBeg(node& head, node& tail) {
	// xoa phan tu dau danh sach 
	node temp;
	if (head == tail) {
		free(head);
		head = tail = NULL;
	}
	else {
		temp = head;
		head = head->next;
		free(temp);
	}
}

void delEnd(node& head, node& tail) {
	// xoa phan tu o cuoi danh sach 
	node temp;
	if (head == tail) {
		free(head);
		head = tail = NULL;
	}
	else {
		for (temp = head; temp->next != tail; temp = temp->next);
		free(tail);
		tail = temp;
		temp->next = NULL;
	}
}

void  deleteMid(node q) {
	// xoa phan tu o giua danh sach 
	node temp;
	temp = q->next;
	*q = *temp;
	free(temp);
}

void deteteAt (node& head, node& tail) {
	// delete phan tu tai vi tri bat ky 
	int pos=-1;
	node temp;
	int n = length(head);
	int i;
	do {
		cout << "\nEnter the location you want to delete : ";
		cin >> pos;
		if (pos<0 || pos >= n) {
			cout << "Input location is invalid.Please retype ! \n";
		}
	} while (pos < 0 || pos>=n);

	/*if (pos < 0 || pos >= n) {
		cout << "Input location is invalid.Please retype ! \n";
	}*/
	if (pos == 0) {
		delBeg(head, tail);
	}
	else {
		if (pos == n-1 ) {
			delEnd(head, tail);
		}
		else {
			for (i= 0 , temp = head ; i < pos; i++, temp = temp->next);
			if (temp->next == tail) {
				tail = temp;
			}
			deleteMid(temp);
		}
	}
}

void printList(node head) {
	// in danh sach 
	if (head == NULL) {
		cout << "\nEmmty List " << endl;
	}
	else {
		for (node p = head; p; p = p->next) {
			cout << p->data.num << "/" << p->data.denom << endl;
		}
	}
}

node Input() {
	// khoi tao danh sach 
	node head = NULL;
	node tail = NULL;
	int n;
	PS value;
	do {
		cout << "Enter the number of element : ";
		cin >> n;
	} while (n <= 0);
	for (int i = 0; i < n; i++) {
		cout << "Enter the numerator : ";
		cin >> value.num;
		cout << endl;
		cout << "Enter the denomirator : ";
		cin >> value.denom;
		cout << endl;
		head = addTail(head, value);
		
	}
	return head;
}

void destroyList(node& head) {
	node temp;
	while (head) {
		temp = head;
		head = head->next;
		free(temp);
	}
}