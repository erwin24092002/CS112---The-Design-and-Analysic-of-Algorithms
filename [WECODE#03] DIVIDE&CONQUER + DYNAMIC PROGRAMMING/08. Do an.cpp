#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

struct subject
{
	ll start;
	ll end;
	ll credit;
};

/*
* dp[i] là số tín chỉ tối đa có thể đạt được trong thời gian từ 1 -> i
*
* CÔNG THỨC QUY HOẠCH ĐỘNG:
* dp[i] = max(dp[subjects[j].end] + subjects[i].credit, dp[subjects[i-1].end])
*				j where subject[j].end < subject[i].start
* dp[0] = 0
*/

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll n;
	cin >> n;
	vector<subject> subjects(n);
	for (ll i = 0; i < n; i++)
		cin >> subjects[i].start >> subjects[i].end >> subjects[i].credit;
	sort(subjects.begin(), subjects.end(),
		[](subject a, subject b) {
			return a.end < b.end;
		});

	map<ll, ll> dp;
	dp[0] = 0;
	ll ans = LLONG_MIN;
	for (auto sj : subjects)
	{
		auto it = dp.lower_bound(sj.start);
		it--;
		ll total_credit = it->second + sj.credit;
		ans = max(ans, total_credit);
		dp[sj.end] = ans;
	}
	cout << ans << endl;

	return 0;
}