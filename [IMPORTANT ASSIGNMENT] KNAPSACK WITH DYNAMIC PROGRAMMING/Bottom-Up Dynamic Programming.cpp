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
vector<vector<ll>> dp;

ll knapsack(ll n, ll c)
{
	return dp[n][c];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll n, W;
	cin >> n >> W;
	items.resize(n + 1);
	for (ll i = 1; i <= n; i++)
		cin >> items[i].w;
	for (ll i = 1; i <= n; i++)
		cin >> items[i].v;

	dp.resize(n + 1, vector<ll>(W + 1, 0));
	for (ll i = 0; i <= n; i++)
	{
		for (ll j = 0; j <= W; j++)
		{
			if (i == 0 || j == 0)
				dp[i][j] = 0;
			else if (items[i].w > j)
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = max(dp[i - 1][j], items[i].v + dp[i - 1][j - items[i].w]);
		}
	}
	cout << knapsack(n, W) << endl;

	return 0;
}