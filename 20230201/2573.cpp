#include <iostream>
#include <vector>

using namespace std;

int arr[301][301], copy_arr[301][301];
int x, y, cnt;
int dy[4] = { -1, 0, 1, 0 }, dx[4] = { 0, 1, 0, -1 };


void eraseOne(int y1, int x1)
{
	if (y1 > y || y1 < 0 || x1 > x || x < 0)
		return;

	if (copy_arr[y1][x1] > 0)
		copy_arr[y1][x1] = -1;
	else
		return;

	for (int k = 0; k < 4; k++)
		eraseOne(y1 + dy[k], x1 + dx[k]);
}

int meltIce(int year)
{
	int ans = 0, flag = 1, cnt = 0;

	for (int i = 0; i < y; i++)
		for (int j = 0; j < x; j++)
			copy_arr[i][j] = arr[i][j];

	for (int i = 0; i < y; i++)
		for (int j = 0; j < x; j++)
			if (copy_arr[i][j] > 0)
			{
				if (flag == 0)
					return year;
	
				flag = 0;
				eraseOne(i, j);
			}

	
	int flag2 = 0;
	vector<int> v;
	for (int i = 0; i < y; i++)
		for (int j = 0; j < x; j++)
			if (arr[i][j])
			{
				cnt = 0;
				flag2 = 1;
				for (int k = 0; k < 4; k++)
					if (arr[i + dy[k]][j + dx[k]] == 0)
						cnt++;
				v.push_back(cnt);
			}

	for(int i=0; i<y; i++)
		for(int j=0; j<x; j++)
			if (arr[i][j])
			{
				arr[i][j] -= v[0];
				if (arr[i][j] < 0)
					arr[i][j] = 0;
				v.erase(v.begin());
			}


	if (flag2 == 0)
		return 0;
	else
		return meltIce(year + 1);
}


int main()
{
	int ans = 0;

	cin >> y >> x;

	for (int i = 0; i < y; i++)
		for (int j = 0; j < x; j++)
			cin >> arr[i][j];

	

	cout << meltIce(0);

	return 0;
}