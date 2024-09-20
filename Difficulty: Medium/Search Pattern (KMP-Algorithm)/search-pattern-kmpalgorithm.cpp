//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        void lps_calc(string &s, vector<int> &lps){
            int p=0,i=1; // p - previous lps,,, i-index
            while(i<s.size()){
                if(s[i]==s[p]){
                    lps[i]=p+1;
                    p++;
                    i++;
                }else if(p==0){
                    lps[i]=0;
                    i++;
                }else{
                    p=lps[p-1];
                }
                
            }
        }
        vector <int> search(string p, string t){
            //code here
            if(p=="")return {};
            
            vector <int> lps(p.size(),0);
            vector <int> s;
            
            lps_calc(p,lps);
            
            int i=0; // t
            int j=0; // p
            while(i<t.size()){
                if(p[j]==t[i]){
                    i++;j++;
                }
                if(j==p.size()){
                    s.push_back(i-j+1);
                    j=lps[j-1]; //move back for next occurances
                }
                else if(i<t.size() && p[j]!=t[i]){ 
                    if(j==0)
                        i++;
                    else
                        j=lps[j-1];
                }
                
            }
            
            return s;
            
        }
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        if (res.size()==0)
            cout<<-1<<endl;
        else {
            for (int i : res) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends