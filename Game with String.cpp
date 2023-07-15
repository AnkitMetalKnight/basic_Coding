//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        // code here
        unordered_map<char,int> m;
        
        for(auto c :s)
        m[c]++;
        
        priority_queue<int> p;
        
        for(auto i: m)
        p.push(i.second);
        
        while(k--)
        {
            p.push(p.top()-1);
            p.pop();
            
        }
        while(!p.empty())
        {
            k+=p.top()*p.top();
            p.pop();
        }
        return k+1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends