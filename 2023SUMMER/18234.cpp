#include <bits/stdc++.h>

using namespace std;
#define fio() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main()
{
    fio();
    
    long long ans = 0;

    int n, t, a;
    long long b;
    priority_queue<long long> pq;

    cin >> n >> t;

    for(int i=0; i<n; i++)
    {
        cin >> a >> b;
        ans += a; 
        pq.push(b);
    }

    t--;

    while(!pq.empty())
    {
        ans += pq.top() * t--;
        pq.pop();
    }

    cout << ans;
}