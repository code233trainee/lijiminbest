//串匹配的kmp算法

#include <stdio.h>
#include <string.h>

// 构造模式串的部分匹配表（即 next 数组）
void computeNextArray(char* pattern, int* next, int m) {
    int len = 0;  // 前缀长度
    next[0] = 0;  // 第一个字符的前缀长度为 0
    int i = 1;

    // 计算 next 数组
    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            next[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = next[len - 1];  // 回退到上一个最长前缀
            } else {
                next[i] = 0;
                i++;
            }
        }
    }
}

// KMP算法，用于在主串 text 中查找模式串 pattern
void KMP(char* text, char* pattern) {
    int n = strlen(text);      // 主串长度
    int m = strlen(pattern);   // 模式串长度
    int next[1000];

    // 构造模式串的 next 数组
    computeNextArray(pattern, next, m);

    int i = 0;  // text 的索引
    int j = 0;  // pattern 的索引

    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == m) {  // 完全匹配，输出匹配位置
            printf("Pattern found at index %d\n", i - j);
            j = next[j - 1];  // 继续寻找下一次匹配
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = next[j - 1];  // 利用 next 数组进行移动
            } else {
                i++;  // 如果j==0，直接将主串位置后移
            }
        }
    }
}

int main() {
    char text[] = "ababcabcabababd";    // 主串
    char pattern[] = "ababd";           // 模式串

    KMP(text, pattern);

    return 0;
}
