#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1001;
vector<int> adj[MAXN];
vector<int> r_adj[MAXN];
vector<bool> used;
stack<int> st;
int n, m;

void input(int &n, int &m)
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		r_adj[v].push_back(u);
	}
	used.resize(n, false);
}

void dfs1(int u)
{
	used[u] = true;
	for (int v : adj[u])
	{
		if (!used[v])
		{
			dfs1(v);
		}
	}
	st.push(u);
}

void dfs2(int u)
{
	used[u] = true;
	cout << u << " ";
	for (int v : r_adj[u])
	{
		if (!used[v])
		{
			dfs2(v);
		}
	}
}

void SCC()
{
	used.assign(n, false);
	for (int i = 1; i <= n; i++)
	{
		if (!used[i])
		{
			dfs1(i);
		}
	}
	cout << endl;

	used.assign(n, false);
	int count = 0;
	while (!st.empty())
	{
		int u = st.top();
		st.pop();
		if (!used[u])
		{
			dfs2(u);
			count++;
			cout << endl;
		}
	}
	if(count == 1)
		cout << "Do thi lien thong manh";
	else
		cout << " Do thi khong lien thong ";
}

int main()
{
	input(n, m);
	SCC();
	return 0;
}
