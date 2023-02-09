#include <iostream>
#include <cstring>

using namespace std;

int n, cnt;
int board[101][101], visited[101][101];
int dy[4] = { -1, 0, 1, 0 }, dx[4] = { 0, 1, 0, -1 };

void dfs(int y, int x, int color)
{
	if (y >= n || y < 0 || x >= n || x < 0)
		return;
	if (visited[y][x])
		return;

	visited[y][x] = 1;

	for (int i = 0; i < 4; i++)
		if (board[y + dy[i]][x + dx[i]] == color)
			dfs(y + dy[i], x + dx[i], color);
		
	return;
}

int main()
{
	char input;
	int ans1 = 0, ans2 = 0;
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			cin >> input;
			if (input == 'R')
				board[i][j] = 0;
			else if (input == 'G')
				board[i][j] = 1;
			else
				board[i][j] = 2;
		}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (!visited[i][j])
			{
	
				dfs(i, j, board[i][j]);
				ans1++;
			}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (board[i][j] == 1)
				board[i][j] = 0;

	memset(visited, 0, sizeof(visited));


	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (!visited[i][j])
			{
				dfs(i, j, board[i][j]);
				ans2++;
			}

	cout << ans1 << ' ' << ans2;
	return 0;
}