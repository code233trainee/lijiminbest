#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n = 0;
    cin >> n;
    int num = 0;
    
    for(int i = 0; i < n; i++)
    {
        cin >> num;
        int ans = 0;
        while(num)
        {
            ans += num % 10;
            num /= 10;    
        }
        cout << ans << endl;
    }
}