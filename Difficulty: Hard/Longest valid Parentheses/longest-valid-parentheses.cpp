//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxLength(string& str) {
        // code here
        int n=str.size(), o=0,c=0,ans=0;
        
        for(int i=0;i<n;i++){
            if(str[i]=='(') o++;
            else c++;
            
            if(o==c)
                ans=max(ans,o*2); // making a valid pair
            else if(c>o) //if any time no of ) > ( make their count 0
                o=c=0;
        }
        
        o=c=0;
        for(int i=n-1;i>=0;i--){
            if(str[i]=='(') o++;
            else c++;
            if(o==c)
                ans=max(ans,o*2); // making a valid pair
            else if(c<o)
                o=c=0;
        }
        return ans;
    }
    
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.maxLength(S) << "\n";
    }
    return 0;
}
// } Driver Code Ends