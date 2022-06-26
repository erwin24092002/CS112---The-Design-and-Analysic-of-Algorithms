#include <bits/stdc++.h>

using namespace std;

typedef int ll;
typedef long double ld;
typedef pair<ll, ll> pll;

/*
*	MÔ HÌNH BÀI TOÁN:
	Mỗi căn hộ là một đỉnh, khoảng cách giữa hai căn hộ là số cạnh nối 2 đỉnh
	Đồ thị (1 thành phần liên thông) có n đỉnh, n-1 cạnh => cây
	Quy ước đỉnh 1 chính là gốc của cây (O).

*	Ý TƯỞNG:
	d(A, B) = d[A] + d[B] - 2*d[C]
	Khoảng cách giữa 2 đỉnh A và B = Khoảng cách giữa A và O
									 + Khoảng cách giữa B và O
									 - 2 Khoảng cách giữa C và O (C là điểm chung nằm trên OA và OB và C xa O nhất - LCA)
	calc d[] = depth => Depth First Search
	find C => Lowest Common Ancestor using Binary Lifting
*/

class Graph
{
private:
	ll n;
	ll logn;
	ll time = 0;
	vector<vector<ll>> adj_list;
	vector<ll> d; //  d[i] is the depth of node i in the tree
	vector<vector<ll>> ancestors; // ancestors[v][i] is 2^i-th ancestor of node v
	vector<ll> time_in;
	vector<ll> time_out;
public:
	Graph(ll nn)
	{
		n = nn;
		logn = ceil(log2(n));
		adj_list.resize(n + 1);
		d.resize(n + 1, 0);
		ancestors.resize(n + 1, vector<ll>(logn + 1));
		time_in.resize(n + 1);
		time_out.resize(n + 1);
	}
	void input()
	{
		for (ll i = 1; i < n; i++)
		{
			ll u, v;
			cin >> u >> v;
			adj_list[u].push_back(v);
			adj_list[v].push_back(u);
		}
	}
	void dfs(ll v, ll prev_v, ll depth)
	{
		time_in[v] = time++;
		d[v] = depth;
		ancestors[v][0] = prev_v;
		for (ll i = 1; i <= logn; i++)
			ancestors[v][i] = ancestors[ancestors[v][i - 1]][i - 1];
		for (auto u : adj_list[v])
			if (u != prev_v)
				dfs(u, v, depth + 1);
		time_out[v] = time++;
	}
	bool is_parent(ll a, ll b) // a is b's parent ??
	{
		return time_in[a] <= time_in[b] && time_out[a] >= time_out[b];
	}
	ll get_lca(ll a, ll b)
	{
		if (is_parent(a, b))
			return a;
		if (is_parent(b, a))
			return b;
		for (ll i = logn; i >= 0; i--)
			if (!is_parent(ancestors[a][i], b))
				a = ancestors[a][i];
		return ancestors[a][0];
	}
	ll get_distance(ll v, ll u)
	{
		return d[v] + d[u] - 2 * d[get_lca(v, u)];
	}
};

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll n, q;
	cin >> n >> q;
	Graph gr(n);
	gr.input();
	gr.dfs(1, 1, 0);

	while (q--)
	{
		ll a, b;
		cin >> a >> b;
		cout << gr.get_distance(a, b) << "\n";
	}

	return 0;
}