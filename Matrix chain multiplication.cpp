//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int m[101][101];
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        
        // for(int i = 0;i<=N;i++)
        // {
        //     for(int j = 0; j<= N;j++)
        //     {
        //         m[i][j] =-1;
        //     }
        // }
            memset(m,-1,sizeof(m));

        int ans = solve(arr, 1, N-1);
        return ans;
    }
    
    int solve(int arr[], int i, int j)
    {
        if(i>=j)
        return 0;
        
        if(m[i][j]!=-1)
        return m[i][j];
        
        int mn = INT_MAX;
        for(int k = i; k<j; k++)
        {
            
            int temp = solve(arr, i ,k) + solve(arr, k+1, j) + arr[i-1]* arr[k] *arr[j];
            if(temp<mn)
            mn = temp;
        }
        
        return m[i][j] = mn;
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
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends