
#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// ���������
void buildHeap(int arr[], int n, int i) {
    int largest = i; // ���Ԫ�ص�����
    int left = 2*i + 1; // ���ӽڵ�����
    int right = 2*i + 2; // ���ӽڵ�����
    
    if (left < n && arr[left] > arr[largest])
        largest = left;
    
    if (right < n && arr[right] > arr[largest])
        largest = right;
        
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        buildHeap(arr, n, largest);
    }
}

// �������㷨
void heapSort(int arr[], int n) {
    // ���������
    for (int i = n/2 - 1; i >= 0; i--)
        buildHeap(arr, n, i);
        
    // ��������ֵ�Ƶ�����ĩβ
    for (int i = n-1; i > 0; i--) {
        swap(&arr[0], &arr[i]); // �����ֵ�Ƶ�ĩβ
        buildHeap(arr, i, 0); // ���¹�����
    }
}

int main() {
    int arr[] = {6, 12, 458, 5, 4, 28, 19, 1230, 9, 47};
    int n = sizeof(arr)/sizeof(arr[0]);

    heapSort(arr, n);

    printf("���������飺");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
        
    return 0;
}

