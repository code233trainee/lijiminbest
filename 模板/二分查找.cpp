#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool check(ll mid)
{

}
bool binarySearch(const std::vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return true;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return false;
}
int main()
{
    ll l = 0, r = 1e18;
    // 更推荐的写法
    while (l < r) {
        ll mid = l + (r - l) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return 0;
}