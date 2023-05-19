#include<bits/stdc++.h>

using namespace std;

int vis[1001];
vector<int>adj[1001];

void dfs(int i)
{
    vis[i]=1;
    cout<<i<<"-->";
    for(int child:adj[i])
    {
        if(vis[child]==0)
        dfs(child);
        
    }
}



int main()
{

int comp_count=0;
int V;          //no. of vertices
cin>>V;


//program to count connected components
for(int i=0;i<V;i++)
{
    if(vis[i]==0)
    {
        dfs(i);
        comp_count++;
        
    }
}

return 0;
}