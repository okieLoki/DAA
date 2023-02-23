#include <iostream>
using namespace std;

int binarySearch(int *arr, int n, int key)
{
    int s = 0;
    int e = n - 1;

    int mid = s + (e - s) / 2;

    while (s <= e)
    {
        if (key == arr[mid])
        {
            return mid;
        }
        if (key > arr[mid])
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return -1;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    cout << binarySearch(arr, 5, 2);
}