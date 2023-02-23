#include <bits/stdc++.h>
using namespace std;

class Item
{
public:
    int wt, val;

    Item(int wt, int val)
    {
        this->wt = wt;
        this->val = val;
    }
};

/*
bool cmp(Item a, Item b)
{
    double r1 = a.val / a.wt;
    double r2 = b.val / b.wt;

    return (r1 > r2);
}
*/

void sort(Item *arr, int n)
{
    double *ratio = new double[n];
    for (int i = 0; i < n; i++)
    {
        ratio[i] = (double)(arr[i].val / arr[i].wt);
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 1; j < n - i - 1; j++)
        {
            if (ratio[j] < ratio[j + 1])
            {
                swap(ratio[j], ratio[j + 1]);
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int knapsack(Item *arr, int n, int w)
{
    // sort(arr, arr + n, cmp);
    sort(arr, n);

    double res = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i].wt <= w)
        {
            w = w - arr[i].wt;
            res += arr[i].val;
        }
        else
        {
            res += arr[i].val * ((double)w / arr[i].wt);
            break;
        }
    }
    return res;
}

int main()
{
    Item arr[] = {Item(10, 60), Item(40, 40), Item(20, 100), Item(30, 120)};
    cout << knapsack(arr, 4, 50);
}