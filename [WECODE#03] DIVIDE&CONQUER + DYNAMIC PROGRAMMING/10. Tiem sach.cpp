#include <bits/stdc++.h>

using namespace std;

typedef int ll;
typedef long double ld;
typedef pair<ll, ll> pll;

struct book
{
	ll page_num;
	ll price;
};

vector<book> books;
vector<vector<ll>> dp;

/*
* dp[i][j] là Số trang sách tối đa có thể mua được trên i cuốn sách đầu với j tiền
* CÔNG THỨC QUY HOẠCH ĐỘNG:
* dp[i][j] = max(dp[i - 1][j], books[i].page_num + dp[i - 1][j - books[i].price])
* dp[i][j] = 0 if i==0 or j==0
*/

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll n, x;
	cin >> n >> x;
	books.resize(n + 1);
	for (ll i = 1; i <= n; i++)
		cin >> books[i].price;
	for (ll i = 1; i <= n; i++)
		cin >> books[i].page_num;

	dp.resize(n + 1, vector<ll>(x + 1, 0));
	for (ll i = 0; i <= n; i++)
	{
		for (ll j = 0; j <= x; j++)
		{
			if (i == 0 || j == 0)
				dp[i][j] = 0;
			else if (books[i].price > j)
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = max(dp[i - 1][j], books[i].page_num + dp[i - 1][j - books[i].price]);
		}
	}
	cout << dp[n][x] << endl;

	return 0;
}