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

int LCS(string a, string b)
{
	int n = a.length();
	int m = b.length();
	vector<vector<int>>D(n, vector<int>(m));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (i == 0 or j == 0)
				D[i][j] = 0;
			else if (a[i] == b[j])
				D[i][j] = 1 + D[i - 1][j - 1];
			else
				D[i][j] = max(D[i - 1][j], D[i][j - 1]);
		}
	}
	return D[n - 1][m - 1];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	string A, B;
	cin >> A >> B;
	A.insert(0, " ");
	B.insert(0, " ");

	cout << LCS(A, B) << "\n";
	return 0;
}
