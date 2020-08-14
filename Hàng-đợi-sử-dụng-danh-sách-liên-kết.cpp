#include<iostream>

using namespace std;

template<class T>
struct NODE
{
	T data;
	NODE* pnext;
};

template<class T>
struct QUEUE
{
	NODE<T>* head;
	NODE<T>* tail;
};

//Hàm khỏi tạo hàng đợi.
template<class T>
void initialize(QUEUE<T>** w_queue)
{
	(*w_queue) = new(std::nothrow) QUEUE<T>{ nullptr, nullptr };
}

//Hàm hủy hàng đợi.
template<class T>
void destroy(QUEUE<T>** w_queue)
{
	if ((*w_queue) != nullptr)
	{
		NODE<T>* p = (*w_queue)->head;
		while(p)
		{
			(*w_queue)->head = (*w_queue)->head->pnext;
			delete p;
			p = (*w_queue)->head;
		}
		delete(*w_queue);
		(*w_queue) = nullptr;
	}
}

//Hàm duyệt hàng đợi.
template<class T>
void print(QUEUE<T>* r_queue)
{
	if (isEmpty(r_queue))
	{
		cout << "Hang doi rong.\n";
	}
	NODE<T>* p = r_queue->head;
	while (p)
	{
		cout << p->data<<"  ";
		p = p->pnext;
	}
	cout << endl;
}

//Hàm kiểm tra hàng đợi có rỗng hay không?
template<class T>
bool isEmpty(QUEUE<T>* r_queue)
{
	return (r_queue->head == nullptr);
}

//Hàm tạo 1 node.
template<class T>
NODE<T>* newNode(T r_val)
{
	NODE<T>* p = new(std::nothrow)NODE<T>;
	if (!p)
		return nullptr;
	p->pnext = nullptr;
	p->data = r_val;
	return p;
}

//Hàm thêm 1 phần tử cuối hàng đợi.
template<class T>
void push(QUEUE<T>* u_queue, T r_val)
{
	NODE<T>* p = newNode(r_val);

	if (p == nullptr)
		return;
	
	if (isEmpty(u_queue))
		u_queue->head = u_queue->tail = p;
	else
	{
		u_queue->tail->pnext = p;
		u_queue->tail = p;
	}
}

//Hàm lấy 1 phần tử ở đầu hàng đợi.
template<class T>
T pop(QUEUE<T>* u_queue)
{
	if (isEmpty(u_queue))
		return NULL;

	if (u_queue->head == u_queue->tail)
	{
		T data = u_queue->head->data;
		delete u_queue->head;
		u_queue->head = u_queue->tail = nullptr;
		return data;
	}

	NODE<T>* p = u_queue->head;
	T data = p->data;
	u_queue->head = u_queue->head->pnext;
	delete p;
	p = nullptr;
	return data;
}

int main()
{
	QUEUE<int>* queue = nullptr;
	int a = NULL;
	initialize(&queue);
	if (!queue)
		cout << "Khong the cap phat bo nho!\n";
	else
	{
		if (isEmpty(queue))
			cout << "Hang doi trong.\n";
		
		push(queue, 10);
		print(queue);

		push(queue, 1);
		print(queue);

		push(queue, 14);
		print(queue);

		push(queue, 9);
		print(queue);

		push(queue, 5);
		print(queue);

		a = pop(queue);
		if (a == NULL)
			cout << "Hang doi rong.\n";
		else cout << "Phan tu dau mang la: " << a << endl;
		print(queue);

		a = pop(queue);
		if (a == NULL)
			cout << "Hang doi rong.\n";
		else cout << "Phan tu dau mang la: " << a << endl;
		print(queue);

		a = pop(queue);
		if (a == NULL)
			cout << "Hang doi rong.\n";
		else cout << "Phan tu dau mang la: " << a << endl;
		print(queue);

		a = pop(queue);
		if (a == NULL)
			cout << "Hang doi rong.\n";
		else cout << "Phan tu dau mang la: " << a << endl;
		print(queue);

		a = pop(queue);
		if (a == NULL)
			cout << "Hang doi rong.\n";
		else cout << "Phan tu dau mang la: " << a << endl;
		print(queue);

		a = pop(queue);
		if (a == NULL)
			cout << "Hang doi rong.\n";
		else cout << "Phan tu dau mang la: " << a << endl;
		print(queue);

		a = pop(queue);
		if (a == NULL)
			cout << "Hang doi rong.\n";
		else cout << "Phan tu dau mang la: " << a << endl;
		print(queue);

		a = pop(queue);
		if (a == NULL)
			cout << "Hang doi rong.\n";
		else cout << "Phan tu dau mang la: " << a << endl;
		print(queue);

		destroy(&queue);
	}
	return 0;
}