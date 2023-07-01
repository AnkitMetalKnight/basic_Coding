//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

	void rearrange(int arr[], int n) {
	    
	    // code here
	    
	    int i = 0, j = 0;
	    int temp[n];
	    int k = 0;

    while (i < n && j < n)
    {
        if (arr[i] < 0 && arr[j] >= 0)
        {
            temp[k++] = arr[j];
            temp[k++] = arr[i]; 
            // cout << arr[j] << " " << arr[i] << " ";
            i++;
            j++;
        }
        else if (arr[i] < 0 && arr[j] < 0)
            j++;
        else
            i++;
            
            if((i==n && j!=n)  || (i!=n && j==n))
            break;
	}
    while (i < n)
    {
        if (arr[i] < 0)
        {
            temp[k++] = arr[i];
            // cout << arr[i] << " ";
            i++;
        }
        else
        {
            i++;
        }
    }
    while (j < n)
    {
        if (arr[j] >= 0)
        {
            temp[k++] = arr[j];
            // cout << arr[j] << " ";
            j++;
        }
        else
        {
            j++;
        }
    }
    for(int i = 0;i<n;i++)
    arr[i] = temp[i];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.rearrange(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends