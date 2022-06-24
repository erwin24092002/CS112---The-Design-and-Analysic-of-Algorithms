#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

/*
* dp[i] là độ dài chuỗi con tăng dài nhất kết thúc tại a[i]  (0<=i<n)
* min_val[i] là giá trị nhỏ nhất trong chuỗi con tăng có độ dài là i
*
* CÔNG THỨC QUY HOẠCH ĐỘNG:
* dp[i] = 1 + dp[x] ( x=argmax(dp[j]) where j<i and a[j]<a[i] )
* min_val[i] = x ( x=amin(a[j]) where dp[a[j]] = i)
*/

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll n;
	cin >> n;
	vector<ll> a(n);
	for (ll i = 0; i < n; i++)
		cin >> a[i];

	vector<ll> dp(n, 1);
	vector<ll> min_val(n + 1, LLONG_MAX);
	ll ans = 0;
	for (ll i = 0; i < n; i++)
	{
		ll l = 0;
		ll r = i + 1;
		while (l < r)
		{
			ll m = (l + r) / 2;
			if (min_val[m] >= a[i])
				r = m;
			else
			{
				l = m + 1;
				dp[i] = 1 + m;
			}
		}
		min_val[dp[i]] = min(min_val[dp[i]], a[i]);
		ans = max(ans, dp[i]);
	}
	cout << ans << endl;

	return 0;
}