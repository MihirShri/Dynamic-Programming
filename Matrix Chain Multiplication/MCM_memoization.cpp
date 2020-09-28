#include <iostream>
#include <climits>
#include <cstring>

using namespace std;

int static t[1001][1001];

int mcm(int arr[], int i, int j)
{
	if (i >= j)
		return 0;

	if (t[i][j] != -1)
		return t[i][j];

	int mn = INT_MAX;

	for (int k = i; k < j; k++)
	{
		int tempans = mcm(arr, i, k) + mcm(arr, k+1, j) + arr[i-1] * arr[k] * arr[j];

		if (tempans < mn)
			mn = tempans;
	}

	return t[i][j] = mn;
}

int main()
{
	int arr[] = {10, 20, 30, 40, 30};
	int n = 5;

	memset(t, -1, sizeof(t));

	cout << "The minimum number of multiplications required is: " << mcm(arr, 1, n-1) << endl;
}
