/*
Nguyen Duc Anh Phuc
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll>pll;
typedef pair<ld, ld>pld;

class graph
{
private:
	vector<vector<ll>>g;
	ll n;
	vector<ll> a;
	vector<vector<ll>>cnt;
public:
	void solve()
	{
		for (ll i = 1; i <= n; i++)
			if (a[i - 1] == 0)cnt[i][0]++;
			else cnt[i][1]++;
		dfs(1, -1);
		for (ll i = 1; i <= n; i++)cout << cnt[i][0] << " ";
		cout << "\n";
		for (ll i = 1; i <= n; i++)cout << cnt[i][1] << " ";
		cout << "\n";
	}
	void dfs(ll u, ll pr)
	{
		bool f = 0;
		for (auto v : g[u])
		{
			if (v == pr)continue;
			f = 1;
			dfs(v, u);
			cnt[u][0] += cnt[v][0];
			cnt[u][1] += cnt[v][1];
		}

	}
	void add(ll u, ll v)
	{
		g[u].push_back(v);
		g[v].push_back(u);
	}
	void inp(vector<ll>& aa)
	{
		a = aa;
	}
	graph(ll nn)
	{
		n = nn;
		g.resize(n + 1);
		cnt.resize(n + 1, vector<ll>(2, 0));
	}
};

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll tt;
	tt = 1;
	while (tt--)
	{
		ll n;
		cin >> n;
		graph t(n);
		for (ll i = 1; i <= n - 1; i++)
		{
			ll u, v;
			cin >> u >> v;
			t.add(u, v);
		}
		vector<ll>a(n);
		for (ll i = 1; i <= n; i++)cin >> a[i-1];
		t.inp(a);
		t.solve();
	}
	return 0;
}