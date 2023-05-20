/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include<vector>

using namespace std;

vector <int>adj [100001];
int vis[100001];

void dfs(int node)
{
    vis[node]=1;
    
    for(int child :adj[node])
    {
        if(vis[child]==0)
        dfs(child);
    }
}


int main()
{
int n,m;

cin>>n>>m;
int a,b;

for(int i=1;i<=m;i++)
{
    cin>>a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a);
    
}

int c_count=0;

for(int i=1;i<=n;i++)
{
    if(vis[i]==0)
    {
        dfs(i);
        c_count++;
        
    }
}

//tree check part
if(c_count==1 && m==n-1)
cout<<"YES";
else
cout<<"NO";

    return 0;
}