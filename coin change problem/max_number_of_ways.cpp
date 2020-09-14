#include <iostream>

using namespace std;

int max(int a, int b) {return a > b ? a : b;}

int coin_change(int coins[], int sum, int n)
{
	int t[n+1][sum+1];

	for (int i = 0; i <= n; i++)
		t[i][0] = 1;

	for (int i = 1; i <= sum; i++)
		t[0][i] = 0;

	for (int i = 1; i < n + 1; ++i)
	{
		for (int j = 1; j < sum + 1; ++j)
		{
			if (coins[i-1] <= j)
				t[i][j] = t[i][j-coins[i-1]] + t[i-1][j];
			else
				t[i][j] = t[i-1][j];
		}
	}

	cout << "The maximum number of ways is: ";

	return t[n][sum];
}

int main()
{
	int coins[] = {1, 2, 3};
	int sum = 5;

	cout << coin_change(coins, sum, 3) << endl;

	return 0;
}
