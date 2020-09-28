#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int max(int a, int b) {return a > b ? a : b;}

int lcs(string x, string y, int m, int n)
{
	if (m == 0 || n == 0)
		return 0;

	else if (x[m-1] == y[n-1])
		return 1 + lcs(x, y, m-1, n-1);

	else
		return max(lcs(x, y, m-1, n), lcs(x, y, m, n-1));
}

int main()
{
	string x = "abcdgh";
	string y = "abedfhr";

	cout << "The length of the Longest Common Subsequence (LCS) is: " << lcs(x, y, x.size(), y.size()) << endl;

	return 0;
}
