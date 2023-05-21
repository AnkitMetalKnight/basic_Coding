/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

vector <int> adj[100001];

int vis[100001];
int col[100001];

bool dfs(int node, int c)
{
    vis[node]=1;
    col[node]=c;
    
    for(int child:adj[node])
    {
        if(vis[child]==0)
        {
            if(dfs(child,c^1)==false)
            return false;
            
        }
        else if(col[child]==c)
        return false;
    }
    return true;
    
}

int main()
{
dfs(1,0);
    return 0;
}
