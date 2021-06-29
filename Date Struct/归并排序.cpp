#include <iostream>
using namespace std;
void Merge(int arr[], int temp[], int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;
    int t = 0;
    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            temp[t++] = arr[i++];
        }
        else
        {
            temp[t++] = arr[j++];
        }
    }
    while (i <= mid)
    {
        temp[t++] = arr[i++];
    }
    while (j <= right)
    {
        temp[t++] = arr[j++];
    }
    t = 0;
    while (left <= right)
    {
        arr[left++] = temp[t++];
    }
}
void Msort(int arr[], int temp[], int left, int right)
{
    if (left == right)
    {
        temp[left] = arr[left];
    }
    else
    {
        int mid = (left + right) / 2;
        Msort(arr, temp, left, mid);
        Msort(arr, temp, mid + 1, right);
        Merge(arr, temp, left, mid, right);
    }
}
void MergeSort(int a[], int n)
{
    int temp[5];
    Msort(a, temp, 0, n - 1);
}
int main()
{
    int a[5];
    for (int i = 0; i < 5; i++)
    {
        cin >> a[i];
    }
    MergeSort(a, 5);
    for (int i = 0; i < 5; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}