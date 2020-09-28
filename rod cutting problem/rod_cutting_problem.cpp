#include <iostream>

using namespace std;

int max(int a, int b) {return a > b ? a : b;}

int unbounded_knapsack(int len[], int price[], int c, int n)
{
	int t[n+1][c+1];

	for (int i = 0; i <= n; i++)
		t[i][0] = 0;

	for (int i = 1; i <= c; i++)
		t[0][i] = 0;

	for (int i = 1; i < n + 1; ++i)
	{
		for (int j = 1; j < c + 1; ++j)
		{
			if (len[i-1] <= j)
				t[i][j] = max((price[i-1] + t[i][j-len[i-1]]), t[i-1][j]);
			else
				t[i][j] = t[i-1][j];
		}
	}

	int i = n, j = c;
	cout << "Status of the objects: " << endl;
	while (i > 0)
	{
		if (t[i][j] == t[i-1][j])
		{
			i--;
		}
		else
		{
			cout << len[i-1] << " = 1 (Included)" << endl;
			j = j - len[i-1];
		}

	}

	cout << endl << "The maximum profit is: ";

	return t[n][c];
}

int main()
{
	int len[] = {1, 2, 3, 4, 5, 6, 7, 8};
	int price[] = {3, 5, 8, 9, 10, 17, 17, 20};
	int c = 8;

	cout << unbounded_knapsack(len, price, c, 8) << endl;

	return 0;
}
