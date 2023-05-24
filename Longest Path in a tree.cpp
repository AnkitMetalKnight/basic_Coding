/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

int maxNode,maxD;
vector <int> adj[100001];
int vis[100001];

void dfs(int node,int d)
{
    vis[node]=1;
    if(d>maxD)
    {
        maxD=d;
        maxNode=node;
    }
    
    for(int child:adj[node])
   {
       if(vis[child]==0)
       dfs(child,d+1);
   }
    
}

int main()
{
int n,a,b;
cin>>n;
for(int i=1;i<=n-1;i++)
{
    cin>>a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a);
    
}

maxD=-1;
dfs(1,0);

for(int i=1;i<=n-1;i++)
{
    vis[i]=0;
}

maxD=-1;
dfs(maxNode,0);

cout<<maxD;

    return 0;
}
