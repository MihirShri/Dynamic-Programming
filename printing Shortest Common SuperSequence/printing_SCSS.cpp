#include <iostream>
#include <vector>
#include <algorithm>

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

	int i = m, j = n;
	std::vector<char> s;

	while (i > 0 && j > 0)
	{
		if (x[i-1] == y[j-1])
		{
			s.push_back(x[i-1]);
			i--;
			j--;
		}

		else
		{
			if (t[i][j-1] > t[i-1][j])
			{
				s.push_back(y[j-1]);
				j--;
			}

			else
			{
				s.push_back(x[i-1]);
				i--;
			}
		}
	}

	while (i > 0)
	{
		s.push_back(x[i-1]);
		i--;
	}

	while (j > 0)
	{
		s.push_back(y[j-1]);
		j--;
	}

	std::reverse(s.begin(), s.end());

	cout << "The Shortest Common SuperSequence (SCSS) is: \"";

	for (auto i = s.begin(); i != s.end(); i++)
		cout << *i;

	cout << "\"" << endl << "The length of the Shortest Common SuperSequence (SCSS) is: ";

	return t[m][n];
}

int main()
{
	string x = "geek";
	string y = "eke";

	cout << x.size() + y.size() - lcs(x, y, x.size(), y.size()) << endl;

	return 0;
}
