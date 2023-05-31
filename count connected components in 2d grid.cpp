/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

bool vis[1000][1000];
int N,M;
int arr[1000][1000];

bool isValid(int x, int y)
{
    if(x<1 || x>N || y<1 || y>M)
    return false;
    
    if(vis[x][y]==1 || arr[x][y]==0)
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
}

int main()
{
   cin>>N>>M;
   
   for(int i=1;i<=N;i++)
   {
       for(int j=1;j<=M;j++)
       {
           cin>>arr[i][j];
           
       }
   }
   
   int cc=0;
   
  for(int i=1;i<=N;i++)
   {
       for(int j=1;j<=M;j++)
       {
           if(arr[i][j]==1 && vis[i][j]==0)
           {
               cc++;
               dfs(i,j);
           }
       }
   }
   cout<<cc<<"\n";
   
   
    return 0;
}
