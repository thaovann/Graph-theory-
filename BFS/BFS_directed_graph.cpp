#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

const int MAXN = 1001;
set<int> adj[MAXN];
bool visited[MAXN];

void input(int &n, int &m)
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].insert(v);
	}
	fill(visited, visited + MAXN, false);
}

void bfs(int u)
{
	queue<int> q;
	q.push(u);
	visited[u] = true;

	while (!q.empty())
	{
		int v = q.front();
		q.pop();
		cout << v << " ";
		for (int x : adj[v])
		{
			if (!visited[x])
			{
				q.push(x);
				visited[x] = true;
			}
		}
	}
}

int main()
{
	int n, m;
	input(n, m);
	bfs(1);
	return 0;
}
