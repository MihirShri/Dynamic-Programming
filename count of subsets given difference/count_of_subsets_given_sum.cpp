#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int subset_sum(vector<int> nums, int S)
{
	 int c = 0, sum = 0, n = nums.size();
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            if (nums[i] == 0)
                c++;
        }
        
        if (S > sum || (sum - S)%2 != 0)
            return 0;
        
        int s = (sum - S) / 2;
        
        int t[n+1][s+1];

        for (int i = 0; i <= n; i++)
            t[i][0] = 1;

        for (int i = 1; i <= s; i++)
            t[0][i] = 0;

        for (int i = 1; i < n + 1; ++i)
        {
            for (int j = 1; j < s + 1; ++j)
            {
                if(nums[i-1]==0)
                    t[i][j] = t[i-1][j];
                else if(j < nums[i-1])
                    t[i][j] = t[i-1][j];
                else
                    t[i][j] = t[i-1][j] + t[i-1][j-nums[i-1]];
            }
	}

	return pow(2, c) * t[n][s];
}

int main()
{
	vector<int> set = {0,0,0,0,0,0,0,0,1};
	cout << "Count of subsets whose difference of the individual sums is equal to the given difference is: " << subset_sum(set, 1) << endl;

	return 0;
}
