#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int max(int a, int b) {return a > b ? a : b;}

int lps(string x, string y, int m, int n)
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

	cout << "Minimum number of deletions to make the string palindrome is: ";

	return t[m][n];
}

int main()
{
	string y = "agbcba";
	string x = y;
	reverse(y.begin(), y.end());

	cout << y.size() - lps(x, y, x.size(), y.size()) << endl;

	return 0;
}
