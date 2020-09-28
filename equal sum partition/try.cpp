#include <iostream>
#include <vector>

using namespace std;

int solve(int A, vector<int> B)
{
    int count[A]={0},s=0;

    for(int i=0;i<A;i++)
        s=s+B[i];

    if(s%3!=0)
        return 0;

    s=s/3;

    int ss=0;
    
    for(int j=A-1;j>=0;j--)
    {
        ss=ss+B[j];

        if(ss==s)
            count[j]=1;
    }

    for(int k=A-2;k>=0;k--)
        count[k]+=count[k+1];

    int ans = 0; 
    ss = 0; 
      
    // Calculating answer using original 
    // and cnt array. 
    for (int i = 0 ; i+2 < A ; i++) 
    { 
        ss += B[i]; 
        if (ss == s) 
            ans += count[i + 2]; 
    }

    return ans;
}

// main function for 3-partition problem
int main()
{
	// Input: set of integers
	std::vector<int> v = {1, 2, 3, 0, 3};

	cout << solve(5, v);

	return 0;
}