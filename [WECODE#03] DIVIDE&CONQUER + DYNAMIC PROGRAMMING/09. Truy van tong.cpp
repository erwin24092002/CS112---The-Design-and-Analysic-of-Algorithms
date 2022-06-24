#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

/*
* dp[i] là giá trị của tổng các phần tử từ A[1]->A[i]
*
* CÔNG THỨC QUY HOẠCH ĐỘNG:
* dp[i] = dp[i-1] + A[i]
* dp[0] = 0
*/

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll n, q;
	cin >> n >> q;
	vector<ll> A(n + 1);
	vector<ll> dp(n + 1, 0);
	for (ll i = 1; i <= n; i++)
		cin >> A[i];

	for (ll i = 1; i <= n; i++)
		dp[i] = dp[i - 1] + A[i];
	while (q--)
	{
		ll a, b;
		cin >> a >> b;
		cout << dp[b] - dp[a - 1] << endl;
	}

	return 0;
}