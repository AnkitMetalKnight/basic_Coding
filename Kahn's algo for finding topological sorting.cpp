/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include<queue>

using namespace std;

vector <int>adj[100];
vector <int> res;
//int vis[100];
int in[100];

void kahn(int n)
{
    queue<int> q;
    for(int i=1;i<=n;i++)
    {
        if(in[i]==0)
        q.push(i);
    }
    
    while(!q.empty())
    {
        int curr=q.front();
        res.push_back(curr);
        q.pop();
        for(int node:adj[curr])
        {
            in[node]--;
            
            if(in[node]==0)
            {
                q.push(node);
                
            }
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
       in[y]++;
   }
   kahn(n);
   
    for(int node:res)
    cout<<node<<"  ";
    
    return 0;
}
