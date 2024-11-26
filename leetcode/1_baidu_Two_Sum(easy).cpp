#include <iostream>  
#include <vector>  
  
void findSumIndices(const std::vector<int>& s, int targetSum) {  
    bool found = false; // 标记是否找到了和为targetSum的两个数  
    for (size_t i = 0; i < s.size(); ++i) {  
        for (size_t j = i + 1; j < s.size(); ++j) {  
            if (s[i] + s[j] == targetSum) {  
                std::cout << "找到和为 " << targetSum << " 的两个数: "  
                          << s[i] << " 和 " << s[j]  
                          << "，它们的下标分别是 " << i << " 和 " << j << std::endl;  
                found = true;  
            }  
        }  
        if (found) {  
            break; // 如果已经找到了一对，就跳出外层循环  
        }  
    }  
    if (!found) {  
        std::cout << "没有找到和为 " << targetSum << " 的两个数。" << std::endl;  
    }  
}  
  
int main() {  
    std::vector<int> s = {2,11,15,7};  
    int targetSum = 9;  
    findSumIndices(s, targetSum);  
    return 0;  
}