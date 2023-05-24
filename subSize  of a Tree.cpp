/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;


int dfs(int node)
{
    vis[node]=1;
    curr=1;
    
    for(int child:adj[node])
    {
        if(vis[node]==0)
        {
            curr+=dfs(node);
        }
    }
    subSize[node]=curr;
    return curr;
}
int main()
{
    cout<<"Hello World";

    return 0;
}
