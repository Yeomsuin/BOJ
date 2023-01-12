#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


bool compare(pair<int, int > a, pair<int, int> b)
{
	return a.second < b.second;
}

int isStraight(vector<pair<char, int>> k)
{
	sort(k.begin(), k.end(), compare);
	int flag = 1;
	for (int i = 0; i < 4; i++)
		if (k[i].second + 1 != k[i + 1].second)
		{
			flag = 0;
			break;
		}
	return flag;
}

int main()
{
	enum {
		R = 0, B = 1, G = 2, Y = 3
	};
	vector<pair<char, int >> v;
	char a;
	int b, ans = 0, max_num = 0;
	int color_check[4] = { 0, }, num_check[10] = { 0, };
	for (int i = 0; i < 5; i++) {
		cin >> a >> b;
		v.push_back(make_pair(a, b));
		num_check[b]++;
		if (a == 'R')
			color_check[0]++;
		if (a == 'B')
			color_check[1]++;
		if (a == 'G')
			color_check[2]++;
		if (a == 'Y')
			color_check[3]++;
		max_num = max(max_num, b);
	}


	int max_color_cnt = 0, max_num_cnt = 0, max_num_idx;

	for (int i = 1; i < 10; i++)
	{
		if (max_num_cnt < num_check[i])
		{
			max_num_idx = i;
			max_num_cnt = num_check[i];
		}
	}
	for (int i = 0; i < 4; i++)
		max_color_cnt = max(max_color_cnt, color_check[i]);

	//cout << max_num_cnt << endl;


	if (isStraight(v))
		ans = max(ans, max_num + 500);

	if (max_color_cnt == 5)
	{
		if (isStraight(v))
			ans = max(ans, max_num + 900);
		else
			ans = max(ans, max_num + 600);
	}
	else if (max_num_cnt == 4)
	{
		ans = max(ans, max_num_idx + 800);
	}
	else if (max_num_cnt == 3)
	{
		int flag = 1;
		for (int i = 1; i < 10; i++)
			if (num_check[i] == 2)
			{
				flag = 0;
				ans = max(ans, max_num_idx * 10 + i + 700);
				break;
			}
		if (flag)
			ans = max(ans, max_num_idx + 400);
	}
	else if (max_num_cnt == 2)
	{
		int flag = 1;
		for (int i = 1; i < 10; i++)
			if (num_check[i] == 2 && i != max_num_idx)
			{
				flag = 0;
				ans = max(ans, i * 10 + max_num_idx + 300);
				break;
			}
		if (flag)
			ans = max(ans, max_num_idx + 200);
	}
	else
	{
		ans = max(ans, max_num + 100);
	}

	cout << ans;


}
