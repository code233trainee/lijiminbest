#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> vs(n);
    for(int i = 0; i < n; i++)
    {
        cin >> vs[i];
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if (vs[i][j] == '.') {
				if ((i + j) & 1) {
                    vs[i][j] = 'B';
                } else {
                    vs[i][j] = 'W';
                } 
			}
        }
    }
    for(int i = 0; i < n; i++)
    {
        cout << vs[i] << "\n";
    }
    return 0;
}