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
	ll n;
	cin >> n;
	vector<ll>a(n + 1);
	a[1] = a[2] = 1;
	for (ll i = 3; i <= n; i++)a[i] = a[i - 1] + a[i - 2];
	cout << a[n];
	return 0;
}