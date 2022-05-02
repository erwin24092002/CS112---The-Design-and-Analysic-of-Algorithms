#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <iomanip>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

ll Al1(ll n) {
	ll i = 1;
	ll m = n - n * (n % 2);
	ll s = 3;
	while (i <= m)
	{
		ll j = 1;
		ll k = i * i * (i% 2);
		s = s + 3;
		while (j <= k)
		{
			j = j + 1;
			s = s + 2;
		}
		i = i + 1;
		s = s + 2;
	}
	return s;
}

ll Al2(ll n) {
	ll i = 1;
	ll m = n * (n % 2);
	ll s = 3;
	while (i <= m)
	{
		ll j = 1;
		ll k = i * i - i * i * (i % 2);
		s = s + 3;
		while (j <= k)
		{
			j = j + 1;
			s = s + 2;
		}
		i = i + 1;
		s = s + 2;
	}
	return s;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cout << setw(6) << "n";
	for (ll i = 1; i <= 20; i++)
		cout << setw(7) << i;
	cout << endl;

	cout << setw(6) << "G1(n)";
	for (ll i = 1; i <= 20; i++)
		cout << setw(7) << Al1(i);
	cout << endl;

	cout << setw(6) << "G2(n)";
	for (ll i = 1; i <= 20; i++)
		cout << setw(7) << Al2(i);
	cout << endl;
	return 0;
}
