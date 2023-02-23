#include <iostream>
using namespace std;

int subArraySum(int arr[], int n)
{
    int sum = 0;
    int maxSum = INT32_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            sum = sum + arr[j];
            maxSum = max(sum, maxSum);
        }
        sum = 0;
    }
    return maxSum;
}

int kadane(int arr[], int n)
{
    int sum = 0;
    int maxSum = INT32_MIN;

    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
        maxSum = max(sum, maxSum);
        if (sum < 0)
        {
            sum = 0;
        }
    }
    return maxSum;
}

int main()
{
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    cout << subArraySum(arr, 8) << endl;
    cout << kadane(arr, 8);
}