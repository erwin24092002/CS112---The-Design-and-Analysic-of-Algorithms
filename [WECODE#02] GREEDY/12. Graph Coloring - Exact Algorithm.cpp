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
	vector<pll> degree;  //first->idx, second->degree
	vector<ll> sol;
	vector<ll> opt_sol;
	ll opt_color = 16777215;
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
		degree[i].first = i;
		degree[i].second = 0;
	}
	adj_matrix.resize(v, vector<ll>(v, 0));

	while (e--)
	{
		string u, i;
		cin >> u >> i;
		adj_matrix[idx[u]][idx[i]] = 1;
		adj_matrix[idx[i]][idx[u]] = 1;
		degree[idx[u]].second++;
		degree[idx[i]].second++;
	}
}

void Graph::coloring()
{
	sort(degree.begin(), degree.end(), [](pll a, pll b) {
		return a.second > b.second;
		});
	ll n = size(idx);
	sol.resize(n, -1);
	opt_sol.resize(n, -1);
	for (ll c = 0; c < n; c++)
	{
		sol[degree[0].first] = c;
		for (ll i = 1; i < n; i++)
		{
			ll v = degree[i].first;
			set<ll> adj_color;
			for (ll j = 0; j < size(idx); j++)
				if (adj_matrix[v][j] == 1 && sol[j] != -1)
					adj_color.insert(sol[j]);
			for (ll j = 0; j < n; j++)
			{
				if (adj_color.find(j) == adj_color.end())
				{
					sol[v] = j;
					break;
				}
			}
		}
		if (*max_element(sol.begin(), sol.end()) < opt_color)
		{
			opt_sol = sol;
			opt_color = *max_element(sol.begin(), sol.end());
		}
		sol.resize(n, -1);
	}
}

vector<ll> Graph::getColor()
{
	return opt_sol;
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
