#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1001;
vector<int> adj[MAXN];
int color[MAXN];
int parent[MAXN];

void input(int &n, int &m)
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
	}
	memset(color, 0, sizeof(color));
	memset(parent, -1, sizeof(parent));
}

bool dfs(int u, int par)
{
	color[u] = 1;
	for (int v : adj[u])
	{
		if (color[v] == 0)
		{
			parent[v] = u;
			if (dfs(v, u))
				return true;
		}
		else if (color[v] == 1)
			return true;
	}
	color[u] = 2;
	return false; // Moved outside the for loop
}

int main()
{
	int n, m;
	input(n, m);

	for (int i = 1; i <= n; i++){
		if (!color[i]) {
			if(dfs(i, 0)){
				cout << "Yes\n";
				return 0;
			}
		}
	}
	cout << "No\n";
	return 0;
}
