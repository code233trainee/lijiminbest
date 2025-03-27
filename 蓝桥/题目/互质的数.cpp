#include <iostream>
using namespace std;
int gcd(int a, int b) 
{
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int main()
{
  // 2 11 23
  int cnt = 0;
  int i = 1;
  while(1)
  {
    if(i%2!=0 && i%11!=0 && i%23!=0)
    {
      cnt++;
    }
    if(cnt == 2024)
    {
      cout << i;
      return 0;
    }
    i++;
  }
  return 0;
}