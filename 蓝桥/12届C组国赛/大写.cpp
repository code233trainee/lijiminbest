#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
	string s;
	cin >> s;
	for(int i = 0; i < s.size(); i++)
	{
		if(s[i] >= 'a' && s[i] <= 'z')
		{
			int k = s[i] - 'a';
			s[i] = char('A' + k);
		}
	}
	cout << s << endl;
	return 0;
}
