#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

class Graph
{
private:
	map<string, ll> idx;
	vector<vector<ll>> adj_matrix;
	vector<ll> deg;
public:
	void input(ll, ll);
	void output();
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
	deg.resize(v);
	while (e--)
	{
		string u, i;
		cin >> u >> i;
		adj_matrix[idx[u]][idx[i]] = 1;
		adj_matrix[idx[i]][idx[u]] = 1;
		deg[idx[u]]++;
		deg[idx[i]]++;
	}
	return;
}

void Graph::output()
{
	for (auto i : deg)
		cout << i << " ";
	cout << endl;
	return;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll v, e;
	cin >> v >> e;

	Graph g;
	g.input(v, e);
	g.output();

	return 0;
}