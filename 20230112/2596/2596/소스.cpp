#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;
const int len_code = 6;
vector<char> ans;
vector<int> input[10];

int code[8][6] = {
	{ 0, 0, 0 ,0 ,0 ,0},
	{ 0, 0, 1, 1, 1, 1},
	{ 0,1,0,0,1,1},
	{0,1,1,1,0,0},
	{1,0,0,1,1,0},
	{1,0,1,0,0,1},
	{1,1,0,1,0,1},
	{1,1,1,0,1,0}
};

int getCode(int n)
{
	int sameCnt;

	for (int i = 0; i < 8; i++)
	{
		sameCnt = 0;
		for (int j = 0; j < len_code; j++)
			if (code[i][j] == input[n][j])
				sameCnt++;

		if (sameCnt == len_code || sameCnt == len_code - 1)
			return (65 + i);

	}

	return 0;

}



int main()
{

	int n, tmp;
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < len_code; j++)
		{
			scanf_s("%1d", &tmp);
			input[i].push_back(tmp);
		}

	for (int i = 0; i < n; i++)
	{
		tmp = getCode(i);
		if (tmp == 0)
		{
			cout << i + 1;
			return 0;
		}
		else
		{
			ans.push_back(char(tmp));
		}
	}
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i];

	return 0;
}