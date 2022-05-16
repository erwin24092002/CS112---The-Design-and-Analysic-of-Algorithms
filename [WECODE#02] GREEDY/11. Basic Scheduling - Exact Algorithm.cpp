#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

ll n, m;
vector<ll> jobs;
vector<ll> machines;
vector<ll> sol;
vector<ll> opt_sol;
ll opt_max = LLONG_MAX;

void scheduling(ll step)
{
	for (ll i = 0; i < m; i++)
	{
		sol[step] = i;
		machines[i] += jobs[step];
		if (step < n - 1)
			scheduling(step + 1);
		else
		{
			if (*max_element(machines.begin(), machines.end()) < opt_max)
			{
				opt_sol = sol;
				opt_max = *max_element(machines.begin(), machines.end());
			}
		}
		machines[i] -= jobs[step];
	}
}


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	jobs.resize(n);
	machines.resize(m, 0);
	for (auto& job : jobs)
		cin >> job;

	sol.resize(n);
	opt_sol.resize(n);
	scheduling(0);

	for (auto i : opt_sol)
		cout << i << " ";
	cout << endl;

	return 0;
}