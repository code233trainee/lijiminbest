#include <iostream>
using namespace std;

int T, n, m, a[20][20];
int ans;
int u[20][20];

bool isValid(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m;
}

void dfs(int x, int y, int z) {
    if (x > n) {
        ans = max(ans, z);
        return;
    }
    int next_x = x, next_y = y + 1;
    if (next_y > m) {
        next_y = 1;
        next_x = x + 1;
    }
    
    // 检查周围8个点是否都未被选择
    bool canSelect = true;
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            if (dx == 0 && dy == 0) continue;
            int nx = x + dx, ny = y + dy;
            if (isValid(nx, ny) && u[nx][ny]) {
                canSelect = false;
                break;
            }
        }
        if (!canSelect) break;
    }
    
    if (canSelect) {
        u[x][y] = 1;
        dfs(next_x, next_y, z + a[x][y]);
        u[x][y] = 0;
    }
    dfs(next_x, next_y, z);
}

int main() {
    std::ios::sync_with_stdio(false);
    cin >> T;
    for (int sth = 1; sth <= T; ++sth) {
        ans = 0;
        cin >> n >> m;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                cin >> a[i][j];
        dfs(1, 1, 0);
        cout << ans << endl;
    }
    return 0;
}