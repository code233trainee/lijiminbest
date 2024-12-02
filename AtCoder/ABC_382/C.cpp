// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n, m;
//     cin >> n >> m;
//     vector<int> a(n+1);
//     for(int i = 1; i <= n; i++)
//     {
//         cin >> a[i];
//     }
//     map<int, int> ma;
//     vector<int> ans;
//     for(int i = 1; i <= m; i++)
//     {
//         int temp;
//         cin >> temp;
//         ma[temp] = -1;
//     }

// }
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 定义结构体来存储人的口味和索引
struct Person {
    int taste, index;
};

// 定义结构体来存储寿司的美味和索引
struct Sushi {
    int deliciousness, index;
};

int main() {
    int N, M;
    cin >> N >> M;

    vector<Person> people(N);
    vector<Sushi> sushi(M);
    vector<int> result(M, -1);  // 初始化结果数组，-1 表示无人吃该寿司

    // 读取每个人的口味等级
    for (int i = 0; i < N; i++) {
        cin >> people[i].taste;
        people[i].index = i + 1;  // 保存原始顺序（1-indexed）
    }

    // 读取每个寿司的美味程度
    for (int j = 0; j < M; j++) {
        cin >> sushi[j].deliciousness;
        sushi[j].index = j;
    }

    sort(sushi.begin(), sushi.end(), [](const Sushi &a, const Sushi &b) {
        return a.deliciousness > b.deliciousness;
    });

    int j = 0;
    for(int i = 0; i < N; i++)
    {
        for(; j < M; j++)
        {
            if(sushi[j].deliciousness >= people[i].taste)
            {
                result[sushi[j].index] = people[i].index;
            }
            else
            {
                break;
            }
        }
        if(j == M)
        {
            break;
        }
    }

    for(int i = 0; i < result.size(); i++)
    {
        cout << result[i] << endl;
    }

    return 0;
}
