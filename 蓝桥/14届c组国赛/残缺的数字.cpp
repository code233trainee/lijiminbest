#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<string> a = {"1111110", "0110000", "1101101", "1111001", "0110011", "1011011", "1011111", "1110000", "1111111", "1111011"};
ll check(string s)
{
  ll cnt = 0;
  for(int i = 0; i < 10; i++)
  {
    bool isok = true;
    for(int j = 0; j < 7; j++)
    {
      if(s[j] == '1' && a[i][j] != '1')
      {
        isok = false;
        break;
      }
    }
    if(isok)
    {
      cnt++;
    }
  }
  return cnt;
}
int main()
{
  ll a = 1;
  for(int i = 1; i <= 18; i++)
  {
    string s;
    cin >> s;
    a *= check(s);
  }
  cout << a;
  return 0;
}