//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	public:
	long long countTriplets(long long arr[], int n, long long sum)
	{
	    // Your code goes here
	    sort(arr , arr +n);
	    
	    long long count = 0;
	    
	    for(int i = 0; i<n; i++)
	    {
	        int start = i+1;
	        int end = n-1;
	        
	       // long long curr=sum-arr[i];
	        
	        if(i>0 && arr[i]==arr[i-1])
	        continue;
	        
	        while(start<end)
	        {
                long long temp = arr[i] +arr[start] +arr[end];
	            if(temp<sum)
	            {
	                count+=end-start;
	                start++;
	            }
                else 
	                end--;
	        }
	    }
	    return count ;
	    
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
    	long long sum;
        cin>>n>>sum;
        long long arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
	    

       

        Solution ob;
        cout << ob.countTriplets(arr, n, sum) ;
	   
        
	    cout << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends