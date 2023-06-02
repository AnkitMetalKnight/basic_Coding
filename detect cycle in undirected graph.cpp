//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);
        stack<pair<int, int>> st;

        for (int i = 0; i < V; i++) {
            if (vis[i] == 0) {
                st.push({i, -1});
                vis[i] = 1;

                while (!st.empty()) {
                    auto curr = st.top();
                    st.pop();

                    int currentNode = curr.first;
                    int parentNode = curr.second;

                    for (int v : adj[currentNode]) {
                        if (vis[v] == 0) {
                            vis[v] = 1;
                            st.push({v, currentNode});
                        } else if (v != parentNode) {
                            return true; // Cycle detected
                        }
                    }
                }
            }
        }

        return false; // No cycle detected
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends