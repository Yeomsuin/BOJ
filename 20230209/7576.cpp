#include <iostream>
#include <queue>
using namespace std;

int tomato[1001][1001], visited[1001][1001];
int N, M, flag;
int dy[4] = { -1, 0, 1, 0 }, dx[4] = { 0, 1, 0, -1 };
queue<pair<int, int>> q;


void bfs(void)
{
	pair<int, int> tmp;

	while (!q.empty())
	{
		tmp = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int y = tmp.first + dy[i];
			int x = tmp.second + dx[i];
			if (y < N && y >= 0 && x < M && x >= 0)
				if (tomato[y][x] == 0)
				{
					q.push(make_pair(y, x));
					visited[y][x] = visited[tmp.first][tmp.second] + 1;
					tomato[y][x] = 1;
				}
		}


	}
}

int main()
{
	int days = 0;

	cin >> M >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			cin >> tomato[i][j];
			if (tomato[i][j] == 1)
				q.push(make_pair(i, j));
			visited[i][j] = 1;
		}
	

	bfs();

	for(int i=0; i<N;i++)
		for (int j = 0; j < M; j++)
		{
			if (tomato[i][j] == 0)
			{
				cout << "-1";
				return 0;
			}
			
			days = max(days, visited[i][j]);
		}

	cout << days - 1;
	return 0;
}