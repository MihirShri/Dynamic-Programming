#include <iostream>

using namespace std;

int max(int a, int b) {return a > b ? a : b;}

int knapsack(int wt[], int val[], int c, int n)
{
	int t[n+1][c+1];

	//Initialization
	for (int i = 0; i <= n; i++)
		t[i][0] = 0;

	for (int i = 1; i <= c; i++)
		t[0][i] = 0;

	for (int i = 1; i < n + 1; ++i)
	{
		for (int j = 1; j < c + 1; ++j)
		{
			if (wt[i-1] <= j)													//If weight of the object is less than the capacity
				t[i][j] = max((val[i-1] + t[i-1][j-wt[i-1]]), t[i-1][j]);		//2 choices: either include or dom't include

			else																//If weight of the object if greater than the capacity
				t[i][j] = t[i-1][j];											//Don't select
		}
	}

	cout << "The maximum profit is: ";

	return t[n][c];
}

int main()
{
	int wt[] = {30, 16, 20, 4, 10};
	int val[] = {250, 100, 150, 100, 50};
	int c = 50;

	cout << knapsack(wt, val, c, 5) << endl;

	return 0;
}
