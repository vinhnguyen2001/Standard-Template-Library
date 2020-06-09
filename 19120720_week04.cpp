#include<iostream>
#include<algorithm>

using namespace std;

void inputArray (int*& a, int& n); // nhap mang cac so nguyen 
 
void inputArrrayFloat ( float *& a, int& n); // nhap mang cac so thuc 

int factorial(int n);

double sumS_2(int n); 

double sumS_3(int n);

double sumS_4(int n, int x);

double sumS_5(int n, int x);

bool isPrime(int n, int i );

int countNumberofPrime(int* a, int n); 

bool checkPerfectNumber(int n, int i ); 

int countPerfectNumber(int* a, int n);

void  sumEvenNumber(int* a, int n, int sum );
	
void listPosofPrime(int* a, int n); 

void listPosofPecfect(int* a, int n);

void sumS_11 (float * a, int n, float  sum); 

inline bool checkDistinctvalue(int* a, int n, int elem); 

int rCountArray(int array[], int n, int a);

int countDistinctValue(int* a, int n); 

int main() {
	
	int* a=nullptr;
	int n = 0;
	inputArray (a, n);
	int temp = 1;
	while (temp != 0) {
		int sel = 0;
		cout << endl;
		cout << " FRESS 1.	TO CHECK  FOR  THE FIRST 5 EXERCISES. " << endl;
		cout << " FRESS 6.	EXERCISE 6." << endl;
		cout << " FRESS 7.	EXERCISE 7." << endl;
		cout << " FRESS 8.	EXERCISE 8." << endl;
		cout << " FRESS 9.	EXERCISE 9." << endl;
		cout << " FRESS 10.	EXERCISE 10." << endl;
		cout << " FRESS 11.	EXERCISE 11." << endl;
		cout << " FRESS 12.	EXERCISE 12." << endl;
		cin >> sel;
		switch (sel) {

		case 1: // gop 5 bai dau tien thanh 1 phan 
		{
			cout << "\nEnter N " << endl;
			int n;
			cin >> n;
			cout << " \nEnter X " << endl;
			int x;
			cin >> x;
			cout << "\nFactorial " << n << " : " << factorial(n);
			cout << "\nSumS_2 : " << sumS_2(n);
			cout << "\nSumS_3 : " << sumS_3(n);
			cout << "\nSumS_4 : " << sumS_4(n, x);
			cout << "\nSumS_5 : " << sumS_5(n, x);
		}
		break;
		case 6:
		{
			cout << " The number of primes in the array is : " << countNumberofPrime(a, n);
			break;
		}
		case 7:
		{
			cout << " The perfect number of numbers in the array is : " << countPerfectNumber(a, n);
			break;
		}
		case 8:
		{  int sum = 0;
	    	sumEvenNumber(a, n, sum);
	     	break;
		}
		case 9:
		{
			cout << " The position of the  prime number is : ";
			listPosofPrime(a, n-1);
			break;
		}
		case 10:
		{
			cout << " The postiton of the pecfect number is : "; listPosofPecfect(a, n-1);
			break;
		}
		case 11:
		{
			float* a1;
			int n = 0;
			int sum11 = 0;
			inputArrrayFloat(a1, n);
			sumS_11(a1, n, sum11);
			if (a1 != NULL) {
				free(a1);
				a1 = nullptr;
			}
			break;
		}
		case 12:
		{
			cout << "\nThe number of distinct elements in the  array is : " << countDistinctValue(a, n);
		}
		}
	   cout<<"\nDo you want continue ?"  << "\t YES 1 " << "NO 0 " << endl;
	   cin >> temp;
	   cout << endl;
		
	}
		if (a != NULL) {
			free(a);
			a = nullptr;
		}
	
	return 0;
}

void inputArray(int*& a, int &n) {
	cout << " Enter the size of array " << endl;
	cin >> n;
	a = (int*) malloc (n * sizeof(int));
	if (a != NULL) {
		cout << " Enter the elenment of the array " << endl;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
	}
}
void inputArrrayFloat(float*& a, int& n) {
	cout << " Enter the size of array " << endl;
	cin >> n;
	a = (float *)malloc(n * sizeof(float ));
	if (a != NULL) {
		cout << " Enter the elenment of the array " << endl;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
	}
}
int factorial (int n) {
	//bai 1
	if (n == 1) return 1;
	return n * factorial (n - 1);
}

