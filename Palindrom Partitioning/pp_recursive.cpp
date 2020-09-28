#include <iostream>
#include <climits>

using namespace std;

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

	int mn = INT_MAX;

	for (int k = i; k < j; k++)
	{
		int tempans = 1 + NoOfPartitions(arr, i, k) + NoOfPartitions(arr, k+1, j);

		if (tempans < mn)
			mn = tempans;
	}

	return mn;
}

int main()
{
	string arr = "ababbbabbababa";

	cout << "The minimum number of parttions required to make a string Palindrome is " << NoOfPartitions(arr, 0, arr.length() - 1) << endl;

	return 0;
}
