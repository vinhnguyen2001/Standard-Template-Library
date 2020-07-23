#include<iostream>

using namespace std;

struct Node {
	int data;
	Node* next;
};
typedef struct Node* Ref;

bool isEmty(Ref head);

int lengthList(Ref head);

Ref newNode(int value);

Ref pushBack(Ref& head, Ref& tail, int value);

void printList(Ref head);

bool isPrime(int n , int i );

int countPrimeNumberLinkedList(Ref head, Ref tail , int n );

void sumOfLastN_Nodes(Node* head, int& num , int& sum);

int countPairs(Ref head1_, Ref head2_, int value);

int main() {
	
	Ref head = nullptr;
	Ref tail = nullptr;
	int i = 1;
	int a[] = { 6,9,2,4,3,15,11 };
	for (int i = 0; i < 7; i++) {
		/*cin >> n;
		cout << n << " : " << isPrime(n,i) << endl;*/
		pushBack(head,tail,a[i]);
	}
	int n = lengthList(head);
	//cout << "\nn: " << n;
	cout << countPrimeNumberLinkedList(head, tail, n) << endl;
	printList(head);
	int sum = 0;
	int num_ = 0;
	sumOfLastN_Nodes(head, num_, sum);
	cout << "\nSUM :" << sum;
	return 0;
	/*
	temp =1;
	int selec = 0;
	while(temp){
	cout<<"NHAN 1. ";
	cout<<"NHAN 2. ";
	cout<<"NHAN 3. ";
	cout<<"NHAN 4. ";
	cout<<"NHAN 5. "<<endl;
	cin>>selec;
	switch(selec){
	
	case 1:{

	break;
	}
	case 2:{

	break;
	}
    case 3:{

	break;
	}
	case 4:
	{

	break;
	}

	case 5:
	{

	}
	cout<<"\nBAN CO MUON TIEP TUC KHONG ? \tCO.1 \tKHONG.0 "<<endl;
	cin>>temp;
	cout<<endl;
	}
	}
	
	// Kiem tra ro ri bo nho !;
	
	*/
}


bool isEmty(Ref head) {
	if (head == nullptr) {
		return true;
	}
	return false;
}


int lengthList(Ref head) {
	Node* temp = head;
	int count = 0;
	while (temp) {
		count++;
		temp = temp->next;
	}
	return count;
}

Ref newNode(int value) {
	/*
	 Ham tao 1 node moi :
	 + neu thanh cong thi tra ve dia chi cua node moi do.
	 + nguoc lai thi dung chuong trinh & xuat loi.
	*/
	Ref temp = new (std::nothrow) Node;
	if (!temp) {
		cout << "\nLoi Vung Nho !";
		exit(0);
	}
	temp->data = value;
	temp->next = nullptr;
	return temp;
}

Ref pushBack(Ref& head, Ref& tail, int value) {
	// ham chen node moi vao cuoi danh sach lien ket.
	Ref temp = newNode(value);
	if (isEmty(head)) {
		head = tail = temp;
	}
	else {
		tail->next = temp;
		tail = temp;
	}
	return head;
}

void printList(Ref head) {
	if (!isEmty(head)) {
		Ref temp = head;
		while (temp != nullptr) {
			cout << temp->data << "  ";
			temp = temp->next;
		}
	}
	else {
		cout << "\nDanh Sach Rong !";
	}
}

bool isPrime(int n , int i = 1) {
	if (n == 0 || n % 2 == 0 && n != 2 ) {
		return false;
	}
	if (i * i > n) {
		return true;
	}
	else isPrime(n, i + 1);
}

int countPrimeNumberLinkedList(Ref head, Ref tail , int n ) {
	/*
	 ham dem so luong phan tu la so nguyen to va phai nho hon phan tu truoc & sau no.
	 (tinh ca phan tu dau & phan tu cuoi)
	*/
	int count = 0;
	if (n >= 3) {
		Ref p_0 = head;
		if (isPrime(p_0->data) && p_0->data < p_0->next->data) {
			count++;
		}
		Ref p_1 = p_0->next;
		for (; p_0->next->next; p_0 = p_0->next) {
			p_1 = p_0->next;
			Ref p_2 = p_1->next;
			if (p_2 == tail) {
				if (isPrime(p_2->data) && p_2->data < p_1->data) {
					count++;
				}
			}
			if (p_1->data < p_0->data && p_1->data < p_2->data && isPrime(p_1->data)) {
				count++;
			}
		}
	}
	else {
		Ref p = head;
		if (p->data < p->next->data && isPrime(p->data)) {
			count++;
		}
		else if (p->next->data < p->data && isPrime(p->next->data)) {
			count++;
		}
	}
	return count;
}


void sumOfLastN_Nodes(Node* head, int& num, int& sum) {
	/*
	Loi giai co tham khao tren geeksforgeek.org
	https://www.geeksforgeeks.org/find-sum-last-n-nodes-given-linked-list/
	*/
	if (!head || num <= 0) {
		return;
	}
	sumOfLastN_Nodes(head->next, num, sum);
	if (num > 0) {
		sum = sum +head->data;
		num--;
	}
}

int countPairs(Ref head1_, Ref head2_, int value) {
	/*
	du doan do phuc tap : O(n^2).
	*/
	int count = 0;
	if (isEmty(head1_)&& isEmty(head2_)){

		for (Ref p1 = head1_; p1; p1 = p1->next) {
			for (Ref p2 = head2_; p2; p2 = p2->next) {
				if ((p1->data + p2->data) == value) {
					count++;
					break;
				}
			}
		}
	}
	return count;
	/*
	countPairs(list1, list2, x)
    int  count = 0
    while list != NULL and list2 != NULL
	 if (list1->data + list2->data) == x
		list1 = list1->next
		list2 = list2->next
		count++
	else if (list1->data + list2->data) > x
		list2 = list2->next
	else
		list1 = list1->next

     return count
	*/
}

