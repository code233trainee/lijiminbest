#include <bits/stdc++.h>
using namespace std;
int main()
{
    int h, w;
    scanf("%d%d",&h,&w);
    int cnt = 0;
    int num[] = {2, 0, 2, 5};
    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)
        {
            cout << num[(j + cnt) % 4];
        }
        cout << endl;
        cnt++;
    }
    return 0;
}