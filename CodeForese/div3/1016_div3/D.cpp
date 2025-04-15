#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

pair<int, int> get_coordinates(ll d, int n, int x_offset = 0, int y_offset = 0, ll base = 1) {
    if (n == 1) {
        if (d == base) return {x_offset, y_offset};           // top-left
        if (d == base + 1) return {x_offset + 1, y_offset + 1}; // bottom-right
        if (d == base + 2) return {x_offset + 1, y_offset};     // bottom-left
        return {x_offset, y_offset + 1};                        // top-right
    }
    int len = 1 << (n - 1);
    ll area = 1LL * len * len;

    if (d < base + area)
        return get_coordinates(d, n - 1, x_offset, y_offset, base);                      // top-left
    if (d < base + area * 2)
        return get_coordinates(d, n - 1, x_offset + len, y_offset + len, base + area);  // bottom-right
    if (d < base + area * 3)
        return get_coordinates(d, n - 1, x_offset + len, y_offset, base + area * 2);    // bottom-left
    return get_coordinates(d, n - 1, x_offset, y_offset + len, base + area * 3);        // top-right
}

ll get_value(int x, int y, int n, int x_offset = 0, int y_offset = 0, ll base = 1) {
    if (n == 1) {
        if (x == x_offset && y == y_offset) return base;         // top-left
        if (x == x_offset + 1 && y == y_offset + 1) return base + 1; // bottom-right
        if (x == x_offset + 1 && y == y_offset) return base + 2;     // bottom-left
        return base + 3;                                            // top-right
    }
    int len = 1 << (n - 1);
    ll area = 1LL * len * len;

    if (x < x_offset + len && y < y_offset + len)
        return get_value(x, y, n - 1, x_offset, y_offset, base);                     // top-left
    if (x >= x_offset + len && y >= y_offset + len)
        return get_value(x, y, n - 1, x_offset + len, y_offset + len, base + area); // bottom-right
    if (x >= x_offset + len && y < y_offset + len)
        return get_value(x, y, n - 1, x_offset + len, y_offset, base + area * 2);   // bottom-left
    return get_value(x, y, n - 1, x_offset, y_offset + len, base + area * 3);       // top-right
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        while (q--) {
            string type;
            cin >> type;
            if (type == "->") {
                int x, y;
                cin >> x >> y;
                cout << get_value(x - 1, y - 1, n) << '\n';
            } else if (type == "<-") {
                ll d;
                cin >> d;
                auto [x, y] = get_coordinates(d, n);
                cout << x + 1 << ' ' << y + 1 << '\n';
            }
        }
    }
    return 0;
}
