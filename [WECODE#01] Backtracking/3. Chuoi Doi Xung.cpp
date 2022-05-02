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

string s;
ll l;  // Kich thuoc cua s
vector<string> ans;

bool ktDoiXung(string str)
{
	ll n = str.length();
	for (ll i = 0; i < n / 2; i++)
		if (str[i] != str[n - i - 1])
			return false;
	return true;
}

void output(vector<string> v)
{
	ll n = size(v);
	for (ll i = 0; i < n; i++)
		cout << v[i] << " ";
	cout << endl;
	return;
}

void ChuoiDoiXung(ll step, ll start)
{
	for (ll i = 1; i <= l - start; i++)   // Duyet qua so luong ky tu co the co cua ans[step]
	{
		string sub_s = s.substr(start, i);
		if (!ktDoiXung(sub_s))
			continue;

		ans.push_back(sub_s);

		if (start + i < l)
			ChuoiDoiXung(step + 1, start + i);
		else
			output(ans);

		ans.erase(ans.begin() + step);
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	// INPUT
	cin >> s;

	// OUTPUT
	l = s.length();
	ChuoiDoiXung(0, 0);

	return 0;
}