#include <iostream>
#include <string>

using namespace std;

int idx, n, m;
string str;

int findLongIOI(int start)
{
	int cnt = 0;
	int i = start;

	while (str[i] != str[i + 1] && i+1 < m)
	{
		i++;
		cnt++;
	}
	
	
	if (str[i] == 'O')
		cnt--;


	idx = i;
	return cnt;
}


int main()
{
	int pn, ans = 0;


	cin >> n >> m;
	cin >> str;
	

	for(int i=0; i<str.size(); i++)
		if (str[i] == 'I')
		{
			pn = findLongIOI(i) / 2;
			if (pn >= n)
				ans += pn - n + 1;
			i = idx;
		}
	cout << ans;

	return 0;
}