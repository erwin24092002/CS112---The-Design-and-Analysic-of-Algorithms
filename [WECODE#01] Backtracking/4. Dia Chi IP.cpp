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
vector<ll> ans(4);

void output(vector<ll> ans)
{
	cout << ans[0] << '.' << ans[1] << '.' << ans[2] << '.' << ans[3] << endl;
	return;
}

void DiaChiIP(ll step, ll start)
{
	for (ll i = 1; i <= 3; i++)
	{
		if (start + i > s.length() || (s[start] == '0' && i > 1))
			break;
		ans[step] = stoi(s.substr(start, i));
		if (ans[step] > 255)
			break;
		else
		{
			if (step < 3)
				DiaChiIP(step + 1, start + i);
			else if (start + i == s.length())
				output(ans);
		}
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	// INPUT
	cin >> s;

	// OUTPUT
	DiaChiIP(0, 0);

	return 0;
}