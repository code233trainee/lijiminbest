#include <bits/stdc++.h>
using namespace std;
template <typename T> inline T read() { T x = 0, w = 0; char ch = getchar(); while (ch < '0' || ch > '9') w |= (ch == '-'), ch = getchar(); while ('0' <= ch && ch <= '9') x = x * 10 + (ch ^ '0'), ch = getchar(); return w ? -x : x; }
const int mn = 2e6+10;
int n, m, q, o[mn], bel[22], tot, L[22];
//这样表示的是a是一个数组，每个元素是vector<int>类型的
vector<int> a[mn];
bool sorted[mn];
int main()
{
    std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    n = read<int>();
    m = read<int>();
    q = read<int>();
    for(int i = 1; i <= m; i++)
    {
        bel[i] = i;
    }
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            a[i].push_back(read<int>());
        }
    }
    for(int i = 1; i <= q; i++)
    {
        int op = read<int>();
        int x = read<int>();
        int y = read<int>();
        if(op == 1)
        {
            if(!sorted[bel[x]])
            {
                sort(a[bel[x]].begin(), a[bel[x]].end());
                sorted[bel[x]] = 1;
            }
            if(!sorted[bel[y]])
            {
                sort(a[bel[y]].begin(), a[bel[y]].end());
                sorted[bel[y]] = 1;
            }
            if(L[bel[x]] < L[bel[y]])
            {
                swap(bel[x], bel[y]);
            }
            L[bel[x]]++;
            int l = n;
            int r = 1;
            while(l && a[bel[x]][l-1] > a[bel[y]][0])
            {
                l--;
            }
            while(r <= n && a[bel[y]][r-1] < a[bel[x]][n-1])
            {
                r++;
            }
            if(l == n)
            {
                continue;
            }
            r -= 2;
            tot = 0;
            for(int i = l; i < n; i++)
            {
                o[++tot] = a[bel[x]][i];
            }
            for(int i = 0; i <= r; i++)
            {
                o[++tot] = a[bel[y]][i];
            }
            sort(o+1, o+tot+1);
            for(int i = l; i < n; i++)
            {
                a[bel[x]][i] = o[i-l+1];
            }
            for(int i = 0; i <= r; i++)
            {
                a[bel[y]][i] = o[i+n-l+1];
            }
        }
        else
        {
            cout << a[bel[x]][y-1] << endl;
        }
    }

    return 0;
}