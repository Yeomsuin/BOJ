	#include <iostream>
	#include <vector>
	#include <algorithm>

	using namespace std;

	int main()
	{

		int N, a, b, piv, max_len = 0, answer = 0, tall_start =-1, tall_end = -1;

		vector<pair<int, int>> v, ans;
		vector<int> max_idx;
	
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			cin >> a >> b;
			v.push_back(make_pair(a, b));
			max_len = max(max_len, b);
		}

		sort(v.begin(), v.end());

		for(int i=0; i<v.size(); i++)
			if (v[i].second == max_len)
				max_idx.push_back(i);


		piv = -1;

		for(int i=0; i<=max_idx[0]; i++)
			if (v[i].second > piv)
			{
				piv = v[i].second;
				ans.push_back(v[i]);
			}

		for (int i = max_idx[0] + 1; i <= max_idx[max_idx.size()-1]; i++)
				ans.push_back(v[i]);

		piv = -1;
		vector <pair<int, int>> tmp;

		for (int i = v.size()-1; i > max_idx[max_idx.size() -1 ]; i--)
		{
			if (v[i].second > piv)
			{
				piv = v[i].second;
				tmp.push_back(v[i]);
			}
		}
	
		for (int i = tmp.size() - 1; i >= 0; i--)
			ans.push_back(tmp[i]);
		int flag = 1;
		max_idx.clear();

		for (int i = 0; i < ans.size(); i++)
			if (ans[i].second == max_len)
			{
				if (flag)
				{
					flag = 0;
					tall_start = ans[i].first;
					tall_end = tall_start;
				}
				else
				{
					tall_end = ans[i].first;
				}
				max_idx.push_back(i);
			}
	

		for (int i = 0; i < max_idx[0]; i++)
			answer += (ans[i + 1].first - ans[i].first) * ans[i].second;		
		


		for (int i = ans.size()-1; i > max_idx[max_idx.size()-1]; i--)
			answer += (ans[i].first - ans[i-1].first) * ans[i].second;
	
		
		int k;

		if (tall_start == tall_end)
			k = 1;
		else
			k = (tall_end - tall_start+1);

		answer += max_len * k;
	
		cout << answer;

		return 0;
	}