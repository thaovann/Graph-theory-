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
void dfs(int u)
{
	visited[u] = true;
	cout << u << endl;
	for (auto &v : adj[u])
	{
		if (!visited[v])
		{
			dfs(v);
		}
	}
}

void connected(){
	int ans = 0;
	for (int i = 1; i <= n; i++){
		if (!visited[i]) {
			++ans;
			cout << " vertises belong to " << ans << " connected component" << endl;
			dfs(i);
		}
	}
	cout << "Number of connected components" << ans << endl;
}


int main()
{
	input();
	connected();
	return 0;
}
