#include <iostream>
using namespace std;

int partition(int *arr, int s, int e)
{
    int p = arr[s];

    int count = 0;

    for (int i = s + 1; i <= e; i++)
    {
        if (arr[i] <= p)
        {
            count++;
        }
    }

    int pIndex = s + count;
    swap(arr[s], arr[pIndex]);

    int i = s, j = e;

    while (i < pIndex && j > pIndex)
    {
        if (arr[i] <= p)
        {
            i++;
        }
        if (arr[j] >= p)
        {
            j--;
        }
        if (i < pIndex && j > pIndex)
        {
            swap(arr[i], arr[j]);
        }
    }
    return pIndex;
}

void quickSort(int *arr, int s, int e)
{
    if (s >= e)
    {
        return;
    }
    int p = partition(arr, s, e);
    quickSort(arr, s, p - 1);
    quickSort(arr, p + 1, e);
}

int main()
{
    int arr[] = {4, 8, 1, 0, 5};
    int n = 5;

    quickSort(arr, 0, n - 1);

    for (int x : arr)
    {
        cout << x << " ";
    }
}