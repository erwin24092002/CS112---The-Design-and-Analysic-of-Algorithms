#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

void solve()
{
	ll n, m;
	cin >> n >> m;
	vector<vector<ll>> jobs(m, vector<ll>(n));
	for (ll i = 0; i < m; i++)
		for (ll j = 0; j < n; j++)
			cin >> jobs[i][j];

	vector<ll> machines(m, 0);
	vector<ll> ans(n);
	for (ll i = 0; i < n; i++)
	{
		ll mi_idx = 0;
		while (jobs[mi_idx][i] < 0)
			mi_idx++;

		for (ll j = 0; j < m; j++)
			if ((jobs[j][i] > 0) && (machines[j] + jobs[j][i] < machines[mi_idx] + jobs[mi_idx][i]))
				mi_idx = j;
		ans[i] = mi_idx;
		machines[mi_idx] += jobs[mi_idx][i];
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