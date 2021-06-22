#include <iostream>
using namespace std;
int main()
{
    int n, k;
    while (cin >> n >> k)
    {
        int minute = 0;
        if (n > k)
        {
            minute = n - k;
            cout << minute << endl;
            continue;
        }
        int temp = k, minute1 = 0;
        if (temp % 2 != 0)
        {
            temp++;
        }
        while (temp > n)
        {
            if (temp % 2 != 0)
            {
                temp = (temp + 1) / 2;
                minute1 += 2;
            }
            else
            {
                temp /= 2;
                minute1++;
            }
        }
        minute1 += (n - temp);
        if (k % 2 != 0)
        {
            minute1++;
        }
        while (n * 2 <= k)
        {
            minute++;
            n *= 2;
        }
        if (n == k)
        {
            cout << minute << endl;
        }
        else
        {
            if (k % 2 == 0)
            {
                int x = k / 2;
                if (k - n <= (n - x + 1))
                {
                    minute += (k - n);
                    cout << minute << endl;
                    continue;
                }
                minute += (n - x);
                minute++;
            }
            else
            {
                int x1 = (k + 1) / 2, x2 = k / 2;
                if (n - x1 < n - x2)
                {
                    if (k - n <= (n - x1 + 1))
                    {
                        minute += (k - n);
                        cout << minute << endl;
                        continue;
                    }
                    minute += (n - x1);
                    minute++;
                }
                else
                {
                    if (k - n <= (n - x2 + 1))
                    {
                        minute += (k - n);
                        cout << minute << endl;
                        continue;
                    }
                    minute += (n - x2);
                    minute++;
                }
                minute += 1;
            }
            if (minute < minute1)
            {
                cout << minute << endl;
            }
            else
            {
                cout << minute1 << endl;
            }
        }
    }
    return 0;
}