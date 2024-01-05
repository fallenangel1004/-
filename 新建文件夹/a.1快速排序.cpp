
#include <stdio.h>

// 交换两个元素的值
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 找到基准元素的位置
int partition (int arr[], int low, int high) {
    int pivot = arr[high];    // 将最后一个元素作为基准
    int i = (low - 1);

    for (int j = low; j <= high- 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// 快速排序函数
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);    // 将数组划分并获取基准元素的位置

        quickSort(arr, low, pi - 1);   // 对左侧进行排序
        quickSort(arr, pi + 1, high);  // 对右侧进行排序
    }
}

int main() {
    int arr[] = {6, 12, 458, 5, 4, 28, 19, 1230, 9, 47};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    printf("原始序列：");
    for (int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    
    quickSort(arr, 0, n-1);
    
    printf("\n排序后序列：");
    for (int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}
