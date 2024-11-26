#include <iostream>
#include <vector>
using namespace std;

int countValidSubsequences(const vector<int>& records) {
    int n = records.size();
    int validSubsequences = 0;
    int balance = 0;  // 当前库存平衡
    int start = 0;    // 记录起始位置

    for (int i = 0; i < n; ++i) {
        balance += records[i];  // 更新库存平衡
        if (balance < 0) {  // 一旦平衡小于0，则不可能有合法的序列
            return validSubsequences;
            // balance = 0;
            // start = i + 1;  // 更新起始位置
        } else if (balance == 0) {  // 库存为0时，找到一个合法子序列
            validSubsequences++;
        }
    }
    return validSubsequences;
}

int main()
{
  int n;
  cin >> n;
  vector<int> num(n);
  for(int i = 0; i < n; i++)
  {
    cin>>num[i];
  }

  // for(int i = 0; i < num.size(); i++)
  // {
  //   cout<<num[i] << " " ;
  // }

  int count = 0;
  for(int i = 0; i < n; i++)
  {
    count += countValidSubsequences(num);
    num.erase(num.begin());
  }

  cout << count;
  return 0;
}