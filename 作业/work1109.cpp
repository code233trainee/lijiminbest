#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

void generateSchedule(vector<vector<int>>& table, int n) {
    if (n == 1) return;
    
    int half = n / 2;
    generateSchedule(table, half);
    
    for (int i = 0; i < half; ++i) {
        for (int j = 0; j < half; ++j) {
            table[i][j + half] = table[i][j] + half;
            table[i + half][j] = table[i][j] + half;
            table[i + half][j + half] = table[i][j];
        }
    }
}

int main() {
    int m;
    cout << "Enter m: ";
    cin >> m;
    int n = 1 << m;
    
    vector<vector<int>> table(n, vector<int>(n));
    
    table[0][0] = 1;
    generateSchedule(table, n);
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << setw(2) << table[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
