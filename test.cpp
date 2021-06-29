#include <iostream>
#include <cstring>
using namespace std;
int n;

void display(string s[])
{
    for (int i = 0; i < n; i++)
    {
        cout << s[i] << " ";
    }
    cout << endl;
}

void Merge(string s[], string s1[], int left, int mid, int right)
{
    int i = left, j, k;
    for (j = mid + 1, k = left; i <= mid && j <= right; k++)
    {
        if (s[i] > s[j])
        {
            s1[k] = s[i++];
        }
        else
        {
            s1[k] = s[j++];
        }
    }

    while (i <= mid)
    {
        s1[k++] = s[i++];
    }

    while (j <= right)
    {
        s1[k++] = s[j++];
    }

    k = left;
    while (left <= right)
    {
        s[left++] = s1[k++];
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        string *s = new string[n + 10];
        string *s1 = new string[n + 10];
        ;
        for (int i = 0; i < n; i++)
        {
            cin >> s[i];
        }
        int flag = 0;
        for (int i = 2;; i *= 2)
        {
            if (flag)
            {
                break;
            }
            if (i >= n)
            {
                flag = 1;
            }
            for (int j = 0; j < n; j += i)
            {
                int right = j + i - 1;
                if (right > n)
                {
                    right = n - 1;
                }
                int mid = (j + right) / 2;
                if (flag == 1)
                {
                    mid = (i / 2 - 1);
                }
                Merge(s, s1, j, mid, right);
            }
            display(s1);
        }
        cout << endl;
    }
    return 0;
}