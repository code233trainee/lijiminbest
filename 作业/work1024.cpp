#include <iostream>
#include <vector>
using namespace std;

void findMinCurrency(int amount) {
    vector<int> currency = {100, 25, 10, 5, 1};
    vector<int> count(currency.size(), 0); // 用于记录每种面值的使用次数

    // 贪心算法：尽量使用面值大的货币
    for (int i = 0; i < currency.size(); i++) {
        if (amount >= currency[i]) {
            count[i] = amount / currency[i]; // 计算可以使用多少张当前面值的货币
            amount = amount % currency[i];   // 剩余需要找的金额
        }
    }

    cout << "使用的最少货币数量为：\n";
    for (int i = 0; i < currency.size(); i++) {
        if (count[i] != 0) {
            cout << "面值 " << currency[i] << " 元: " << count[i] << " 张\n";
        }
    }
}

int main() {
    int amount = 36;
    findMinCurrency(amount);
    return 0;
}
