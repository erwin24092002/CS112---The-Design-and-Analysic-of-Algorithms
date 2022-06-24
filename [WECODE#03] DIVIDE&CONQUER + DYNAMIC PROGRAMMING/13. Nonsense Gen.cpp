#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

/*
* dp[i] biểu thị NST có kích thước i có tồn tại hay không
*
* CÔNG THỨC QUY HOẠCH ĐỘNG:
* dp[i] = true if dp[i-NST] = true for any NST
* dp[0] = true
* dp[i] = false otherwise
*/

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll n;
	cin >> n;
	vector<ll> NSTs(n);
	for (ll i = 0; i < n; i++)
		cin >> NSTs[i];

	vector<bool> dp(1e5 + 1);
	set<ll> distinctNSTs;
	dp[0] = true;
	ll total = 0;
	for (auto NST : NSTs)
	{
		total += NST;
		for (ll size = total; size >= NST; size--)
		{
			if (dp[size - NST] && !dp[size])
			{
				dp[size] = true;
				distinctNSTs.insert(size);
			}
		}
	}
	cout << distinctNSTs.size() << endl;
	for (auto NST : distinctNSTs)
		cout << NST << " ";

	return 0;
}