//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
     long count(int coins[], int N, int sum) {

        // code here.
        
         long t[sum+1] ;
        
        t[0] = 1;
        
        for(int i = 1;i<=sum;i++)
        t[i] = 0;
        
        for(int j = 0;j <N ;j++)
        {
            for(int i = coins[j]; i<=sum;i++)
            {
                t[i]+= t[i-coins[j]];
            }
        }
        
        return t[sum];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends