#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    vector<int> b;
    for(int l = 0, r = 0; l < n; l = r)
    {
        while(r < n && v[l] == v[r])
        {
            r++;
        }
        for(int i = 0; i < (r - l) / 2; i++)
        {
            b.push_back(v[l]);
            //每个被添加的元素都有两个，因为已经对v排过序了，所以添加进b的元素也是从下到大的排列
        }
    }
    if(b.size() < 4)//如果不满足4个坐标的需求
    {
        cout << "NO" << endl;
        return;
    }

    //要想矩形的面积最大，左下角xy都要尽可能的小，右上角的xy要尽可能大
    int x1 = b[0];
    int y1 = b[1];
    int x2 = b[b.size() - 2];
    // int y2 = b.back();//最后一个元素
    int y2 = b[b.size() - 1];//一个效果

    std::cout << "YES\n";
    std::cout << x1 << " " << y1 << " " << x1 << " " << y2 << " " << x2 << " " << y1 << " " << x2 << " " << y2 << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}