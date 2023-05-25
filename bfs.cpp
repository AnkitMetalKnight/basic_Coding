/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> adj[100001];
int dist[100001];
int vis[100001];

void bfs(int src)
{
    queue <int> q;
    q.push(src);
    vis[src]=1;
    dist[src]=0;
    
    while(!q.empty())
    {
        int curr=q.front();
        q.pop();
        
        for(int child:adj[curr])
        {
            if(vis[child]==0)
            {
                q.push(child);
                vis[child]=1;
                dist[child]=dist[curr]+1;
                
                
            }
        }
    }
    
}

int main()
{
int tc,n,m,a,b;

cin>>tc;
while(tc--)
{
cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        vis[i]=0;
        adj[i].clear();
        
    }
    
    for(int i=1;i<=m;i++)
    {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        
    }
    bfs(1);
    cout<<dist[n]<<"\n";
    
}
    return 0;
}
