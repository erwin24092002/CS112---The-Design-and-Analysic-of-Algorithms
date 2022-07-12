#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

string s;
vector<ll> operands;
vector<char> operators;
vector<vector<vector<ll>>> d;

/*
	d[i][j] là danh sách kết quả có thể tạo được từ operands[i] đến operands[j]

*	CÔNG THỨC QUY HOẠCH ĐỘNG
	d[i][j] = calc(d[i][k], d[k+1][j], operators[k]) for each k from i to j, each elements of d[i][k], d[k+1][j]

*	KẾT QUẢ:
	d[i][operands.size()-1]
*/


ll calc(ll a, ll b, char opr)
{
	if (opr == '+')
		return a + b;
	else if (opr == '-')
		return a - b;
	else
		return a * b;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> s;

	for (ll i = 0; i < s.size(); i++)
	{
		if (s[i] == '+' || s[i] == '-' || s[i] == '*')
			operators.push_back(s[i]);
		else
		{
			ll j = 0;
			while (i < s.size())
			{
				j = j * 10 + s[i] - '0';
				if (i + 1 < s.size() && s[i + 1] >= '0' && s[i + 1] <= '9')
					i++;
				else
					break;
			}
			operands.push_back(j);
		}
	}

	ll opr_n = operators.size();
	ll opd_n = operands.size();

	d.resize(opd_n, vector<vector<ll>>(opd_n));
	for (ll i = 0; i < opd_n; i++)
		d[i][i].push_back(operands[i]);
	for (ll n = 1; n < opd_n; n++)
		for (ll i = 0; i + n < opd_n; i++)
			for (ll k = i; k < i + n; k++)
				for (ll l_res : d[i][k])
					for (ll r_res : d[k + 1][i + n])
						d[i][i + n].push_back(calc(l_res, r_res, operators[k]));

	sort(d[0][opd_n - 1].begin(), d[0][opd_n - 1].end());
	for (ll result : d[0][opd_n - 1])
		cout << result << endl;

	return 0;
}