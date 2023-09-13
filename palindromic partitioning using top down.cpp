//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    int t[501][501];
    
    int palindromicPartition(string str)
    {
        // code here
        memset(t,-1,sizeof(t));
        return solve(str,0,str.length()-1);
        
    }
    
    int solve(string str, int i, int j)
    {
        if(i>=j)
        return 0;
        else if(isPalindrome(str, i, j)==true)
        return 0;
        
        if(t[i][j]!=-1)
        return t[i][j];
        
        int mn = INT_MAX;
        
        int left = 0,right = 0;
        for(int k = i; k<j; k++)
        {
            if(t[i][k]!=-1)
            left = t[i][k];
            else
            {
                left = solve(str, i, k);
                t[i][k]=left;
            }
            
            if(t[k+1][j]!=-1)
            right = t[k+1][j];
            else
            {
                right = solve(str, k+1, j);
                t[k+1][j]=right;
            }
            
            int temp = left + right + 1;
            if(temp<mn)
            mn = temp;
        }
        return t[i][j] = mn;
    }
    
    bool isPalindrome(string str, int i, int j)
    {
        if(i>=j)
        return true;
        
        while(i<j)
        {
            if(str[i]!=str[j])
            return false;
            i++;
            j--;
        }
        return true;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends