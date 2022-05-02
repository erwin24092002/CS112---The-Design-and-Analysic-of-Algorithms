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

ll n;
vector<ld> hs;
ld da;
ld dtb = 0;
vector<ld> ans;

void output(vector<ld> v)
{
	ll m = size(v);
	for (ll i = 0; i < m; i++)
		cout << v[i] << " ";
	cout << endl;
}

void DiemMonHoc(ll step)
{
	for (ld i = 0.25; i <= 10; i += 0.25)
	{
		ans[step] = i;
		ld delta = hs[step] * ans[step];

		if (dtb + delta - 0.1 > da)
			break;

		dtb += delta;

		if (step < n - 1)
			DiemMonHoc(step + 1);
		else if (roundf(dtb * 10) == da * 10)
			output(ans);

		dtb -= delta;
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	// INPUT
	cin >> n;
	hs.resize(n);
	for (ll i = 0; i < n; i++)
	{
		cin >> hs[i];
		hs[i] /= 100;
	}
	cin >> da;

	// OUTPUT
	ans.resize(n, 0.25);
	DiemMonHoc(0);

	return 0;
}