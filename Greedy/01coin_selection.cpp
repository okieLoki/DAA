#include <bits/stdc++.h>
using namespace std;

int minCoins(int *coin, int n, int val)
{
    sort(coin, coin + n, greater<int>());
    int cnt = 0;
    for (auto i = 0; i < n; i++)
    {
        if (coin[i] <= val)
        {
            int c = val / coin[i];
            cnt = cnt + c;
            val = val - c * coin[i];
        }
        if (val == 0)
        {
            break;
        }
    }
    return cnt;
}

int main()
{
    int coin[] = {5, 10, 2, 1};
    cout << minCoins(coin, 4, 57);
    return 0;
}