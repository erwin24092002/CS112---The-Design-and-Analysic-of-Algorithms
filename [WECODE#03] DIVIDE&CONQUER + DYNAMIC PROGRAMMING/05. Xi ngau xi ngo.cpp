#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll s;
	cin >> s;

	vector<ll> dp(s + 1, 0);
	dp[0] = 1;
	for (ll sum = 1; sum <= s; sum++)
	{
		for (ll dice = 1; dice <= 6; dice++)
		{
			if (sum - dice >= 0)
			{
				dp[sum] += dp[sum - dice];
				dp[sum] %= (ll(1e9 + 7));
			}
		}
	}
	cout << dp[s] << endl;

	return 0;
}