#include <iostream>
#include <vector>
using namespace std;

int memoization[10000];

int getCombination(int n)
{
	if (n == 0)
		return 1;
	if (memoization[n])
		return memoization[n];
	else
	{
		memoization[n] = getCombination(n - 1) + getCombination(n - 2);
		return memoization[n];
	}
	
}

int main()
{	
	int a, N, M, ans = 1;
	vector<int> vip;

	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> a;
		vip.push_back(a);
	}

	int s = 0, e = N;
	memoization[1] = 1;
	memoization[2] = 2;
	
	while (vip.size() != 0)
	{
		ans *= getCombination(vip[0] - s - 1);
		s = vip[0];
		vip.erase(vip.begin());
	}

	ans *= getCombination(N - s);

	cout << ans;
	
}