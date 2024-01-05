
#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 建立大根堆
void buildHeap(int arr[], int n, int i) {
    int largest = i; // 最大元素的索引
    int left = 2*i + 1; // 左子节点索引
    int right = 2*i + 2; // 右子节点索引
    
    if (left < n && arr[left] > arr[largest])
        largest = left;
    
    if (right < n && arr[right] > arr[largest])
        largest = right;
        
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        buildHeap(arr, n, largest);
    }
}

// 堆排序算法
void heapSort(int arr[], int n) {
    // 构建大根堆
    for (int i = n/2 - 1; i >= 0; i--)
        buildHeap(arr, n, i);
        
    // 逐个将最大值移到数组末尾
    for (int i = n-1; i > 0; i--) {
        swap(&arr[0], &arr[i]); // 将最大值移到末尾
        buildHeap(arr, i, 0); // 重新构建堆
    }
}

int main() {
    int arr[] = {6, 12, 458, 5, 4, 28, 19, 1230, 9, 47};
    int n = sizeof(arr)/sizeof(arr[0]);

    heapSort(arr, n);

    printf("排序后的数组：");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
        
    return 0;
}

