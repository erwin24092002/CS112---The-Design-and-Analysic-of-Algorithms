#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

ll l;
ll n;
vector<ll> c;
vector<vector<ll>> d;
vector<vector<ll>> opt;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> l >> n;
	c.resize(n + 2);
	for (ll i = 1; i <= n; i++)
		cin >> c[i];
	c[0] = 0;
	c[n + 1] = l;

	d.resize(n + 2, vector<ll>(n + 2, LLONG_MAX));
	opt.resize(n + 2, vector<ll>(n + 2));
	for (ll i = n; i >= 0; i--)
	{
		for (ll j = i + 1; j <= n + 1; j++)
		{
			if (j == i + 1)
			{
				d[i][j] = 0;
				opt[i][j] = j;
			}
			else
			{
				for (ll k = opt[i][j - 1]; k <= min(j - 1, opt[i + 1][j]); k++)
				{
					if (d[i][k] + d[k][j] + (c[j] - c[i]) < d[i][j])
					{
						d[i][j] = d[i][k] + d[k][j] + (c[j] - c[i]);
						opt[i][j] = k;
					}
				}
			}
		}
	}

	cout << d[0][n + 1] << endl;

	return 0;
}