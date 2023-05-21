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
    int tc,n,m,a,b;
    int i=1;
    
    
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
        bool flag=true;
        
        for(int i=1;i<n;i++)
        {
        if(vis[i]==0)
        {
        bool res=dfs(i,0);
        if(res==false)
        flag=false;
            
        }
        }
        
        cout<<"Scenario #"<<i++<<":\n";
        
        if(flag==false)
        cout<<"Suspicious bugs found!\n";
        else
        cout<<"No suspicious bugs found!\n";
        
            }
    return 0;
}
