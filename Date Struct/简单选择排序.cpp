#include <iostream>
#include <stack>
using namespace std;
int selectMin(int a[], int i, int n)
{
    int min = i;
    for (int j = i + 1; j < n; j++)
    {
        if (a[min] > a[j])
        {
            min = j;
        }
    }
    return min;
}
void SelectSort(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int j = selectMin(a, i, n);
        if (i != j)
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
}
int main()
{
    int a[5];
    for (int i = 0; i < 5; i++)
    {
        cin >> a[i];
    }
    SelectSort(a, 5);
    for (int i = 0; i < 5; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}