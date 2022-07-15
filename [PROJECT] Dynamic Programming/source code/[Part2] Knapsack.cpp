#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

struct item
{
	ll w;  // weight
	ll v;  // value
};

vector<item> items;
vector<vector<ll>> d;
vector<ll> sol;


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll n, W;
	cin >> n;
	items.resize(n + 1);
	for (ll i = 1; i <= n; i++)
		cin >> items[i].w;
	for (ll i = 1; i <= n; i++)
		cin >> items[i].v;
	cin >> W;

	d.resize(n + 1, vector<ll>(W + 1, 0));
	for (ll i = 0; i <= n; i++)
	{
		for (ll j = 0; j <= W; j++)
		{
			if (i == 0 || j == 0)
				d[i][j] = 0;
			else if (items[i].w > j)
				d[i][j] = d[i - 1][j];
			else
				d[i][j] = max(d[i - 1][j], items[i].v + d[i - 1][j - items[i].w]);
		}
	}

	sol.resize(n + 1);
	ll res = d[n][W];
	ll m = W;
	for (ll i = n; i >= 1; i--)
	{
		if (res == 0)
			break;
		else if (res == d[i - 1][m])
			sol[i] = 0;
		else
		{
			sol[i] = 1;
			res -= items[i].v;
			m -= items[i].w;
		}
	}

	cout << d[n][W] << endl;
	for (ll i = 1; i <= n; i++)
		cout << setw(2) << sol[i];

	return 0;
}