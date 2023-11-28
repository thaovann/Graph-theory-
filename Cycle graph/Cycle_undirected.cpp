#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1001;
vector<int> adj[MAXN];
bool visited[MAXN];
int start, endd;
int parent[MAXN];

void input(int &n, int &m)
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
	memset(parent, -1, sizeof(parent));
}

bool dfs(int u, int par)
{
	visited[u] = true;
	for (int v : adj[u])
	{
		if (!visited[v])
		{
			parent[v] = u;
			if (dfs(v, u))
				return true;
		}
		else if (v != par && v != parent[u])
		{
			start = v;
			endd = u;
			return true;
		}
	}
	return false; // Moved outside the for loop
}

int main()
{
	int n, m;
	input(n, m);
	if (dfs(1, 0))
	{
		cout << "Yes, the graph contains a cycle." << endl;
		stack<int> cycle;
		cycle.push(start);
		while (endd != start)
		{
			cycle.push(endd);
			endd = parent[endd];
		}
		cycle.push(endd);
		while (!cycle.empty())
		{
			cout << cycle.top() << " ";
			cycle.pop();
		}
		cout << endl;
	}
	else
	{
		cout << "No, the graph does not contain a cycle." << endl;
	}
	return 0;
}
