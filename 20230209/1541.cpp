#include <iostream>
#include <string>

using namespace std;


int main()
{
	string str;
	char tmp1, tmp2;
	int ans = 0, k = 0, flag = 1;

	cin >> str;


	while (!str.empty())
	{	
		tmp1 = str.front();
		str.erase(str.begin());
	
		if (tmp1 == '-')
		{
			ans += k;
			k = 0;
			while (!str.empty())
			{
				flag = 0;
				tmp2 = str.front();
				str.erase(str.begin());

				if (tmp2 == '+' || tmp2 == '-')
				{
					ans -= k;
	
					k = 0;
				}
				else
				{
					k = k * 10 + (int)(tmp2 - '0');
				}
			}
		}
		else if (tmp1 == '+')
		{
			ans += k;
			k = 0;
		}
		else
		{
			k = k * 10 + (int)(tmp1 - '0');
		}

	}

	if (flag)
		ans += k;
	else
		ans -= k;

	cout << ans;

	return 0;
}