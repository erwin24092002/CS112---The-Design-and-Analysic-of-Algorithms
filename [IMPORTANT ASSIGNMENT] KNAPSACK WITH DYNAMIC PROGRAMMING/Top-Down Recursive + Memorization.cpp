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
	ll result = 0;
	if (dp[n][c] != -1)
		result = dp[n][c];
	if (n == 0 || c == 0)
		return 0;
	else if (items[n].w > c)
		result = knapsack(n - 1, c);
	else
		result = max(knapsack(n - 1, c), items[n].v + knapsack(n - 1, c - items[n].w));
	dp[n][c] = result;
	return result;
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

	dp.resize(n + 1, vector<ll>(W + 1, -1));
	cout << knapsack(n, W) << endl;

	return 0;
}