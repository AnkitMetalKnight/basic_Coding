//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    bool subsetSumToK(int n, int k, int *arr)
    {
        vector<bool> prev(k+1, 0) , curr(k+1, 0);
        prev[0] = curr[0] = true;
        if(arr[0] <= k)     prev[arr[0]] == true;
        
        for(int ind = 1; ind <= n-1; ind++)
        {
            for(int target = 1; target <= k; target++)
            {
                bool notTake = prev[target];
                bool  take = false;
                if(arr[ind] <= target)
                take = prev[target - arr[ind]];
                
                curr[target] = take | notTake ;
            }
            prev = curr;
        }
        return prev[k];
        
    }
    int equalPartition(int N, int arr[])
    {
        // code here
         int totsum = 0;
         for(int i = 0; i<N;i++)
         {
            totsum += arr[i];
         }
         if(totsum%2!=0)
         return 0;
         
         int target = totsum/2;
         
         return subsetSumToK(N, target, arr);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends