#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll>pll;
typedef pair<ld, ld>pld;

void add(vector<vector<ll>>& g, ll u, ll v, ll w)
{
	g[u][v] = w;
	g[v][u] = w;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll n, m;
	cin >> n >> m;
	vector<vector<ll>>g;
	g.resize(n, vector <ll>(n, LLONG_MAX));
	for (ll i = 0; i <= m - 1; i++)
	{
		ll u, v, w;
		cin >> u >> v >> w;
		add(g, u, v, w);
	}
	ll mxmsk = 1LL << n;
	mxmsk--;
	vector<vector<ll>>d(mxmsk + 1, vector<ll>(n, LLONG_MAX));
	d[1][0] = 0;
	for (ll mask = 0; mask <= mxmsk; mask++)
	{
		for (ll i = 0; i <= n - 1; i++)
		{
			if ((mask & (1LL << i)) == 0)continue;
			for (ll j = 0; j <= n - 1; j++)
			{
				if ((mask & (1LL << j)) == 0 && g[i][j] != LLONG_MAX && d[mask][i] != LLONG_MAX)
				{
					d[mask | (1LL << j)][j] = min(d[mask | (1LL << j)][j], d[mask][i] + g[i][j]);
				}
			}
		}
	}
	for (ll i = 0; i <= mxmsk; i++)
	{
		for (ll j = 0; j <= n - 1; j++)
		{
			if (d[i][j] == LLONG_MAX)cout << setw(4) << '-';
			else cout << setw(4) << d[i][j];
		}
		cout << "\n";
	}
	return 0;
}