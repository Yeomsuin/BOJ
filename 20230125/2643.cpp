#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[101];

int main()
{
	vector<pair<int, int>> v;

	int n, a, b, ans = 1;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;

		if (a > b)
			swap(a, b);
		v.push_back(make_pair(a, b));
	}
	sort(v.begin(), v.end());


	for (int k = 0; k < n; k++)
	{
		dp[k] = 1;
		for (int i = 0; i < k; i++)
			if (v[k].first >= v[i].first && v[k].second >= v[i].second)
				dp[k] = max(dp[i] + 1, dp[k]);
		ans = max(ans, dp[k]);
	}
	
	cout << ans;

}