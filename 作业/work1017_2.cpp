#include <stdio.h>

void selectionSort(int arr[], int n) {
    int i, j, min_idx;

    // 一轮一轮的选择最小的元素放在已排序部分的最后
    for (i = 0; i < n-1; i++) {
        min_idx = i;  // 假设当前位置 i 为最小值

        // 在未排序部分寻找最小值
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        // 找到更小的元素后，交换
        if (min_idx != i) {
            int temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Original array: ");
    printArray(arr, n);

    selectionSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}
