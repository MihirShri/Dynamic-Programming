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

	if (isPalindrome(arr, i, j))
		return 0;

	if (t[i][j] != -1)
		return t[i][j];

	int mn = INT_MAX;

	for (int k = i; k < j; k++)
	{
		int tempans = 1 + NoOfPartitions(arr, i, k) + NoOfPartitions(arr, k+1, j);

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
