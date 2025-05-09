#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    const int mod = 1e9+7;
public:
    vector<int> baseUnitConversions(vector<vector<int>>& conversions) {
        int n = conversions.size();
        vector<int> ans(n+1);
        ans[0] = 1;
        for(int i = 0; i < n; i++)
        {
            ans[conversions[i][1]] = ans[conversions[i][0]] * conversions[i][2] % mod;
        }
        return ans;
    }
};
int main()
{
    vector<vector<int>> a = {{0,1,2},{1,2,3}};
    Solution sol;
    vector<int> ans = sol.baseUnitConversions(a);
    for(int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}