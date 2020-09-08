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

	if (t[n][sum] == 1)
	{
		int i = n, j = sum;
		cout << "Status of the objects: " << endl;
		while (i > 0)
		{
			if (t[i][j] == t[i-1][j])
				cout << set[i-1] << " = Set2" << endl;
			else
			{
				cout << set[i-1] << " = Set1" << endl;
				j = j - set[i-1];
			}

			i--;
		}
		cout << endl;
	}

	return t[n][sum];
}

int main()
{
	int set[] = {1, 5, 11, 5};
	int sum = 0;

	for (int i = 0; i < 4; i++)
		sum += set[i];

	if (sum % 2 != 0)
		cout << "Not possible" << endl;
	else
	{
		if (subset_sum(set, sum/2, 4))
			cout << "Possible" << endl;
		else
			cout << "Not possible" << endl;
	}

	return 0;
}
