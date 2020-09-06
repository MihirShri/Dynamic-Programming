#include <iostream>

using namespace std;

int subset_sum(int set[], int sum, int n)
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
			if (set[i-1] <= j)
				t[i][j] = t[i-1][j-set[i-1]] + t[i-1][j];
			else
				t[i][j] = t[i-1][j];
		}
	}

	cout << "The number of subsets is: ";

	return t[n][sum];
}

int main()
{
	int set[] = {2, 3, 5, 8, 10};
	int sum = 10;

	cout << subset_sum(set, sum, 5) << endl;

	return 0;
}
