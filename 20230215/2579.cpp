#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	int weight[301];
	int dp[3][301];
	int n;

	cin >> n;

	weight[0] = 0;
	for (int i = 1; i <= n; i++)
		cin >> weight[i];
	
	memset(dp, 0, sizeof(dp));
	dp[1][1] = weight[1];
	dp[0][1] = weight[1];
	dp[2][1] = weight[1];

	for (int i = 2; i <= n; i++)
	{
		dp[1][i] = dp[2][i - 1] + weight[i];
		dp[2][i] = dp[0][i - 2] + weight[i];
		dp[0][i] = max(dp[1][i], dp[2][i]);
	}

	cout << dp[0][n];
}