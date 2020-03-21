#include<iostream>
#include<vector>
using namespace std;
/*
Hải có hai số nguyên dương a và b.
Hải muốn đếm có bao nhiêu số k sao cho k là bội của a đồng thời là ước của b.
Ví dụ:

Với a = 4, b = 36, thì countNumbers(a,b) = 3.
Giải thích: 3 số đó là 4,12 và 36.
Với a =6, b = 10, thì countNumbers(a,b) = 0.
https://codelearn.io/training/detail?id=670075

*/
int isPrime(int n)
{
    int flag = 1;
    if (n == 1) return 1;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            flag = 0;
            break;
        }
    }
    if (flag == 0)return 0;
    else if (flag == 1) return 1;
}
int divisorNumbers(int n)
{
    int icount;
    int result = 1;

    for (int i = 2; i <= n; i++)
    {
        icount = 0;
        while (n % i == 0)
        {
            ++icount;
            n /= i;
        }
        if (icount)
        {
            if (icount >= 1)
            {
                icount++;
                result *= icount;
            }
        }
    }
    return  result;
}
int countNumbers(int a, int b)
{
    int x = b / a;
    if (a == b) return 1;
    if (a > b / 2 || a < b && x == 1) return 0;
    else if (isPrime(x) == 1 || a == b / 2) return 2;

    else if (isPrime(x) == 0)
    {
        return divisorNumbers(x);
    }
}
 int countNumbers0(int a, int b)
    { // de hieu nhung chua toi uu duoc thoi gian
        int icount = 0;
        if (b % a != 0)
        {
            for (int i = a; i <= b / 2; i += a)
            {
                if (round(b % i) == 0 && round(i % a) == 0)
                {
                    icount++;
                }
            }
        }
        //them y tuong chu ko giup ich gi nhieu 
        /*
        Phương pháp là đếm số lượng ước của b/a NẾU b chia hết cho a.

        Giả sử ta có một số x là ước của b và là bội của a => b = k.x và x = l.a với k và l là các số nguyên. Khi đó b = k.x = k.l.a <=> k.l = b/a. Vậy k và l đều là ước của b/a, và do phép nhân có tính giao hoán nên k.l = l.k, tức là mình chỉ cần đếm số lượng ước của b/a là đủ.

       Nếu b không chia hết cho a thì ta không thể tìm được k và l nguyên sao cho k.l = b/a.
        else if (b % a == 0)
        {
            int temp = b / a;
            for (int i = 1; i <= temp; i++)
            {
                if (round(temp % i) == 0) icount++;
            }
        }

        return icount;
        */
    }
int main()
{
    std::cout << "  " << countNumbers(4,4);
}