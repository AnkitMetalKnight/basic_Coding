#include <iostream>
#include <vector>

using namespace std;
vector<int>adj[100];
int vis[100];
int low[100];
int in[100];
int timer=0;

void IsCutpoint(int node)
{

}

void dfs(int node, int p)
{
    vis[node]=1;
    in[node]=low[node]=timer++;
    int children=0;
    
    for(int ot:adj[node])
    {
        if(ot==p)
        continue;
        
        if(vis[ot]==1)
        {
            
            low[node]=min(in[ot],low[node]);
        }
        else
        {
            dfs(ot,node);
            
            low[node]=min(low[ot],low[node]);
            
            if(low[ot]>in[node] && p!=-1)
            IsCutpoint(node);      //can use this fn to calculate no. of cutpoints
            ++children;
        }
    }
    
    if( p=-1 && children>1)
    IsCutpoint(node);
    
}


int main()
{
    int V;
    for(int i=1;i<V;i++)
{
    if(vis[i]==0)
    dfs(i,-1);
}  
return 0;
}
