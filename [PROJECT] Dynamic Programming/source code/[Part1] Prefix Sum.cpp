/*------------------------------------------------------------------------*
|    User: Huynh Viet Tuan Kiet                                           |
|    Degree: Student - Formal University                                  |
|    Study Computer Science at the University of Information Technology   |
|    Country: Viet Nam                                                    |
|    City: Ho Chi Minh                                                    |
|    Organization: VNUHCM - UIT - University of Information Technology    |
*-------------------------------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

#define _TestCases_ ll tcs; cin >> tcs; while (tcs--)
#define db double
#define ld long double
#define ll long long
#define i64 __int64 // == ll
#define ull unsigned long long
#define ui64 unsigned __int64 // == unsigned ll
#define pq priority_queue
#define sortU(v) sort(v.begin(), v.end())
#define sortD(v) sort(v.rbegin(), v.rend())
#define pll pair<ll, ll>
#define psl pair<string, ll>
#define MOD 1e9 + 7
const ll size_max = 2e5 + 1;

vector<int>p;

void prefix_sum(vector<int>&a, int n)
{
    p.resize(n + 1);
    p[0] = 0;
    for (int i = 1; i <= n; i++)
        p[i] = p[i - 1] + a[i];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, q;
    cin >> n >> q;
    vector<int>a(n + 1);
    a[0] = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    prefix_sum(a, n);

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << "a[" << l << "," << r << "] = " << p[r] - p[l - 1] << "\n";
    }
    return 0;
}

