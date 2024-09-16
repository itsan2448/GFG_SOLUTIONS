//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int perfectSum(int a[], int n, int s)
	{
        // Your code goes here
        int mod=1e9+7;
        
        vector<vector<long long>> dp(n+1,vector<long long> (s+1,0));
        for(int i=0;i<=n;i++){
            dp[i][0]=1; // for every sum = 0, we can no. of subset as {0} nullset
        }
        
        for(int i=1;i<=n;i++){ // i -> no. of elements from left we consider
            for(int j=0;j<=s;j++){ // j -> current sum 
                if(j>=a[i-1]){
                    dp[i][j]=(dp[i-1][j-a[i-1]]+dp[i-1][j])%mod;
                }else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        
        return dp[n][s];
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends