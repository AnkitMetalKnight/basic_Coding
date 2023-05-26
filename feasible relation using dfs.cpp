/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>


using namespace std;

vector <int> adj[1000001];
int vis[1000001];
int cc[1000001];
int curr_cc;

void dfs(int num)
{
    vis[num]=1;
    cc[num]=curr_cc;
    
    for(int child:adj[num])
    {
        if(vis[child]==0)
        {
            dfs(child);
        }
    }
}

int main()
{
  int tc,n,m,a,b;
  string op;
  
  cin>>tc;
  while(tc--)
  {
      curr_cc=0;
      vector <pair<int,int>> edgeList;
      
      cin>>n>>m;
      
      for(int i=1;i<=n;i++)
      {
          adj[i].clear();
          vis[i]=0;
          
      }
      
     for(int i=1;i<=m;i++)
{
    cin>>a>>op>>b;
    if(op=="=")
      {
          adj[a].push_back(b);
          adj[b].push_back(a);   
      }
      else
      edgeList.push_back({a,b});
}

for(int i=1;i<=n;i++)
{
    if(vis[i]==0)
    {
        curr_cc++;
        dfs(i);
    }
}


bool flag= true;

for(int i=0;i<edgeList.size();i++)
{
    int k=edgeList[i].first;
    int l=edgeList[i].second;
    
    if(cc[k]==cc[l])
    {
        flag=false;
        break;
    }
}
if(flag==true)
cout<<"YES\n";
else
cout<<"NO\n";

  }

    return 0;
}
