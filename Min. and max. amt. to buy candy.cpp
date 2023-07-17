//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        // Write Your Code here
        int mn = 0;
        int mx = 0;
        
        vector<int> v;
        
        sort(candies,candies+N);
        
        int i = 0;
        int j = N;
        
        while(i<j)
        {
            mn+=candies[i];
            i++;
            j = j-K;
            
        }
        
        reverse(candies,candies+N);
        
        
        i = 0;
        j = N;
        
        while(i<j)
        {
            mx+=candies[i];
            i++;
            j = j-K;
        }
        v.push_back(mn);
        v.push_back(mx);
        
        return v;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}
// } Driver Code Ends