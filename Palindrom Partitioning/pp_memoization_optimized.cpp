#include <iostream>
#include <climits>
#include <cstring>

using namespace std;

int t[1001][1001];

bool isPalindrome(string arr, int i, int j)
{
	while (i < j)
	{
		if (arr[i] != arr[j])
			return false;

		i++;
		j--;
	}
	return true;
}

int NoOfPartitions(string arr, int i, int j)
{
	if (i >= j)
		return 0;

	if (t[i][j] != -1)
		return t[i][j];

	if (isPalindrome(arr, i, j))
		return 0;

	int mn = INT_MAX;
	int left, right;

	for (int k = i; k < j; k++)
	{
		if (t[i][k] != -1)
			left = t[i][k];

		else
		{
			left = NoOfPartitions(arr, i, k);
			t[i][k] = left;
		}

		if (t[k+1][j] != -1)
			right = t[k+1][j];

		else
		{
			right = NoOfPartitions(arr, k+1, j);
			t[k+1][j] = right;
		}

		int tempans = 1 + left + right;

		if (tempans < mn)
			mn = tempans;
	}

	return t[i][j] = mn;
}

int main()
{
	string arr = "ababbbabbababa";

	memset(t, -1, sizeof(t));

	cout << "The minimum number of parttions required to make a string Palindrome is " << NoOfPartitions(arr, 0, arr.length() - 1) << endl;

	return 0;
}
