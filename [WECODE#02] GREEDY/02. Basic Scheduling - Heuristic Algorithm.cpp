#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

void solve()
{
	ll n, m;
	cin >> n >> m;
	vector<pll> jobs(n);
	for (ll i = 0; i < n; i++)
	{
		cin >> jobs[i].first;
		jobs[i].second = i;
	}
	sort(jobs.begin(), jobs.end(), [](pll a, pll b) {return a > b; });

	vector<ll> machine(m, 0);
	vector<ll> ans(n);

	for (ll i = 0; i < n; i++)
	{
		ll mi_idx = 0;
		for (ll j = 0; j < m; j++)
		{
			if (machine[j] < machine[mi_idx])
				mi_idx = j;
		}
		machine[mi_idx] += jobs[i].first;
		ans[jobs[i].second] = mi_idx;
	}

	for (auto i : ans)
		cout << i << " ";
	cout << endl;

	return;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();

	return 0;
}