//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    
	    int range = 0;
	    for(int i = 0; i<n;i++)
	    range +=arr[i];
	    
	    
	    bool t[n+1][range+1];
	    
	    for(int i = 0; i< n+1; i++)
	    {
	        for(int j = 0; j<range+1; j++ )
	        {
	            if(i==0)
	            t[i][j]=false;
	            if(j==0)
	            t[i][j]=true;

	        }
	    }
	    
	    for(int i = 1; i< n+1; i++)
	    {
	        for(int j = 1; j<range+1; j++ )
	        {
	            if(arr[i-1]<=j)
	            t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
	            else
	            t[i][j] = t[i-1][j];
	        }
	    }
	    
	    int mn = INT_MAX;
	    for(int j = 0; j<range+1; j++)
	    {
	        if(t[n][j]==true)
	        mn = min(mn,abs(range-(2*j)));

	    }

	    
	    return mn;
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends