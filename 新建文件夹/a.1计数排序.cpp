
#include <stdio.h>

void countSort(int arr[], int n) {
    // 找出数组中的最大元素
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    // 创建计数数组并初始化为0
    int count[max + 1];
    for (int i = 0; i <= max; ++i) {
        count[i] = 0;
    }

    // 计算每个元素出现的次数
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // 将计数数组转换为累加和数组
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    // 创建临时数组用于存储排序结果
    int output[n];

    // 根据原始数组和计数数组，将元素放入临时数组并更新计数数组
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // 将临时数组的结果拷贝回原始数组
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {6, 12, 458, 5, 4, 28, 19, 1230, 9, 47};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("原始数组：");
    printArray(arr, n);

    countSort(arr, n);

    printf("排序后的数组：");
    printArray(arr, n);

    return 0;
}

