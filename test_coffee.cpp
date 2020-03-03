#include<iostream>
using namespace std;
void showResult0(int* a)
{
	int* posPtr = a;
	for (; posPtr <= &a[9]; posPtr++)
	{
		cout << *posPtr<< " ";
		//a++;
	}
}

void showResult1(int*a[10])
{
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			cout << *(*(a + i) + j) << " ";
		}
		cout << endl;
	}
}
void showExample(void* data, int size)
{
	if (size == sizeof(char))
	{
		char* charPtr = (char*)data;
		//ep kieu con tro tu kieu *void sang kieu char
		cout << *charPtr << endl;
	}
	else if (size == sizeof(int))
	{
		int* ptr = (int*)data;
		cout << *ptr << endl;
	}
	else if (size == sizeof(double))
	{
		double* Ptr = (double*)data;
		*Ptr *= 3;
		cout << *Ptr << endl;
	}
}
int main()
{
	/*//cap phat mang dong hai chieu 
	int** array, array2, array3;
	float** floatArray;
	char** friends;
	array = new int* [100];
	for (size_t i = 0; i < 100; i++)
	{ // tao mang dong hai chieu 
		array[i] = new int[100];
	}
	fill(array[0], array[0] + 100 * 100,1);// gan tat ca phan tu trong mang co gia tri dac biet nao do 
	for (size_t i = 0; i < 100; i++)
	{
		for (size_t j = 0; i < 100; j++)
		{
			cout << array[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
	
	// CON TRO & MANG MOT CHIEU 
	int b[] = { 1,2,3,4,5,6,7,8,9,10 };
	int* ptr = b;
	showResult0(b);
	
	*/
	// MANG HAI CHIEU VA POINTER

	/*int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int* a[10][10] = {};
	int* b[10];
	for (size_t i = 0; i < 10; i++)
	{
		b[i] = new int[10];
	}
	
	int** c = new int* [3];
	for (size_t i = 0; i < 3; i++)
	{
		c[i] = new int[3];
	}
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			c[i][j] = i + j;
		}
	}
	showResult1(b);*/
	/*int* prt = NULL;
	prt = 0;
	double x = 3.124324;
	char c = 'LD';
	showExample(&x, sizeof(double));
	showExample(&c, sizeof(char));
	return 0;*/
	// thu hoi cap phat dong cho con tro tro den con tro 
	//int** xptr;
	//xptr = new int* [100];
	//for (size_t i = 0; i < 100; i++)
	//{
	//	xptr[i] = new int[12];
	//}
	//for (size_t i = 0; i < 100; i++)
	//{
	//	delete[] xptr;
	//}
	//delete xptr;
	//// thu hoi cap phat dong voi mang mot chieu va con tro void
	//int* aptr;
	//int* arr = new int[100];
	//delete[] arr;
	//void* vptr;
	//int* b = new int(100);
	//vptr = (int*)b;
	//delete vptr;
	//// normal pointer
	//int* nptr;
	//int* c = new int(100);
	//nptr = c;
	//delete nptr;

}