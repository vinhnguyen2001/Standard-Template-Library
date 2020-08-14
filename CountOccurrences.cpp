#include<iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};
struct List {
	Node* head;
};

int countOccurrences(List ls, int num);

bool isPermutation(List ls1, List ls2);

Node* newNode(int val);

void pushBack(List& ls, int val);

void printList(List ls);

void destroyList(List ls);

int main() {
	int a[6] = { 3,4,3,6,7,8 };
	int b[6] = { 3,4,3,6,7,8 };
	List ls1 ;
	ls1.head = nullptr;
	List ls2;
	ls2.head = nullptr;
	for (int i = 0; i < 6; i++){
		pushBack(ls1, a[i]);
		pushBack(ls2, b[i]);
	}
	/*printList(ls1);
	printList(ls2);*/
	cout << "\n the result: " << isPermutation(ls1, ls2);
	cout << "\n the result: " << countOccurrences(ls1,3);
	destroyList(ls1);
	destroyList(ls2);
	return 0;
}

int countOccurrences(List ls, int num) {
	int count = 0;
	Node* cur = ls.head;
	for (; cur; cur = cur->next) {
		if (cur->data == num) {
			count++;
		}
	}
	return count;
}

bool isPermutation(List ls1, List ls2) {
	Node* cur_1 = ls1.head;
	Node* cur_2 = ls2.head;
	for (; cur_1; cur_1 = cur_1->next) {
		if (countOccurrences(ls2, cur_1->data)==0) {
			return false;
		}
	}
	return true;
}

Node* newNode(int val) {
	Node* temp = new(std::nothrow) Node;
	if (!temp) {
		cout << "\nHeap Overflow !";
		exit(0);
	}
	temp->data = val;
	temp->next = nullptr;
	return temp;
}

void pushBack(List& ls, int val) {
	Node* cur = newNode(val);
	if (ls.head == nullptr) {
		ls.head = cur;
		return;
	}
	Node* temp = ls.head;
	for (; temp->next; temp = temp->next);
	temp->next = cur;
}

void printList(List ls) {
	if (ls.head) {
		Node* temp = ls.head;
		while (temp) {
			cout << "\n" << temp->data;
			temp = temp->next;
		}
	}
}

void destroyList(List ls) {
	while (ls.head) {
		Node* temp = ls.head;
		ls.head = temp->next;
		delete temp;
		temp->next = nullptr;
		temp = nullptr;
	}
}
