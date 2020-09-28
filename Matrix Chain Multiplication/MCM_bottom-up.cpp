#include<iostream>
using namespace std;

int main()
{
	int n = 5;
	int P[] = {10, 20, 30, 40, 30};
	int m[5][5] = {0};
	int s[5][5] = {0};
	int j, min, q;
	
	for(int d = 1; d < n-1; d++)
	{
		for(int i = 1; i < n-d; i++)
		{
			j = i+d;
			min = 32767;

			for(int k = i; k < j; k++)
			{
				q = m[i][k] + m[k+1][j] + P[i-1]*P[k]*P[j];
				if(q < min)
				{
					min = q;
					s[i][j] = k;
				}
			}
			
			m[i][j] = min;
		}
	}
	cout << m[1][n-1] << endl;
	return 0;
}