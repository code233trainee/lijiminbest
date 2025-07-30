#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    string res;
    int l = 0, r = n - 1;
    for(int i = 1; i <= n; i++)
    {
        if(i%2)
        {
            if(a[l] < a[r])
            {
                res += 'L';
                l++;
            }
            else
            {
                res += 'R';
                r--;
            }
        }
        else
        {
            if(a[l] < a[r])
            {
                res += 'R';
                r--;
            }
            else
            {
                res += 'L';
                l++;
            }
        }
    }
    cout << res << endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
