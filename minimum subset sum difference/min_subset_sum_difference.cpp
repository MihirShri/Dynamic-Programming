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
				t[i][j] = t[i-1][j-set[i-1]] || t[i-1][j];
			else
				t[i][j] = t[i-1][j];
		}
	}

	int s1;

	for (int i = 0; i <= sum/2; i++)
	{
		if (t[n][i] != 0)
			s1 = i;
	}

	cout << "Minimum difference is ";

	return sum - 2*s1;
}

int main()
{
	int set[] = {1, 2, 5, 7};
	int sum = 0;

	for (int i = 0; i < 4; i++)
		sum += set[i];

	cout << subset_sum(set, sum, 4) << endl;

	return 0;
}
