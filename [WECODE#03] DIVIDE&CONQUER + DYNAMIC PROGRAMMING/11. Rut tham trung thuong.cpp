#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

/*
* dp[i][j] là số hành động tối thiểu để biến chuỗi con gồm i ký tự đầu của s1
* thành chuỗi con gồm j ký tự đầu của s2.
*
* CÔNG THỨC QUY HOẠCH ĐỘNG:
* dp[i][j] = min(1 + dp[i][j-1], 1 + dp[i-1][j], dp[i-1][j-1] + s1[i-1]!=s2[j-1])
* dp[0][0] = 0
*/

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	string s1, s2;
	cin >> s1 >> s2;
	ll n = s1.length();
	ll m = s2.length();

	vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, LLONG_MAX));
	dp[0][0] = 0;
	for (ll i = 0; i <= n; i++)
	{
		for (ll j = 0; j <= m; j++)
		{
			if (i > 0)
				dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
			if (j > 0)
				dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
			if (i > 0 && j > 0)
				dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + (s1[i - 1] != s2[j - 1]));
		}
	}
	cout << dp[n][m] << endl;

	return 0;
}