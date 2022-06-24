#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

/*
* dp[i][j] là số lượng đường đi có thể đến tọa độ (i, j)
*
* CÔNG THỨC QUY HOẠCH ĐỘNG:
* dp[i][j] = dp[i - 1][j] * (map[i - 1][j] == '.') + dp[i][j - 1] * (map[i][j - 1] == '.')
* dp[i][j] = 1 if i==0 and j==0
* dp[i][j] = dp[i][j - 1] * (map[i][j - 1] == '.') if i==0
* dp[i][j] = dp[i - 1][j] * (map[i - 1][j] == '.') if j==0
*/

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll n;
	cin >> n;
	vector<string> map(n);
	for (ll i = 0; i < n; i++)
		cin >> map[i];

	vector<vector<ll>> dp(n, vector<ll>(n, 0));
	dp[0][0] = 1;
	for (ll i = 0; i < n; i++)
	{
		for (ll j = 0; j < n; j++)
		{
			if (i == 0 && j == 0)
				continue;
			if (i == 0)
				dp[i][j] = dp[i][j - 1] * (map[i][j - 1] == '.');
			else if (j == 0)
				dp[i][j] = dp[i - 1][j] * (map[i - 1][j] == '.');
			else
				dp[i][j] = dp[i - 1][j] * (map[i - 1][j] == '.') + dp[i][j - 1] * (map[i][j - 1] == '.');
			dp[i][j] %= (ll(1e9 + 7));
		}
	}
	cout << (map[n - 1][n - 1] == '.' ? dp[n - 1][n - 1] : 0) << endl;

	return 0;
}