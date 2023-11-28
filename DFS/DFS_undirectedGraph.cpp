#include <bits/stdc++.h>
using namespace std;

int n, m;

vector<int> adj[1001];
bool visited[1001];

void input(){
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	memset(visited, false, sizeof(visited));
}

void dfs(int u){
	cout << u << " ";
	visited[u] = true;
	for (auto &v : adj[u]){
		if (!visited[v]){
			dfs(v);
		}
	}
}

int main(){
	input();
	dfs(1);
	return 0;
}

