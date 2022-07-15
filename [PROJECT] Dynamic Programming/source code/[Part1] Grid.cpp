#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll>pll;
typedef pair<ld, ld>pld;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll n, m;
	cin >> n >> m;
	vector <vector<ll>>a(n, vector<ll>(m));
	for (ll i = 0; i <= n - 1; i++)
		for (ll j = 0; j <= m - 1; j++)cin >> a[i][j];
	vector<vector<ll>>d(n, vector<ll>(m,LLONG_MAX));
	for (ll j = 0; j <= m - 1; j++)
		d[0][j] = a[0][j];
	for (ll i = 1; i <= n - 1; i++)
	{
		for (ll j = 0; j <= m - 1; j++)
		{
			d[i][j] = d[i - 1][j]+a[i][j];
			if (j - 1 >= 0)
				d[i][j] = min(d[i][j], d[i - 1][j - 1] + a[i][j]);
			if(j+1<=m-1)
				d[i][j] = min(d[i][j], d[i - 1][j + 1] + a[i][j]);
		}
	}
	ll ma = LLONG_MAX;
	for (ll i = 0; i <= m - 1; i++)
		ma = min(ma, d[n - 1][i]);
	cout << ma;
	return 0;
}