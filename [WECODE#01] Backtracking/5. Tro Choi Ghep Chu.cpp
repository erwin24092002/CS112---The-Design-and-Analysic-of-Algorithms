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

string keyword;
vector<string> v;
ll n, m;   //so dong, so cot
bool ans = false;
vector<vector<ll>> flag;

bool isValidLocation(ll x, ll y)
{
	return 0 <= x && x < n && 0 <= y && y < m;
}

void GhepChu(ll step, ll x, ll y)
{
	if (ans)
		return;
	for (ll i = -1; i <= 1; i++)
	{
		for (ll j = -1; j <= 1; j++)
		{
			ll cur_x = x + i;
			ll cur_y = y + j;
			if (!isValidLocation(cur_x, cur_y) || flag[cur_x][cur_y] == 1 || v[cur_x][cur_y] != keyword[step])
				continue;
			//cout << v[cur_x][cur_y] << endl;
			flag[cur_x][cur_y] = 1;
			if (step < keyword.length() - 1)
				GhepChu(step + 1, cur_x, cur_y);
			else
				ans = true;
			flag[cur_x][cur_y] = 0;
		}
	}
	return;
}

void ChoiGhepChu()  // Duyet qua cac diem Bat dau
{
	for (ll i = n - 1; i >= 0; i--)
	{
		for (ll j = m - 1; j >= 0; j--)
		{
			if (v[i][j] != keyword[0])
				continue;
			else if (keyword.length() == 1)
			{
				cout << "true" << endl;
				return;
			}
			flag[i][j] = 1;
			GhepChu(1, i, j);
			flag[i][j] = 0;
		}
	}
	cout << (ans ? "true" : "false") << endl;
	return;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	// INPUT
	cin >> keyword;
	string word;
	cin >> word;
	while (word != ".")
	{
		v.push_back(word);
		cin >> word;
	}

	// OUTPUT
	n = size(v);
	m = v[0].length();
	flag.resize(n, vector<ll>(m, 0));
	ChoiGhepChu();

	return 0;
}