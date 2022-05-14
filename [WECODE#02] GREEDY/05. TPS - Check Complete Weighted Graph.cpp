#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

class Graph
{
private:
	map<string, set<string>> adj_list;
public:
	void input(ll);
	bool isCompleteGraph();
};

void Graph::input(ll n)
{
	while (n--)
	{
		string u, i;
		cin >> u >> i;
		adj_list[u].insert(i);
	}
	return;
}

bool Graph::isCompleteGraph()
{
	bool ans = true;
	ll n = size(adj_list);
	for (auto i : adj_list)
		if (size(i.second) != n - 1)
			ans = false;
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll n;
	cin >> n;
	Graph g;
	g.input(n);
	cout << (g.isCompleteGraph() ? "TRUE" : "FALSE") << endl;

	return 0;
}