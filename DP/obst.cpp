#include <bits/stdc++.h>
using namespace std;

int sum(int freq[], int i, int j)
{
	int s = 0;
	for (int k = i; k <= j; k++)
	s += freq[k];
	return s;
}

int optimalSearchTree(int keys[], int freq[], int n)
{

	int costdp[n][n];
	for (int i = 0; i < n; i++)
		costdp[i][i] = freq[i];

	for (int L = 2; L <= n; L++)
	{

		for (int i = 0; i <= n-L+1; i++)
		{
			int j = i+L-1;
			costdp[i][j] = INT_MAX;
			int off_set_sum = sum(freq, i, j);

			
			for (int r = i; r <= j; r++)
			{
			int c = ((r > i)? costdp[i][r-1]:0) +
					((r < j)? costdp[r+1][j]:0) +
					off_set_sum;
			if (c < costdp[i][j])
				costdp[i][j] = c;
			}
		}
	}
	return costdp[0][n-1];
}


int main()
{
	int keys[] = {10, 12, 20};
	int freq[] = {34, 8, 50};
	cout << optimalSearchTree(keys, freq, 3);

}