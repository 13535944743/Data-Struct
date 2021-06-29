#include <iostream>
using namespace std;
void HeapAdjust(int a[], int i, int n)
{
    int temp = a[i];
    for (int j = 2 * i; j <= n; j *= 2)
    {
        if (j < n && a[j] < a[j + 1])
        {
            j++;
        }
        if (!(temp < a[j]))
        {
            break;
        }
        else
        {
            a[i] = a[j];
            i = j;
        }
    }
    a[i] = temp;
}
void HeapSort(int a[], int n)
{
    for (int i = n / 2; i > 0; i--)
    {
        HeapAdjust(a, i, n);
    }
    for (int i = n; i > 1; i--)
    {
        int temp = a[1];
        a[1] = a[i];
        a[i] = temp;
        HeapAdjust(a, 1, i - 1);
    }
}
int main()
{
    int a[6];
    for (int i = 1; i <= 5; i++)
    {
        cin >> a[i];
    }
    HeapSort(a, 5);
    for (int i = 1; i <= 5; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}