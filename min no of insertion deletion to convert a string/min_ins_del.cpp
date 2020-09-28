#include <iostream>

using namespace std;

int max(int a, int b) {return a > b ? a : b;}

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
				t[i][j] = max(t[i-1][j], t[i][j-1]);
		}
	}

	return t[m][n];
}

int main()
{
	string x = "heap";
	string y = "pea";
	int m = x.size();
	int n = y.size();

	cout << "Minimum number of Deletions: " << m - lcs(x, y, m, n) << endl;
	cout << "Minimum number of Insertions: " << n - lcs(x, y, m, n) << endl;

	return 0;
}
