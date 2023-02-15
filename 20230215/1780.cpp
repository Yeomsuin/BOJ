#include <iostream>

using namespace std;

int paper[3000][3000];
int n;
int ans_minus, ans_zero, ans_plus;

int checkAllSame(int n, int sx, int ex, int sy, int ey)
{
	int tmp = paper[sy][sx];
	
	if (n != 1)
	{
		for (int i = sy; i < ey; i++)
			for (int j = sx; j < ex; j++)
				if (tmp != paper[i][j])
					return false;
	}

	if (tmp == 0)
		ans_zero++;
	else if (tmp == 1)
		ans_plus++;
	else
		ans_minus++;

	return true;
	
}

void solve(int n, int sx, int ex, int sy, int ey)
{
	
	if (checkAllSame(n, sx, ex, sy, ey))
		return;
	
	int k = n / 3;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			solve(n/3, sx + k * i, sx +k * (i + 1),sy + k * j, sy + k * (j + 1));

	return;
}



int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> paper[i][j];

	solve(n, 0, n, 0, n);

	cout << ans_minus << endl << ans_zero << endl << ans_plus;

	return 0;
}