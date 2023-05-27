/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

vector<int>adj[100];
int vis[100];
int low[100];
int timer=0;
int in[100];

void dfs(int node, int par)
{
    vis[node]=1;
    in[node]=low[node]=timer;
    timer++;
    
    for(int child:adj[node])
    {
        if(par==child)
            continue;
            
        if(vis[child]==1)
        {
            low[node]=min(low[node],in[child]);
        }
        else
        {
            dfs(child,node);
            
            if(low[child]>in[node])
            cout<<child<<" - "<<node<<" is a bridge.\n";
            
            low[node]=min(low[child],low[node]);
        }
    }
    
}

int main()
{
    int n,m,x,y;
    cin>>n>>m;
    
    while(m--)
    {
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1,-1);

    return 0;
}
