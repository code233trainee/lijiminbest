#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    std::cin >> n;
    bool isok = false;
    std::vector<std::vector<int>> vv; 
    int cnt = 0;
    for(int i = 1; i <= 3; i++)
    {
        for(int j = 1; j <= 3; j++)
        {
            for(int k = 1; k <= 3; k++)
            {
                for(int l = 1; l <= 3; l++)
                {
                    for(int r = 1; r <= 3; r++)
                    {
                        for(int m = 1; m <= 3; m++)
                        {
                            for(int p = 1; p <= 3; p++)
                            {
                                for(int z = 1; z <= 3; z++)
                                {
                                    for(int x = 1; x <= 3; x++)
                                    {
                                        for(int c = 1; c <= 3; c++)
                                        {
                                            if((i+j+k+l+r+m+p+z+x+c) == n)
                                            {
                                                vv.push_back({i, j, k, l, r, m, p, z, x, c});
                                                cnt++;
                                                isok = true;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    if(!isok)
    {
        std::cout << 0 << "\n";
    }
    else
    {
        int s = vv.size();
        std::cout << s << "\n";
        for(int i = 0; i < s; i++)
        {
            std::cout << vv[i][0] << " " << vv[i][1] << " "<< vv[i][2] << " "<< vv[i][3] << " "<< vv[i][4] << " "<< vv[i][5] << " "<< vv[i][6] << " "<< vv[i][7] << " "<< vv[i][8] << " "<< vv[i][9] << "\n";  
        }
    }
    return 0;
}