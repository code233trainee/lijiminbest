#include <bits/stdc++.h>
using namespace std;

constexpr int prime[] = {2,  3,  4,  5,  7,  9,  11, 13, 17, 19,
                         23, 25, 29, 31, 37, 41, 43, 47, 49};
int cnt = 0;
char res[5];

int main()
{
    for (int i : prime) {
    cout << i << endl;
    fflush(stdout);
    cin >> res;
    if (res[0] == 'y' && ++cnt == 2) 
    {
        printf("composite");
        return 0;
    }
    }
  printf("prime");
  return 0;
}