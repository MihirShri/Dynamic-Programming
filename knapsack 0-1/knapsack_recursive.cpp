#include <iostream>

using namespace std;

int max(int a, int b) {return a > b ? a : b;}

int knapsack(int wt[], int val[], int c, int n)
{
	if (n == 0 || c == 0)
		return 0;

	if (wt[n - 1] <= c)																					//If weight of the object is less than the capacity
		return max(val[n - 1] + knapsack(wt, val, c - wt[n - 1], n - 1), knapsack(wt, val, c, n - 1));  //2 choices: either include or dom't include

	else																								//If weight of the object if greater than the capacity
		return knapsack(wt, val, c, n - 1);																//Don't select
}

int main()
{
	int wt[] = {16, 4, 20, 30};
	int val[] = {100, 100, 150, 250};
	int c = 50;

	cout << "The maximum profit is: " << knapsack(wt, val, c, 4) << endl;;

	return 0;
}
