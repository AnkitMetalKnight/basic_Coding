//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int arr[], int n){
        // Your code here
        // {1, 4, 3, 2, 6, 7}
        
        int curFar = 0,curEnd = 0;
        int cnt = 0;
        
        for(int i=0;i<n-1;i++)
        {
            curFar = max(curFar,i+arr[i]);
            
            if(i==curEnd)
            {
                cnt++;
                curEnd = curFar;
                
                if(curEnd>= n-1)
                return cnt;
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends