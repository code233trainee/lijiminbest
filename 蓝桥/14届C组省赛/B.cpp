#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

    int yyyy, MM, dd, hh, mm, ss;
    int mouth[] = {0,31,59,90,120,151,181,212,243,273,304,334,365};
    vector<int> a;
    for(int i = 1; i <= 520; i++)
    {
        scanf("%d-%d-%d %d:%d:%d",&yyyy, &MM, &dd, &hh, &mm, &ss);
        int s = (mouth[MM-1] + dd - 1)*86400 + hh * 3600 + mm * 60 + ss;
        a.push_back(s);
    }
    sort(a.begin(), a.end());
    int sum = 0;
    for(int i = 0; i < 520-1; i += 2)
    {
        sum += a[i+1]-a[i];
    }
    cout << sum;
    return 0;
}