#include<iostream>
using namespace std;

//struct phanso
//{
//	int tuso, mauso;
//};
//void nhapmang(phanso* x, int& n)
//{
//	cout << " nhap so phan tu"; cin >> n;
//	phanso* vitri = x;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> vitri->tuso;
//		cin >> vitri->mauso;
//		vitri = vitri + 1;
//	}
//}
//void xuatmang(phanso* x, int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		cout << (x + i)->tuso << "/" << (x + i)->mauso << endl;
//	}
//}
//void chen(phanso* x, int& n, phanso a)
//{
//	(x + n)->tuso = a.tuso;
//	(x + n)->mauso = a.mauso;
//	n++;
//}
//
//int main()
//{
//	phanso* mang = new phanso[100];
//	int sopt = 0;
//	phanso a;
//	
//	
//	nhapmang(mang, sopt);
//	xuatmang(mang, sopt);
//	chen(mang, sopt, a);
//	xuatmang(mang, sopt);
//
//}
int* myReference()

{
	int ref = 69;

	return &ref;
}
int* doubleValue(int x)
{
	int value{ x * 2 };
	return &value; // return value by address here
} 
int main()
{
	int p=69;
	cout << "       " <<myReference();
}