double sumS_2(int n) {
	//bai 2
	if (n == 0) return 1;
	return  1 / (double)((__int64)2 * n + 1) + sumS_2(n - 1);
}

double sumS_3(int n) {
	// bai 3
	if (n == 0) return 0.5;
	return (float)(2 * n + 1) / (2 * n + 2) + sumS_3(n - 1);
}

double sumS_4(int n, int x) {
	// bai 4
	if (x == 1 || x == 0) return n;
	if (n == 1) return x;
	return pow(x, n) + sumS_4(n - 1, x);

}

double sumS_5(int n, int x) {
	// bai 5
	if (x == 0) return 0;
	if (n == 1) return x;
	return (double)(pow(x,n) / (double(n * (n + 1) / 2))) + sumS_5(n - 1, x);
}

bool isPrime(int n, int i = 2) {
	// kiem tra so nguyen to 
	if (n % 2 == 0 && n != 2 || n == 0) return false;
	if (i * i > n) return true;
	if (n % i == 0) return false;
	return isPrime(n, i + 1);
}

int countNumberofPrime(int* a, int n) {
	// dem so nguyen to co trong  mang 
	if (n < 1) return 0;

	return countNumberofPrime(a, n - 1) + isPrime(a[n - 1]);
}

bool checkPerfectNumber(int n, int i = 1) {
	// kiem tra so hoan thien 
	static  int temp = 0;
	if (n == 0) return false;
	if (i == 1) temp = 0;

	if (i <= n / 2) {

		if (n % i == 0) temp += i;
		checkPerfectNumber(n, i + 1);

	}
	if (temp == n) return true;
	return false;
}

int countPerfectNumber(int* a, int n) {
	//dem so hoan thien co trong mang
	if (n < 1) return 0;

	return checkPerfectNumber(a[n - 1]) + countPerfectNumber(a, n - 1);
}

void  sumEvenNumber(int* a, int n, int sum = 0) {
	// tong cua cac so chan trong mang 1 chieu 
	if (n > 0) {
		if ((a[n - 1]) % 2 == 0) {
			sum += a[n - 1];
		}
	}
	else {
		cout << " The sum of even numbers in array is : " << sum << endl;
		return;
	}
	sumEvenNumber(a, n - 1, sum);
}

void listPosofPrime(int* a, int n) {
	// vi tri cua cac so nguyen to trong mang  
  static int flag = 0;
	if (n >= 0) {
		flag = 1;
		if (isPrime(a[n])) {
			cout << " " << n;
		}
		listPosofPrime(a, n-1);

	}
	if (flag == 0) cout << " Does not exist in prime number in array " << endl;
}

void listPosofPecfect(int* a, int n) {
	//  vi tri cac so hoan hao 
	int flag = 0;
	if (n >= 0) {
		flag = 1;
		if (checkPerfectNumber(a[n])) {
			cout << " " << n << endl;
		}
		listPosofPecfect(a, n - 1);
	}
	if (flag == 0) cout << " Does not exist in perfect number in  array " << endl;
}

void sumS_11(float * a, int n, float sum) {
	// tong cac so lon hon so dung truoc no trong mang 
	if (n > 1) {
		if (a[n - 1] > a[n - 2]) {
			sum += a[n - 1];
		}
		sumS_11(a, n - 1, sum);
	}
	else
	{
		cout << "\n The sum of the valuse í greater than the value that precedes it in the one -dimensinal array of numbers " << sum;
	
	}
}

inline bool checkDistinctvalue(int* a, int n, int elem) {
	// kiem tra so elem có tu 2 so tro len hay khong . Neu co return true neu khong nguoc lai
	for (int i = 0; i < n; i++) {
		if (a[i] == elem) return true;
	}
	return false;

}

int rCountArray(int array[], int n, int a)
{
	int found = 0;
	if (n < 0)
		return 0;

	if (array[n] == a)
		++found;

	return (found + rCountArray(array, n - 1, a));
}

int countDistinctValue(int* a, int n) {
	// dem co bao nhieu so phan biet trong mang 
	if (n == 1) return 1;
	int count = countDistinctValue(a, n - 1);
	if (checkDistinctvalue(a, n - 1, a[n - 1])) {
		return count;
	}
	else  return  count + 1;
}
/*
bool check(int n) {

	int sum = 0;//khai bao biem sum
	for (int i = 1; i <= n/2; i++) {
		if (n % i == 0)
			sum += i;
	}
	if (sum == n) return true; // tra ve true
	return false;
}
*/