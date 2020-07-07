#include<iostream>

using namespace std;

#define MAX_SIZE 100

struct Stack {
	int data;
	Stack* next;
};


void push(Stack*&top ,int data);

int isEmty(Stack* top);

void pop(Stack*& top);

void printStack(Stack*top);

int main() {
	Stack* top = nullptr;
	push(top,44);
	push(top, 45);
	push(top, 46);
	push(top, 47);
	pop(top);
	printStack(top);
	return 0;
}

int isEmty(Stack* top)
{
	return top == nullptr;
}

void push(Stack*& top, int data) {
	Stack* temp;
	temp = new (std::nothrow) Stack;
	if (!temp) {
		cout << "\nHeap Overflow!";
		exit(0);
    }
	temp->data = data;
	temp->next = top;
	top = temp;
}

void pop(Stack*& top) {
	Stack* temp;
	if (top == nullptr) {
		cout << "\nStack Underflow !" << endl;
		return;
	}
	temp = top;
	top = top->next;
	temp->next = nullptr;
	free(temp);
	temp = nullptr;
}

void printStack(Stack* top) {
	Stack* temp;
	if (top == nullptr) {
		cout << "\nStack Underflow !";
		return;
	}
	temp = top;
	while (temp) {
		cout << temp->data << endl;
		temp=temp->next;
	}

}