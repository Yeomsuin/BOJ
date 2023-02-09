#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
	if (a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}

int main()
{
	int a, b, n, ans = 0;
	vector<pair<int, int>> v;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}

	sort(v.begin(), v.end(), compare);

	int piv_idx = 0, start = 0;

	for (int i = 0; i < v.size(); i++)
	{
		if (start <= v[i].first)
		{
			start = v[i].second;
			ans++;
		}
	}
	
	cout << ans;
	return 0;
}