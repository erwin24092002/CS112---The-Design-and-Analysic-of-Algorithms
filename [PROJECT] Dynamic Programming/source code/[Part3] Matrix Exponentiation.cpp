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

struct Matrix
{
    vector<vector<ll>>a;
    ll n, m;

    Matrix(ll n = 0, ll m = 0) :n(n), m(m)
    {
        a.resize(n);
        for (ll i = 0; i < n; i++)
        {
            a[i].resize(m);
            for (ll j = 0; j < m; j++)
                a[i][j] = 0;
        }
    }
};

Matrix operator*(const Matrix& a, const Matrix& b)
{
    Matrix c(a.n, b.m);

    for (ll i = 0; i < a.n; i++)
        for (ll j = 0; j < b.m; j++)
            for (ll k = 0; k < a.m; k++)
                c.a[i][j] += (a.a[i][k] * b.a[k][j]);
    return c;
}

ostream& operator<< (ostream& os, const Matrix& mt)
{
    for (ll i = 0; i < mt.n; i++)
    {
        for (ll j = 0; j < mt.m; j++)
            os << mt.a[i][j] << " ";
        os << "\n";
    }
    return os;
}

Matrix Identity(ll n)
{
    Matrix mat(n, n);
    for (ll i = 0; i < n; i++)
        mat.a[i][i] = 1;
    return mat;
}

Matrix pow(const Matrix& a, ll k)
{
    if (k == 0)
        return Identity(a.n);
    if (k == 1)
        return a;

    ll n = ll(log(k)) + 1;
    vector<Matrix> d(n + 1);
    d[0] = a;
    for (ll i = 1; i <= n; i++)
        d[i] = d[i - 1] * d[i - 1];

    ll tmp_k = k;
    ll i = 0;
    Matrix ans = Identity(a.n);
    while (tmp_k > 0)
    {
        if (tmp_k % 2 == 1)
            ans = ans * d[i];
        i++;
        tmp_k /= 2;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll n, k;
    cin >> n >> k;

    Matrix a(n, n);

    for (ll i = 0; i < n; i++)
        for (ll j = 0; j < n; j++)
            cin >> a.a[i][j];

    cout << "\n" << pow(a, k);

    return 0;
}