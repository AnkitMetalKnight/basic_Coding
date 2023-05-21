#include <iostream>
#include <vector>
#define INF 1000000000

using namespace std;

vector <int> adj[1001];
	int vis[1001];
	int dist[1001];
	void dfs(int node, int d)
	{
		vis[node]=1;
		dist[node]=d;

		for(int child :adj[node])
		{
			if(child==0)
			dfs(child,dist[node]+1);
		}

	}

int main() {

	

	int city;
	cin>>city;

	int a;
	int b;


	for(int i=1;i<=city-1;i++)
	{
		cin>>a;
		cin>>b;

	adj[a].push_back(b);
	adj[b].push_back(a);

	}

	dfs(1,0);

	int q;
	cin>>q;
	
	int girl_city;
	int ans;

	int distance=INF;
	while(q--)
	{
		cin>>girl_city;
		if(dist[girl_city]<distance)
		distance =dist[girl_city], ans=girl_city;
		else if(dist[girl_city]==distance && girl_city<ans)
		ans=girl_city;

	}
cout<<ans;

return 0;
}
