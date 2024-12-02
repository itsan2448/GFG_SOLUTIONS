//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> dir = {{-1,0},{1,0},{0,-1},{0,1},{-1,-1},{-1,1},{1,-1},{1,1}};
    
    bool search(vector<vector<char>>grid,string word,int i,int j){
        int n=grid.size();
	    int m=grid[0].size();
	   // int k;
	    int l=word.size();
	    for(auto d:dir){
	        int x=i,y=j,k;
	        for(k=0;k<l;k++){
	            if(x>=0 && y>=0 && x<n && y<m && grid[x][y]==word[k]){
	                x+=d[0];
	                y+=d[1];
	                
	            }else break;
	        }
	    if(k==l) return 1;
	    }
	    return 0;
    }
    
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    // Code here
	    int n=grid.size();
	    int m=grid[0].size();
	    vector<vector<int>> res;
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(grid[i][j]==word[0] && search(grid,word,i,j)){
	                res.push_back({i,j});
	            }
	        }
	    }
	    return res;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends