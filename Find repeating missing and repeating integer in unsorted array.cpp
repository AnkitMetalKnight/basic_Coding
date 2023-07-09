//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code herem
        vector <int> v;
        int a[n+1] = {0};
        
        for(int i =0 ;i<n;i++)
        {
            a[arr[i]]++;
            
        }
        for(int i =1 ;i<=n;i++)
        {
            if(a[i]>1)
            v.push_back(i);
        }
        for(int i= 1;i<=n;i++)
        {
            if(a[i]==0)
            v.push_back(i);
            
        }
        return v;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends