#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>

using namespace std;

int static t[1001][1001];

int max(int a, int b) {return a > b ? a : b;}

int lcs(string x, string y, int m, int n)
{
	if (m == 0 || n == 0)
		return 0;

	if (t[m][n] != -1)
		return t[m][n];

	else if (x[m-1] == y[n-1])
		return t[m][n] = 1 + lcs(x, y, m-1, n-1);

	else
		return t[m][n] = max(lcs(x, y, m-1, n), lcs(x, y, m, n-1));
}

int main()
{
	memset(t, -1, sizeof(t));

	string x = "abcdgh";
	string y = "abedfhr";

	cout << "The length of the Longest Common Subsequence (LCS) is: " << lcs(x, y, x.size(), y.size()) << endl;

	return 0;
}
