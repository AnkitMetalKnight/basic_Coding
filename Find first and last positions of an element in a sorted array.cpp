//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
vector<int> find(int arr[], int n , int x )
{
    // code here
    int low=0 , high=n-1;
    vector<int>v(2,-1);
    while(low<=high){
        if(arr[low]==x){
            v[0]=low;
            break;
        }
        else low++;
        
    }
    while(high>=0){
        if(arr[high]==x){
            v[1]=high;
            break;
        }
        else high--;
    }
    
    return v;
}

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends