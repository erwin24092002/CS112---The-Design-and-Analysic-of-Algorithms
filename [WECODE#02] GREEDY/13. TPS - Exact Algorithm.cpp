#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

class Graph
{
private:
	map<string, set<pair<string, ll>>> adj_list;
	map<string, ll> flag;
	vector<string> sol;
	string start;
	ll sol_w = 0;
	vector<string> opt_sol;
	ll opt_w = LLONG_MAX;
public:
	void input(ll, string);
	void findCycle(ll, string);
	vector<string> getSol();
};

void Graph::input(ll e, string s)
{
	while (e--)
	{
		string u, i;
		cin >> u >> i;
		ll x;
		cin >> x;
		adj_list[u].insert(make_pair(i, x));
	}
	start = s;
	ll n = size(adj_list);
	sol.resize(n + 1);
	sol[0] = s;
	opt_sol.resize(n + 1);
	opt_sol[0] = s;
	flag[s] = 1;
}

void Graph::findCycle(ll step, string s)
{
	for (auto v : adj_list[s])
	{
		if (flag[v.first])
			continue;

		sol[step] = v.first;
		flag[v.first] = 1;
		sol_w += v.second;
		if (step < size(adj_list) - 1)
			findCycle(step + 1, v.first);
		else
		{
			for (auto i : adj_list[v.first])
			{
				if (i.first == start)
				{
					sol[step + 1] = i.first;
					sol_w += i.second;
					if (sol_w < opt_w)
					{
						opt_sol = sol;
						opt_w = sol_w;
					}
					sol_w -= i.second;
				}
			}
		}
		flag[v.first] = 0;
		sol_w -= v.second;
	}
}

vector<string> Graph::getSol()
{
	return opt_sol;
}


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll e;
	cin >> e;
	string s;
	cin >> s;

	Graph g;
	g.input(e, s);
	g.findCycle(1, s);

	vector<string> ans = g.getSol();
	for (auto i : ans)
		cout << i << " ";
	cout << endl;

	return 0;
}