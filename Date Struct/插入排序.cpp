#include <iostream>
#include <stdlib.h>
using namespace std;
int a[10010];
void InsertSort(int n)
{
    int i, j;
    for (int i = 2; i <= n; i++)
    {
        if (a[i] < a[i - 1])
        {
            a[0] = a[i];
            a[i] = a[i - 1];
            for (j = i - 2; a[0] < a[j]; j--)
            {
                a[j + 1] = a[j];
            }
            a[j + 1] = a[0];
        }
    }
}
int main(void)
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    InsertSort(n);
    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << " ";
    }
}