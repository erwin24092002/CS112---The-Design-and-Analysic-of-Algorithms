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
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

char NgoacDon[] = { '(', ')' };
ll n;

void output(vector<char> v)
{
	ll n = size(v);
	for (ll i = 0; i < n; i++)
		cout << v[i];
	cout << endl;
}

void CapNgoacDon(ll step, ll flag, vector<char> ans)
{
	for (ll i = 0; i < 2; i++)
	{
		ans[step] = NgoacDon[i];
		ll delta = ans[step] == '(' ? 1 : -1;
		if (flag + delta<0 || flag + delta>n / 2)
			continue;
		if (step < n - 1)
			CapNgoacDon(step + 1, flag + delta, ans);
		else if (flag + delta == 0)
			output(ans);
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	// INPUT
	cin >> n;
	n *= 2;

	/* CONVENTION
	* '(' = +1
	* ')' = -1
	* when check<0 => false solution
	*/

	// OUTPUT
	vector<char> ans(n);
	ll flag = 0;
	CapNgoacDon(0, flag, ans);

	return 0;
}