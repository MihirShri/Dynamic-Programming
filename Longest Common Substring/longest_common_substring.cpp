#include <iostream>

using namespace std;

int lcs(string x, string y, int m, int n)
{
	int t[m+1][n+1];

	for (int i = 0; i <= m; i++)
		t[i][0] = 0;

	for (int i = 1; i <= n; i++)
		t[0][i] = 0;

	for (int i = 1; i < m + 1; ++i)
	{
		for (int j = 1; j < n + 1; ++j)
		{
			if (x[i-1] == y[j-1])
				t[i][j] = 1 + t[i-1][j-1];

			else
				t[i][j] = 0;
		}
	}

	int max = 0;

	cout << "The length of the Longest Common Substring is: ";

	for (int i = 1; i < m + 1; ++i)
	{
		for (int j = 1; j < n + 1; ++j)
		{
			if (t[i][j] > max)
				max = t[i][j];
		}
	}

	return max;
}

int main()
{
	string x = "aacfe";
	string y = "aaabcde";

	cout << lcs(x, y, x.size(), y.size()) << endl;

	return 0;
}
