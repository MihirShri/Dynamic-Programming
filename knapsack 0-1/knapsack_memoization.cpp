#include <iostream>
#include <cstring>

using namespace std;

int t[101][1001];

int max(int a, int b) {return a > b ? a : b;}

int knapsack(int wt[], int val[], int c, int n)
{
	if (n == 0 || c == 0)
		return 0;

	if (t[n][c] != -1)
		return t[n][c];

	else if (wt[n - 1] <= c)
		return t[n][c] = max(val[n - 1] + knapsack(wt, val, c - wt[n - 1], n - 1), knapsack(wt, val, c, n - 1));		//Maintain a matrix for keeping track of our choices

	else
		return t[n][c] = knapsack(wt, val, c, n - 1);
}

int main()
{
	memset(t, -1, sizeof(t));

	int wt[] = {16, 4, 20, 30};
	int val[] = {100, 100, 150, 250};
	int c = 50;

	cout << "The maximum profit is: " << knapsack(wt, val, c, 4) << endl;

	return 0;
}
