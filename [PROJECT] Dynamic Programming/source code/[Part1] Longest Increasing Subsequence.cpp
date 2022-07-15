#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
#include <unordered_set>
#include <cmath>
#include <numeric>
#include <stdio.h>
#include <cstdio>
#include <stack>
#include <queue>
#include <fstream>
#include <sstream>
#include <map>

typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#define vt vector

ll n;
vt<ll> A;

ll LIS();

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cout << "Input n: ";
	cin >> n;
	
	cout << "Input array A: ";
	A.resize(n + 1);

	for (int i = 1; i <= n; i++)
		cin >> A[i];
	
	cout << "Length of the longest increasing subsequence in A: " << LIS();
}

ll LIS()
{
	//freopen("bcount.in", "r", stdin);
	//freopen("bcount.out", "w", stdout);
	vt<ll> d(n + 1, 0);
	d[1] = 1;

	for (int i = 2; i <= n; i++)
	{
		ll jmax = 0;
		for (int j = 1; j < i; j++)
		{
			if (A[j] < A[i] && d[jmax] < d[j])
			{
				jmax = j;
			}
		}
		d[i] = d[jmax] + 1;
	}
	return *max_element(d.begin(), d.end());
}
