//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
// Function to return Breadth First Traversal of given graph.
public:
     vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    //     // Code here
    
    vector<int> res;
    int vis[V+1];
    
    for(int i=0; i<V; ++i)
    vis[i] = 0;
    queue <int> q;
    q.push(0);
    res.push_back(0);
    vis[0]=1;
    
    while(!q.empty())
    {
        int curr=q.front();
        q.pop();
        for(auto child: adj[curr])
        {
            if(vis[child]==0)
            {
                q.push(child);
                vis[child]=1;
                res.push_back(child);
            }
        }
    }
    
    return res;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends