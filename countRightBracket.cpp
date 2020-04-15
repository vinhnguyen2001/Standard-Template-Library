#include<iostream>
using namespace std;
long double  gt(int n) {
    long double s = 1;
    for (int i = 2; i <= n; ++i)s *= i;
    return s;
}
int countRightBracket(int n)
{
    if (n == 0)return 0;
    if (n % 2)return 0;
    n = n / 2;
    long double a = gt(2 * n);
    long double b = gt(n) * gt(n + 1);
    return a / b;
}

int main()
{
    cout << countRightBracket(4);

}