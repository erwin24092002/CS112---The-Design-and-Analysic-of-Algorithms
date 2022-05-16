#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

ll colorn = 16777215;

class Graph
{
private:
	map<string, ll> idx;
	vector<vector<ll>> adj_matrix;
	vector<ll> color;
	set<ll> used_color;
public:
	void input(ll, ll);
	ll colorSlection(string);
};

void Graph::input(ll v, ll e)
{
	for (ll i = 0; i < v; i++)
	{
		string s;
		cin >> s;
		idx[s] = i;
	}
	adj_matrix.resize(v, vector<ll>(v, 0));
	color.resize(v, -1);
	while (e--)
	{
		string u, i;
		cin >> u >> i;
		adj_matrix[idx[u]][idx[i]] = 1;
		adj_matrix[idx[i]][idx[u]] = 1;
	}
	for (ll i = 0; i < v; i++)
	{
		cin >> color[i];
		if (color[i] != -1)
			used_color.insert(color[i]);
	}
}

ll Graph::colorSlection(string v)
{
	set<ll> adj_color;
	ll v_num = size(idx);
	for (ll i = 0; i < v_num; i++)
	{
		if (adj_matrix[idx[v]][i] == 1)
			adj_color.insert(color[i]);
	}

	ll flag_color = 1;
	if (color[idx[v]] == -1)
		flag_color = 0;
	else
		for (auto i : adj_color)
			if (i == color[idx[v]])
				flag_color = 0;

	if (flag_color)
		return -1;
	else
	{
		for (auto i : used_color)
		{
			ll flag = 1;
			for (auto j : adj_color)
				if (i == j)
					flag = 0;
			if (flag)
				return i;
		}
		for (ll i = 0; i < colorn; i++)
		{
			ll flag = 1;
			for (auto j : used_color)
				if (i == j)
					flag = 0;
			if (flag)
				return i;
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll v, e, n;
	cin >> v >> e >> n;

	Graph g;
	g.input(v, e);

	while (n--)
	{
		string v;
		cin >> v;
		ll ans = g.colorSlection(v);
		cout << (ans == -1 ? "TRUE" : to_string(ans)) << endl;
	}

	return 0;
}