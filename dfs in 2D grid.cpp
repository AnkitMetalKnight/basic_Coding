/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

bool vis[1000][1000];
int N,M;


bool isValid(int x, int y)
{
    if(x<1 || x>N || y<1 || y>M)
    return false;
    
    if(vis[x][y]==1)
    return false;
    
    return true;
}

int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};


void dfs(int x,int y)
{
    vis[x][y]=1;
    
    cout<<x<<" , "<<y<<endl;
    
    for(int i=0;i<=3;i++)
    {
        if(isValid(x + dx[i] , y + dy[i]))
        dfs(x + dx[i] , y + dy[i]);
    }
    
    
    // if(isValid(x-1,y))
    // dfs(x-1,y);
    
    // if(isValid(x,y+1))
    // dfs(x,y+1);
    
    // if(isValid(x+1,y))
    // dfs(x+1,y);
    
    // if(isValid(x,y-1))
    // dfs(x,y-1);
    
    
}

int main()
{
   cin>>N>>M;
   dfs(1,1);
   
    return 0;
}
