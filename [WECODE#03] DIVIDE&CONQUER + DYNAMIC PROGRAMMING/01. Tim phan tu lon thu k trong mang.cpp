#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

/*
*	Ý TƯỞNG CHIA ĐỂ TRỊ:
	Chọn một phần tử a[p], và chia mảng ra thành hai phần,
phần 1 gồm những phần tử nhỏ hơn a[p] và phần 2 gồm những phần tử lớn hơn hoặc bằng a[p]
	- Nếu k nhỏ hơn kích thước phần 2, tiến hành tìm phần tử lớn thứ k trong phần 2
	- Nếu k lớn hơn kích thước phần 2, tiến hành tìm phần tử lớn thứ k-size(part2) trên phần 1
	- Nếu k == size(part2) => ans = a[p]
*/


ll partition(vector<ll>& v, ll l, ll r, ll p)
{
	swap(v[p], v[r]);
	ll i = l;
	ll j = r - 1;
	while (i <= j)
	{
		while (i <= j && v[i] < v[r])
			i++;
		while (i <= j && v[j] >= v[r])
			j--;
		if (i < j)
			swap(v[i], v[j]);
	}
	swap(v[i], v[r]);
	return i;
}

ll quick_select(vector<ll>& v, ll l, ll r, ll k)
{
	if (r <= l)
		return v[l];
	ll p = (l + r) / 2;
	ll pivot = partition(v, l, r, p);
	ll p2_size = r - pivot + 1;
	if (k == p2_size)
		return v[pivot];
	else if (k > p2_size)
		return quick_select(v, l, pivot - 1, k - p2_size);
	else
		return quick_select(v, pivot + 1, r, k);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll n, k;
	cin >> n >> k;
	vector<ll> a(n);
	for (ll i = 0; i < n; i++)
		cin >> a[i];

	cout << quick_select(a, 0, n - 1, k) << endl;

	return 0;
}
