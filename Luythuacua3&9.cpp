#include<iostream>
using namespace std;
#include<cmath>
#include<vector>
int powerOfThreeNotNine(int m, int n)
{  // round : hàm lam tròn lên 
   /*
   Công việc cần làm :
   + tạo mảng vector chứa các phần tử lũy thừa của 3 và 9
   + xem xet các phân tử này nằm trog đoạn m n
   + xem cac phantu trong mang của lũy thừa 3 có trùng với mảng của lũy thừa 9 hay không
  
   */
    vector<int>a, b;
    for (int i = 0; i < 10; i++)
    {
        a.push_back(round(pow(9, i)));
    }
    for (int i = 0; i < 20; i++)
    {
        b.push_back(round(pow(3, i)));
    }
    int c = 0, c1 = 0;
    for (int i = 0; i < b.size(); i++)
    {
        if (b[i] >= m && b[i] <= n)
        {
            c1++;
            for (int j = 0; j < a.size(); j++)
            {
                if (b[i] == a[j] && a[j] >= m && a[j] <= n)
                    c++;
            }
        }
    }
    return c1 - c;
}
int main()
{
    int m;
    int n ;
    cout << "m =";
    cin >> m;
    cout << endl;
     cout << " n=";
     cin >> n;
     cout<<" ket qua "<<powerOfThreeNotNine(m, n);
     return 0;
}