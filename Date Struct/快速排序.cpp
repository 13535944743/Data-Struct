#include <iostream>
#include <stdlib.h>
using namespace std;
int a[100010];
void swap(int &a, int &b)
{
    int temp = b;
    b = a;
    a = temp;
}
int Partition(int low, int high)
{
    a[0] = a[low];
    int pivotkey = a[low];
    int temp;
    while (low < high)
    {
        while (low < high && a[high] >= pivotkey)
        {
            high--;
        }
        swap(a[low], a[high]);

        while (low < high && a[low] <= pivotkey)
        {
            low++;
        }
        swap(a[low], a[high]);
    }
    a[low] = a[0];
    return low;
}
void QSort(int low, int high)
{
    if (low < high)
    {
        int pivotloc = Partition(low, high);
        QSort(low, pivotloc - 1);
        QSort(pivotloc + 1, high);
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
    QSort(1, n);
    for (int i = 1; i <= n; i++)
    {
        cout << a[i];
        if (i == n)
        {
            cout << endl;
        }
        else
        {
            cout << " ";
        }
    }
}