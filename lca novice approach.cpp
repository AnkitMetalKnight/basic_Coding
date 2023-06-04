/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int lca(int a, int b)
{
    d=level[b]-level[a];
    
    while(d--)
    b=par[b];
    
    if(a==b)
    return a;
    
    while(par[a]!=par[b])
    {
        a = par[a] ,  b = par[b];
    }
    return par[a];
}
int main()
{
    cout<<"Hello World";

    return 0;
}
