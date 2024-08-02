//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
    void solve(vector<string> &ans, string out, int x, int y, vector<vector<int>> &mat, vector<vector<bool>> &visited) {
        if(x >= mat.size() -1 && y >= mat[0].size() -1) {
            ans.push_back(out);
            return;
        }
        visited[x][y] = true;
        // Move right
        if(!visited[x][y+1] && y+1 < mat.size()) {
            solve(ans, out+'R', x, y+1, mat, visited);
        }
        // Move up
        if(!visited[x-1][y] && x - 1 >= 0) {
            solve(ans, out+'U', x - 1, y, mat, visited);
        }
        // Move down
        if(!visited[x+1][y] && x+1 < mat.size()) {
            solve(ans, out+'D', x+1, y, mat, visited);
        }
        // Move left
        if(!visited[x][y-1] && y-1 >= 0) {
            solve(ans, out+'L', x, y-1, mat, visited);
        }
        visited[x][y] = false; 
    }
  public:
    vector<string> findPath(vector<vector<int>> &mat) {
        // Your code goes here
        vector<string> ans;
        
        int x = 0;
        int y = 0;
        vector<vector<bool>> visited;
        for(int i = 0;i<mat.size();i++) {
            visited[i] = vector<bool>();
            for(int j = 0;j<mat[i].size();j++) {
                visited[i][j] = false;
            }
        }
        string out = "";
        solve(ans, out, 0,0, mat, visited);
        return ans;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends