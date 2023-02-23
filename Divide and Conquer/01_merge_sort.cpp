#include <iostream>
using namespace std;

void merge(int *arr, int s, int e)
{
    int mid = s + (e - s) / 2;

    int len1 = mid - s + 1;
    int len2 = e - s;

    int *first = new int[len1];
    int *second = new int[len2];

    int mainArrIndex = s;

    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[mainArrIndex++];
    }
    for (int i = 0; i < len2; i++)
    {
        second[i] = arr[mainArrIndex++];
    }

    // merge two sorted arrays
    int index1 = 0, index2 = 0;
    mainArrIndex = s;

    while (index1 < len1 && index2 < len2)
    {
        if (first[index1] < second[index2])
        {
            arr[mainArrIndex++] = first[index1++];
        }
        else
        {
            arr[mainArrIndex++] = second[index2++];
        }
    }

    while (index1 < len1)
    {
        arr[mainArrIndex++] = first[index1++];
    }
    while (index2 < len2)
    {
        arr[mainArrIndex++] = second[index2++];
    }
}

void mergeSort(int *arr, int s, int e)
{
    if (s >= e)
    {
        return;
    }
    int mid = s + (e - s) / 2;

    mergeSort(arr, s, mid);
    mergeSort(arr, mid + 1, e);

    merge(arr, s, e);
}

int main()
{
    int arr[] = {0, 66, 12, 67, 10};
    int n = 5;

    mergeSort(arr, 0, n - 1);

    for (int x : arr)
    {
        cout << x << " ";
    }
}