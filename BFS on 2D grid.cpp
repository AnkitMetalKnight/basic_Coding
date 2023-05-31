/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <queue>

using namespace std;

bool vis[1000][1000];
int N,M;
int dist[1000][1000];

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

void bfs(int srcX,int srcY)
{
    queue <pair <int,int>> q;
    q.push({srcX,srcY});
    vis[srcX][srcY]=1;
    dist[srcX][srcY]=0;
    
    while(!q.empty())
    {
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        
        for(int i=0;i<4;i++)
        {
            if(isValid(x+dx[i],y+dy[i]))
            {
                int newX = x+dx[i];
                int newY = y+dy[i];
                
                q.push({newX,newY});
                vis[newX][newY]=1;
                dist[newX][newY]= dist[x][y]+1;
            }
        }
    }
    

cout<<"Distance array\n";
{
    for(int i=1;i<=M;i++)
    {
        for(int j=1;j<=N;j++)
        cout<<dist[i][j]<<"  ";
        
        cout<<endl;
    }
}
}

int main()
{
    int x,y;
   cin>>N>>M;
   cin>>x>>y;
   bfs(x,y);
    return 0;
}

