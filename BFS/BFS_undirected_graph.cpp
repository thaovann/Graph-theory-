#include <bits/stdc++.h>
using namespace std;

int n, m;

vector<int> adj[1001];
bool visited[1001];

void input()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	memset(visited, false, sizeof(visited));
}

void bfs(int u)
{
	queue<int> q;
	q.push(u);
	visited[u] = true;

	while(!q.empty()){
		int v = q.front();
		q.pop();
		cout << v << " ";
		for(int x : adj[v]){
			if (!visited[x]) {
				q.push(x);
				visited[x] = true;
			}	
		}
	}
}

int main()
{
	input();
	bfs(1);
	return 0;
}
