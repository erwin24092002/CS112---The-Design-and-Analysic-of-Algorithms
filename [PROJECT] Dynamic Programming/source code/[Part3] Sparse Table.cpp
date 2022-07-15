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
#include <math.h>

typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#define vt vector

void printTable(ll n, ll maxPOW, vt<vt<ll>> sparseTable)
{
	for (int i = 0; i <= maxPOW; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << sparseTable[i][j] << "\t";
		}
		cout << endl;
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll n, q;
	cout << "Enter n: ";
	cin >> n;

	cout << "Enter elements of array: " << endl;
	vt<ll> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	cout << "Enter q: ";
	cin >> q;
	cout << "Enter queries: " << endl;

	vt<pair<ll, ll>> query(q);
	for (int i = 0; i < q; i++)
		cin >> query[i].first >> query[i].second;

	ll maxPOW = 25;
	vt<vt<ll>> sparseTable(maxPOW + 1, vt<ll>(n));
	for (int i = 0; i < n; i++)
		sparseTable[0][i] = arr[i];

	for (int expo = 1; expo <= maxPOW; expo++)
	{
		for (int i = 0; i + pow(2, expo) - 1 < n; i++)
		{
			sparseTable[expo][i] = min(sparseTable[expo - 1][i], sparseTable[expo - 1][i + pow(2, expo - 1)]);
		}
	}

	//printTable(n, maxPOW, sparseTable);

	cout << "Minimum number in each query: " << endl;
	for (auto x : query)
	{
		ll left = x.first - 1;
		ll right = x.second - 1;
		ll power = log2(right - left + 1);
		
		cout << "left: " << x.first << " " << "right: " << x.second << endl;
		cout << min(sparseTable[power][left], sparseTable[power][right - pow(2, power) + 1]) << endl;
	}

}

