// #include <stdio.h>
// #include <stdlib.h>

// #define MAXSIZE 100

// typedef int ElemType; // 可根据需要更改元素类型

// // 顺序表结构体定义
// typedef struct {
//     ElemType data[MAXSIZE];
//     int length;
// } SeqList;

// // 初始化顺序表
// void initList(SeqList *L) {
//     L->length = 0;
// }

// // 显示顺序表中的所有元素
// void displayList(SeqList L) {
//     if (L.length == 0) {
//         printf("顺序表为空！\n");
//         return;
//     }
//     printf("顺序表元素：");
//     for (int i = 0; i < L.length; i++) {
//         printf("%d ", L.data[i]);
//     }
//     printf("\n");
// }

// // 查找指定元素，返回下标，未找到返回-1
// int searchList(SeqList L, ElemType x) {
//     for (int i = 0; i < L.length; i++) {
//         if (L.data[i] == x)
//             return i;
//     }
//     return -1;
// }

// // 在指定位置插入元素（0为起始下标），返回1成功，0失败
// int insertList(SeqList *L, int pos, ElemType x) {
//     if (L->length >= MAXSIZE) return 0; // 表满
//     if (pos < 0 || pos > L->length) return 0; // 插入位置非法

//     // 后移元素，为插入做准备
//     for (int i = L->length; i > pos; i--) {
//         L->data[i] = L->data[i - 1];
//     }
//     L->data[pos] = x;
//     L->length++;
//     return 1;
// }

// // 删除指定位置的元素，返回1成功，0失败
// int deleteList(SeqList *L, int pos) {
//     if (pos < 0 || pos >= L->length) return 0; // 删除位置非法
//     // 前移元素覆盖被删除的数据
//     for (int i = pos; i < L->length - 1; i++) {
//         L->data[i] = L->data[i + 1];
//     }
//     L->length--;
//     return 1;
// }

// // 合并两个有序顺序表（非递减），返回合并后的顺序表
// SeqList mergeLists(SeqList L1, SeqList L2) {
//     SeqList L;
//     L.length = 0;
//     int i = 0, j = 0;
//     while (i < L1.length && j < L2.length && L.length < MAXSIZE) {
//         if (L1.data[i] <= L2.data[j])
//             L.data[L.length++] = L1.data[i++];
//         else
//             L.data[L.length++] = L2.data[j++];
//     }
//     // 若L1中仍有剩余
//     while (i < L1.length && L.length < MAXSIZE) {
//         L.data[L.length++] = L1.data[i++];
//     }
//     // 若L2中仍有剩余
//     while (j < L2.length && L.length < MAXSIZE) {
//         L.data[L.length++] = L2.data[j++];
//     }
//     return L;
// }

// int main() {
//     SeqList list;
//     initList(&list);
//     int choice;
//     while (1) {
//         printf("\n---------- 顺序表操作菜单 ----------\n");
//         printf("1. 显示顺序表\n");
//         printf("2. 查找元素\n");
//         printf("3. 插入元素\n");
//         printf("4. 删除元素\n");
//         printf("5. 合并两个有序顺序表\n");
//         printf("6. 退出\n");
//         printf("请输入您的选择：");
//         scanf("%d", &choice);

//         if (choice == 1) {
//             displayList(list);
//         } else if (choice == 2) {
//             int x;
//             printf("请输入要查找的元素：");
//             scanf("%d", &x);
//             int pos = searchList(list, x);
//             if (pos == -1)
//                 printf("未找到元素 %d。\n", x);
//             else
//                 printf("元素 %d 在顺序表中的位置是：%d\n", x, pos);
//         } else if (choice == 3) {
//             int pos, x;
//             printf("请输入插入位置（0为起始下标）：");
//             scanf("%d", &pos);
//             printf("请输入要插入的元素：");
//             scanf("%d", &x);
//             if (insertList(&list, pos, x))
//                 printf("插入成功！\n");
//             else
//                 printf("插入失败，请检查位置是否合法或顺序表是否已满。\n");
//         } else if (choice == 4) {
//             int pos;
//             printf("请输入删除元素的位置（0为起始下标）：");
//             scanf("%d", &pos);
//             if (deleteList(&list, pos))
//                 printf("删除成功！\n");
//             else
//                 printf("删除失败，请检查位置是否合法。\n");
//         } else if (choice == 5) {
//             SeqList L1, L2, merged;
//             initList(&L1);
//             initList(&L2);
//             int n1, n2;
//             printf("请输入第一个有序顺序表的元素个数：");
//             scanf("%d", &n1);
//             if(n1 > MAXSIZE) n1 = MAXSIZE;
//             printf("请输入 %d 个元素（非递减顺序）：\n", n1);
//             for (int i = 0; i < n1; i++) {
//                 scanf("%d", &L1.data[i]);
//             }
//             L1.length = n1;

//             printf("请输入第二个有序顺序表的元素个数：");
//             scanf("%d", &n2);
//             if(n2 > MAXSIZE) n2 = MAXSIZE;
//             printf("请输入 %d 个元素（非递减顺序）：\n", n2);
//             for (int i = 0; i < n2; i++) {
//                 scanf("%d", &L2.data[i]);
//             }
//             L2.length = n2;

//             merged = mergeLists(L1, L2);
//             printf("合并后的顺序表为：\n");
//             displayList(merged);
//         } else if (choice == 6) {
//             printf("程序退出。\n");
//             break;
//         } else {
//             printf("输入有误，请重新选择！\n");
//         }
//     }
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int n, r, c;
    cin >> n >> r >> c;
    set<array<int, 2>> smoke;
    int x = 0, y = 0;
    smoke.insert({x, y});

    string s;
    cin >> s;
    //每次移动后不是产生新的烟雾，是已产生的烟雾会移动，
    //但是移动烟雾有点麻烦，毕竟不好维护，
    //于是我们可以改为移动篝火和人物
    //原来篝火和人的位置是不变的
    //我们现在移动篝火和人的位置(但是它们的相对位置依然是不变的)就可以了
    //判断当前的移动有没有没烟雾覆盖，我们只需要把人的位置，加上当前的位置偏移就可以了
    for(int i = 0; i < n; i++)
    {
        switch(s[i]){
            case 'N': x++; break;
            case 'W': y++; break;
            case 'S': x--; break;
            case 'E': y--; break;
        };
        smoke.insert({x, y});
        cout << (smoke.count({r + x, c + y}));
    }
    cout << "\n";
    return 0;
}