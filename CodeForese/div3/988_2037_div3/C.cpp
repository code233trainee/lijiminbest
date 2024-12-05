#include <iostream>
#include <vector>
using namespace std;

void solve(int n) {
    if (n <= 4) {
        cout << -1 << endl;
        return;
    }

    vector<int> result, even, odd;
    for(int i = 1; i <= n; i++)
    {
        if(i%2)
        {
            odd.push_back(i);
        }
        else
        {
            even.push_back(i);
        }
    }
    for(auto z : even)
    {
        if(z != 4)
        {
            result.push_back(z);
        }
    }
    result.push_back(4);
    result.push_back(5);
    for(auto z : odd)
    {
        if(z != 5)
        {
            result.push_back(z);
        }
    }
    
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        solve(n);
    }
    return 0;
}

