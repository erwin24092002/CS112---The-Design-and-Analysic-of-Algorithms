#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

void solve()
{
	string a;
	cin >> a;
	ll k;
	cin >> k;

	if (k > a.length())
	{
		cout << "error" << endl;
		return;
	}

	ll n = a.length();
	while (k--)
	{
		// remove prefix = 0
		ll i = 0;
		while (i < n && a[i] == '0')
			i++;
		a.erase(a.begin(), a.begin() + i);
		if (!(n -= i))
			break;

		// find element's index should be removed
		ll re_idx = n - 1;
		for (i = 0; i < n - 1; i++)
		{
			if (a[i] > a[i + 1])
			{
				re_idx = i;
				break;
			}
		}

		// remove that element
		a.erase(a.begin() + re_idx);
		n--;
	}
	cout << (a.empty() ? 0 : stoi(a)) << endl;
	return;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();

	return 0;
}