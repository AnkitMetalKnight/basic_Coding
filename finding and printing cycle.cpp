#include <iostream>
#include <vector>

using namespace std;

vector <int> adj[100];
int vis[100];
vector <int> temp;
bool dfs(int node, int par)
{
    vis[node]=1;
    temp.push_back(node);
    for(int v:adj[node])
    {
        if(vis[v]==0)
      {  
          if(dfs(v,node)==true)
          return true;
      }
      else if(v!=par)
      {
          temp.push_back(v);
          return true;
      }
    }
    temp.pop_back();
    return false;
}

int main()
{
    
dfs(1,-1);
    return 0;
}
