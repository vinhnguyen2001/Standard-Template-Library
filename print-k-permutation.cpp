//Hàm in ra tất cả các chỉnh hợp chập k của tập hợp có n phần tử.

#include<iostream>

using namespace std;
int temp[100] = { 0 };
int address[100] = { -1 };
int dem = 1;
void print_k_permutation(int a[], int n, int k, int num = 0)
{
	for (int i = 0; i < n; i++)
	{
		if (temp[i] == 0)
		{
			temp[i] = 1;
			address[num] = i;
			cout << "\n num " << num;
			cout << "address :" << i;
			
			if (k == num + 1)
			{
				cout << "\nThu " << dem++ << ": ";
				for (int i = 0; i < k; i++)
				{
					cout << a[address[i]] << ", ";
				}
				cout << endl;
			}
			else
			{
				print_k_permutation(a, n, k, num + 1);
			}

			temp[i] = 0;
			address[num] = -1;
		}
	}
}

int main()
{
	int a[] = { 0,1,2,3 };
	int n = sizeof(a) / sizeof(a[0]);
	print_k_permutation(a, n, 4);
	return 1;
}