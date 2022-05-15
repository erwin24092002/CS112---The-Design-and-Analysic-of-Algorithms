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
	vector<pll> degree; // first->degree, second->index
	vector<ll> color;
public:
	void input(ll, ll);
	void coloring();
	vector<ll> getColor();
};

void Graph::input(ll v, ll e)
{
	degree.resize(v);
	for (ll i = 0; i < v; i++)
	{
		string s;
		cin >> s;
		idx[s] = i;
		degree[i].first = 0;
		degree[i].second = i;
	}
	adj_matrix.resize(v, vector<ll>(v, 0));
	color.resize(v, -1);
	while (e--)
	{
		string u, i;
		cin >> u >> i;
		adj_matrix[idx[u]][idx[i]] = 1;
		adj_matrix[idx[i]][idx[u]] = 1;
		degree[idx[u]].first++;
		degree[idx[i]].first++;
	}
	sort(degree.begin(), degree.end(), [](pll a, pll b) {return a > b; });
}

void Graph::coloring()
{
	ll n = size(idx);
	for (auto v : degree)
	{
		set<ll> adj_color;
		for (ll i = 0; i < n; i++)
			if (adj_matrix[v.second][i] == 1 && color[i] != -1)
				adj_color.insert(color[i]);

		ll c = 0;
		for (c = 0; c < colorn; c++)
			if (adj_color.find(c) == adj_color.end())
				break;

		color[v.second] = c;
	}
}

vector<ll> Graph::getColor()
{
	return color;
}


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll v, e;
	cin >> v >> e;

	Graph g;
	g.input(v, e);

	g.coloring();
	vector<ll> ans = g.getColor();

	for (auto i : ans)
		cout << i << " ";
	cout << endl;

	return 0;
}