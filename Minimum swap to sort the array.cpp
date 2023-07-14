//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    
	    vector<int> v(nums.begin(), nums.end());
	    
	    int cnt = 0;
	    
	    sort(v.begin(),v.end());
	    
	    unordered_map<int,int> m;
	    
	    for(int i =0;i<nums.size();i++)
	    {
	        m[v[i]]=i;
	        
	    }
	    
	    int i =0;
	    while(i<nums.size())
	    {
	        if(m[nums[i]] == i)
	        i++;
	        else
	        {
	            swap(nums[i],nums[m[nums[i]]]);
	            cnt++;
	        }
	    }
	    return cnt;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends