#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

class Graph
{
private:
	map<string, set<pair<string, ll>>> adj_list;
public:
	void input(ll);
	ll isValidCycle(vector<string>);
};

void Graph::input(ll n)
{
	while (n--)
	{
		string u, i;
		cin >> u >> i;
		ll w;
		cin >> w;
		adj_list[u].insert(make_pair(i, w));
	}
	return;
}

ll Graph::isValidCycle(vector<string> c)
{
	ll ans = 0;
	ll n = size(c);
	for (ll i = 0; i < n - 1; i++)
	{
		ll flag = 0;
		for (auto v : adj_list[c[i]])
		{
			if (c[i + 1] == v.first)
			{
				ans += v.second;
				flag = 1;
			}
		}
		if (!flag)
			return -1;
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll e, n;
	cin >> e >> n;
	Graph g;
	g.input(e);

	while (n--)
	{
		string x;
		cin >> x;
		vector<string> c;
		while (x != ".")
		{
			c.push_back(x);
			cin >> x;
		}
		ll ans = g.isValidCycle(c);
		cout << ((ans == -1) ? "FALSE" : to_string(ans)) << endl;
	}

	return 0;
}