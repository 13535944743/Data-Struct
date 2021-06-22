#include <iostream>
#include <stdlib.h>
using namespace std;
int a[10010];
void BInsertSort(int n)
{
    for (int i = 2; i <= n; i++)
    {
        a[0] = a[i];
        int low = 1, high = i - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (a[0] < a[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        for (int j = i - 1; j >= high + 1; j--)
        {
            a[j + 1] = a[j];
        }
        a[high + 1] = a[0];
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
    BInsertSort(n);
    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << " ";
    }
}