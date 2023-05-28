/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include<vector>

using namespace std;

vector <int> adj[100001];
int vis[100001];
int subSize[100001];
int curr;


int dfs(int node)
{
    vis[node]=1;
    curr=1;
    
    for(int child:adj[child])
    {
        if(vis[node]==0)
        {
            curr+=dfs(node);
        }
    }
    subSize[node]=curr;
    return curr;
}
int main()
{

int d=dfs(1);

    return 0;
}
