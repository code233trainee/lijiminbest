#include <bits/stdc++.h>
int main()
{
    std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    //加上以上解绑后就过了
    int n;
    std::cin >> n;
    double mx = -1;
    double mn = 101;
    double total = 0;
    for(int i = 0; i < n; i++)
    {
        double a;
        std::cin >> a;
        if(i == 0)
        {
            mx = a;
            mn = a;
            total += a;
            continue;
        }
        if(a > mx)
        {
            mx = a;
        }
        else if(a < mn)
        {
            mn = a;
        }
        total += a;
        if(i >= 2)
        {
            std::cout << std::fixed << std::setprecision(2) << (total - mx - mn) / (i - 1) << "\n";
        }
    }

    return 0;
}