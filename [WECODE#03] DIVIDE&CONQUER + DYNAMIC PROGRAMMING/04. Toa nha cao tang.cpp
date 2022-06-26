#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

/*
*	BRUTE FORCE:
	hist là bảng phân phối độ cao, hist[i] là độ cao của tòa nhà tại tọa độ i trên Ox
	Theo đề thì những điểm điểm nút sẽ tại vị trí:
	1. (i+1, hist[i+1]) nếu hist[i]<hist[i+1]
	2. (i, hist[i+1]) nếu hist[i]>hist[i+1]

*/

struct buiding
{
	ll l, r, h;
};

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll n;
	cin >> n;
	vector<buiding> buidings(n);
	for (auto& i : buidings)
		cin >> i.l >> i.r >> i.h;

	ll city_size = 1e6;
	vector<ll> hist(city_size);
	for (auto i : buidings)
		for (ll j = i.l; j <= i.r; j++)
			hist[j] = max(hist[j], i.h);

	if (hist[0])
		cout << 0 << " " << hist[0] << endl;
	for (ll i = 0; i < city_size - 1; i++)
	{
		if (hist[i + 1] > hist[i])
			cout << i + 1 << " " << hist[i + 1] << endl;
		if (hist[i + 1] < hist[i])
			cout << i << " " << hist[i + 1] << endl;
	}

	return 0;
}