#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

class Graph
{
private:
	map<string, set<pair<ll, string>>> adj_list;
	map<string, ll> flag; // trạng thái đỉnh đã được đi qua chưa
	ll n;
	string start;
	vector<string> sol;
	ll isOK = 0;
public:
	void input(ll);
	void setStart(string);
	//	Ứng dụng set để có dãy tăng dần về khoảng cách của đỉnh đang xét đến các đỉnh kề
	// đảm bảo tính tham lam là luôn xét đến các đỉnh kề có khoảng cách gần nhất trước
	//	Ứng dụng kỹ thuật Quay lui cho findCycle
	//	Phương án giải gồm có n+1 bước [0->n], bước 0->n thử lần lượt các đỉnh kề có thể đi
	// bước n kiểm tra xem có đỉnh s kể với đỉnh được chọn ở bước n-1 hay không
	void findCycle(ll, string);
	vector<string> getSol();
};

void Graph::input(ll e)
{
	while (e--)
	{
		string u, i;
		cin >> u >> i;
		ll w;
		cin >> w;
		adj_list[u].insert(make_pair(w, i));
		flag[u] = 0;
		flag[i] = 0;
	}
	n = size(adj_list);
	sol.resize(n + 1);
	return;
}

void Graph::setStart(string s)
{
	start = s;
	return;
}

void Graph::findCycle(ll step, string s)
{
	if (isOK)
		return;

	if (step < n - 1)
	{
		sol[step] = s;
		flag[s] = 1;
		for (auto i : adj_list[s])
			if (!flag[i.second])
				findCycle(step + 1, i.second);
		flag[s] = 0;
	}
	else
	{
		sol[n - 1] = s;
		for (auto i : adj_list[s])
			if (i.second == start)
			{
				sol[n] = start;
				isOK = 1;
			}
	}
	return;
}

vector<string> Graph::getSol()
{
	return sol;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll e;
	cin >> e;
	string s;
	cin >> s;

	Graph g;
	g.input(e);
	g.setStart(s);
	g.findCycle(0, s);

	vector<string> ans = g.getSol();
	for (auto i : ans)
		cout << i << " ";
	cout << endl;
	return 0;
}