#include <bits/stdc++.h>
using namespace std;

class Activity
{
public:
    int start;
    int end;

    Activity(int start, int end)
    {
        this->start = start;
        this->end = end;
    }
};

void sort(Activity *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j].end > arr[j + 1].end)
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void activitySelection(Activity arr[], int n)
{
    sort(arr, n);

    int res = 1;
    int prev = 0;
    cout << "Sequence: " << arr[0].start << " ";

    for (int curr = 1; curr < n; curr++)
    {
        if (arr[curr].start >= arr[prev].end)
        {
            cout << arr[curr].start << " ";
            res++;
            prev = curr;
        }
    }
    cout << endl
         << "Total activities: " << res;
}

int main()
{
    Activity arr[] = {Activity(1, 2), Activity(3, 4), Activity(2, 3), Activity(5, 6)};
    activitySelection(arr, 4);
}