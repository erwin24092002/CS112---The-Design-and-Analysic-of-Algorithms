#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

/*
	dp[config][i] là số tiền tối đa Bình thu được khi xóa bong bóng thứ i đầu tiên
trong trạng thái các bong bóng là config
	ans[config] là số tiền tối đa Bình thu được trong trạng thái các bong bóng là config
	config = 0 1 1 1 1 0 1 (dãy bong bóng Bình tiến hành bóp là 1 2 3 4 6)

*	CÔNG THỨC QUY HOẠCH ĐỘNG:
	dp[config][i] = ans[config\i] + w[i]
*/

ll n;
vector<ll> bals;
vector<vector<ll>> dp;
vector<ll> ans;

ll bit_off(ll bit_mask, ll i)
{
	return (bit_mask & ~(1LL << i));
}

ll bit_on(ll bit_mask, ll i)
{
	return (bit_mask | (1LL << i));
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;
	bals.resize(n);
	for (ll& bal : bals)
		cin >> bal;

	ll config_num = 1LL << n;
	dp.resize(config_num, vector<ll>(n, 0));
	ans.resize(config_num, 0);

	for (ll config = 0; config < config_num; config++)
	{
		for (ll bal = 0; bal < n; bal++)
		{
			if (config != 0 && bit_off(config, bal) == 0)
				dp[config][bal] = bals[bal];
			else if (bit_off(config, bal) == config)
				dp[config][bal] = 0;
			else
			{
				ll w = 1;
				for (ll i = bal + 1; i <= n - 1; i++)
				{
					if (((1LL << i) & config) != 0)
					{
						w *= bals[i];
						break;
					}
				}
				for (ll i = bal - 1; i >= 0; i--)
				{
					if (((1LL << i) & config) != 0)
					{
						w *= bals[i];
						break;
					}
				}
				w *= bals[bal];
				dp[config][bal] = w + ans[bit_off(config, bal)];
			}
			ans[config] = max(ans[config], dp[config][bal]);
		}
	}

	cout << ans[config_num - 1] << endl;


	return 0;
}