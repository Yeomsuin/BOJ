#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define fio() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
int T, n, size, cnt;
int dd[101010]; // -1 탐색끝났지만 연결x, 0 탐색 x, 1 탐색끝났고 연결 o
int arr[101010], visited[101010];

void dfs(int cur)
{   
    visited[cur] = 1;
    int next = arr[cur];

    if(!visited[next])
        dfs(next);
    else if(!dd[next])
    {
        for(int i=next; i != cur; i = arr[i])
            cnt++;
        cnt++;
    }

    dd[cur] = 1;

}

int main()
{

    fio();

    cin >> T;

    while(T--)
    {
        cin >> n;

        for(int i=1; i<=n; i++)
            cin >> arr[i];
        
        memset(dd, 0, sizeof(dd));
        memset(visited, 0 ,sizeof(visited));

        cnt = 0;

        for(int i=1; i<=n; i++)
            if(!visited[i])
                dfs(i);
     
        cout << n-  cnt << endl;
    }
}