#include <bits/stdc++.h>
using namespace std;

int n, m, s, t;

vector<int> adj[1001];
bool visited[1001];
int parent[1001];

void input()
{
	cin >> n >> m ;
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	cin >> s >> t;
	memset(visited, false, sizeof(visited));
}

void dfs(int u)
{
	visited[u] = true;
	for (auto &v : adj[u])
	{
		if (!visited[v])
		{
			parent[v] = u;
			dfs(v);
		}
	}
}

void find_path(int s, int t){
	memset(parent, 0, sizeof(parent));
	dfs(s);
	if(!visited[t]){
		cout << "Cant find the path from " << s << " to " << t << endl;
	}
	else{
		//truy vet duong di
		stack<int> path;
		while(t != s){
			path.push(t);
			t = parent[t];
		}

		path.push(s);
		while(!path.empty()) {
			cout << path.top() << " ";
			path.pop();
		}
	}
}


int main()
{
	input();
	find_path(s, t);
	return 0;
}
