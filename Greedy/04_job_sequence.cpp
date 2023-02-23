#include <bits/stdc++.h>
using namespace std;

class Job
{
public:
    int profit, dead;

    Job(int profit, int dead)
    {
        this->profit = profit;
        this->dead = dead;
    }
};

bool cmp(Job j1, Job j2)
{
    return j1.profit > j2.profit;
}

vector<int> jobSelection(Job arr[], int n)
{
    sort(arr, arr + n, cmp);

    int dead = 0, profit = 0;
    bool done[n] = {0};

    for (int i = 0; i < n; i++)
    {
        for (int j = min(n, arr[i].dead - 1); j >= 0; j--)
        {
            if (done[j] == false)
            {
                profit += arr[i].profit;
                dead++;
                done[j] = true;
                break;
            }
        }
    }
    return {profit, dead};
}

int main()
{
    Job arr[] = {Job(70, 4), Job(80, 1), Job(30, 1), Job(100, 1)};
    vector<int> res = jobSelection(arr, 4);
    for (int x : res)
    {
        cout << x << " ";
    }
}