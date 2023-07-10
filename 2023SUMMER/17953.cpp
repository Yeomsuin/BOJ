#include <bits/stdc++.h>

using namespace std;
#define fio() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

long long dp[10][101010];
int arr[10][101010];
// j번째날에 i번째 디저트르 먹을 때 최대값

int main()
{
    int n, m;
    cin >> n >> m;

    for(int i=0; i<m;i ++)
        for(int j=1; j<=n; j++)
            cin >> arr[i][j];

    for(int i=0; i<m; i++)
        dp[i][1] = arr[i][1];    

    for(int i=2; i<=n; i++)
        for(int j=0; j<m; j++)
            for(int k=0; k<m; k++)
                if(j == k)
                    dp[j][i] = max(dp[j][i], dp[k][i-1] + arr[k][i] / 2);
                else
                    dp[j][i] = max(dp[j][i], dp[k][i-1] + arr[j][i]);
    long long ans = 0;



    for(int i=0; i<m; i++)
        ans = max(ans, dp[i][n]);


    cout << ans;
}